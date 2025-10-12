#pragma once
#include "world_dumper.hpp"

#include <vector>
#include <fstream>

#include <fmt/chrono.h>

#include "../parser/parser.hpp"
#include "../../core/core.hpp"
#include "../../client/client.hpp"
#include "../../packet/game/core.hpp"
#include "../../utils/text_parse.hpp"
#include "../../core/logger.hpp"
#include "../../utils/packet_utils.hpp"
#include "../../utils/byte_stream.hpp"
#include "../../server/server.hpp"
#include "../../packet/packet_types.hpp"

namespace extension::world_dumper {
class WorldDumperExtension final : public IWorldDumperExtension {
    core::Core* core_;
    std::string world_name_;
    std::vector<std::byte> world_data_;
public:
    explicit WorldDumperExtension(core::Core* core) : core_{ core }, world_data_{}, world_name_{} {

    }

    ~WorldDumperExtension() override = default;

    void init() override {
        core_->get_event_dispatcher().prependListener(
            core::EventType::Packet,
            [this](const core::EventPacket& event) {
                if (event.from != core::EventFrom::FromServer) {
                    return;
                }
                if (event.get_packet().type == packet::PacketType::PACKET_SEND_MAP_DATA) {
                    utils::PacketUtils::send_chat_message(&event.get_target(), "Received map data.");
                    world_data_ = event.get_ext_data();
                }
            }
        );

        core_->get_event_dispatcher().prependListener(
            core::EventType::Message,
            [this](const core::EventMessage& event) {
                const auto& text_parse = event.get_message();
                if (event.from != core::EventFrom::FromClient) {
                    if (text_parse.get("eventName") == "300_WORLD_VISIT") {
                        world_name_ = text_parse.get("World_name").substr(2);
                    }
                    return;
                }

                if (text_parse.get("action") != "input") {
                    return;
                }
                else if (text_parse.get("text") != "/save") {
                    return;
                }

                utils::PacketUtils::send_chat_message(&event.get_player(), "Dumping world data");

                auto current_time = std::chrono::system_clock::now();
                std::string file_name = fmt::format("WorldData_{}_{:%Y%m%d_%H%M%S}.dat", world_name_, current_time);
                std::ofstream output_file{ 
                    file_name.c_str(),
                    std::ios::binary | std::ios::out
                };
                output_file.write((char*)world_data_.data(), world_data_.size());
                output_file.close();

                event.canceled = true;
            }
        );
    }

    void free() override
    {
        delete this;
    }
};
}
