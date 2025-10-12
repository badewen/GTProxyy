#pragma once
#include "world_dumper.hpp"
#include "../parser/parser.hpp"
#include "../../core/core.hpp"
#include "../../client/client.hpp"
#include "../../packet/game/core.hpp"
#include "../../utils/text_parse.hpp"
#include "../../core/logger.hpp"
#include "../../utils/packet_utils.hpp"
#include "../../utils/byte_stream.hpp"
#include "../../server/server.hpp"

namespace extension::command_handler {
class WorldDumperExtension final : public IWorldDumperExtension {
    core::Core* core_;
    ByteStream world_data_;
public:
    explicit WorldDumperExtension(core::Core* core): core_{ core }, world_data_{}{

    }

    ~WorldDumperExtension() override = default;

    void init() override {
        core_->get_event_dispatcher().prependListener(
            core::EventType::Message,
            [this](const core::EventMessage& event) {
                TextParse textParse(event.get_message().get_raw(), "|");
                event.
                std::string command = textParse.get("text");

                if (command == "/proxy") {

                }
            }
            );
    }

    void free() override
    {
        delete this;
    }
};
}
