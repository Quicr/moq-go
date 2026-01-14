# SPDX-FileCopyrightText: Copyright (c) 2024 Cisco Systems
# SPDX-License-Identifier: BSD-2-Clause

cmake_minimum_required(VERSION 3.13)
project(quicr_shim VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add libquicr as subdirectory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../libquicr ${CMAKE_CURRENT_BINARY_DIR}/libquicr)

# Create the shim library
add_library(quicr_shim STATIC
    quicr_shim.cpp
)

target_include_directories(quicr_shim PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../libquicr/include
)

target_link_libraries(quicr_shim PUBLIC
    quicr
)

# Set C++ compiler flags
target_compile_options(quicr_shim PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# Install targets
install(TARGETS quicr_shim
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES quicr_shim.h
    DESTINATION include
)
