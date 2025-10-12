# Growtopia Proxy

Just another fork of [GTProxy](https://github.com/ZTzTopia/GTProxy) to better fit my use cases.
Growtopia Proxy is a free and open-source proxy for [Growtopia](https://growtopiagame.com/), which enables the user to debug incoming and outgoing packets and even modify them. It is a useful tool for developers who want to analyze the game's network traffic and develop custom features.

## Supported Platforms

- [Windows](https://www.microsoft.com/en-us/windows). Tested with Windows 7, 8, 10 and 11.
- [GNU/Linux](https://www.gnu.org/gnu/linux-and-gnu.en.html). Tested with Ubuntu and Arch Linux. (but who use GNU/Linux to play growtopia?)

## Features

- Open source and free to use.
- Support for Growtopia 3.92 and newer versions.
- Includes a built-in http server with metadata from the Growtopia client.
- Works well with sub-server redirection.
- Supports packet debugging and modification.
- Includes a configuration file for customization.

## Build

The following dependencies are required to build from source:

- [CMake](https://cmake.org/).

To build from source:

1. Clone the source code of this project: `git clone --recurse-submodules https://github.com/Badewen/GTProxyy.git`
```shell
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
$ cmake --build .
```

## Credits

- [cpp-httplib](https://github.com/yhirose/cpp-httplib): A C++ header-only HTTP/HTTPS server and client library
- [ENet](https://github.com/lsalzman/enet): ENet reliable UDP networking library
- [eventpp](https://github.com/wqking/eventpp): Event Dispatcher and callback list for C++
- [fmt](https://github.com/fmtlib/fmt): A modern formatting library
- [glm](https://github.com/g-truc/glm): OpenGL Mathematics (GLM)
- [LibreSSL](https://www.libressl.org/) is a version of the TLS/crypto stack forked from OpenSSL in 2014, with goals of modernizing the codebase, improving security, and applying best practice development processes
- [magic_enum](https://github.com/Neargye/magic_enum): Static reflection for enums (to string, from string, iteration)
- [nlohmann_json](https://github.com/nlohmann/json): JSON for Modern C++
- [pcg-cpp](https://github.com/imneme/pcg-cpp): Random number generator
- [randutils.hpp](https://gist.github.com/imneme/540829265469e673d045): Random utilities
- [spdlog](https://github.com/gabime/spdlog): Fast C++ logging library

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/ZTzTopia/GTProxy/blob/main/LICENSE) file for details.
