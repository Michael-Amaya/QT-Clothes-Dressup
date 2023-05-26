cmake_minimum_required(VERSION 3.21.1)

project(test_WASM VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/Users/michaelamaya/Qt/6.5.1/macos")

include_directories(include)
add_subdirectory(src)