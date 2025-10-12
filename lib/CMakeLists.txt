project(GTProxy-Library)

add_subdirectory(cpp-httplib)
add_subdirectory(enet)
add_subdirectory(eventpp)
add_subdirectory(fmt)
add_subdirectory(glm)
add_subdirectory(magic_enum)
add_subdirectory(nlohmann_json)
add_subdirectory(spdlog)

option(LIBRESSL_SKIP_INSTALL "Skip installation" OFF)
option(LIBRESSL_APPS "Build apps" OFF)
option(LIBRESSL_TESTS "Build tests" ON)
add_subdirectory(libressl)

