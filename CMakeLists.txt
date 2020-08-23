cmake_minimum_required(VERSION 3.17)
project(houston VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_SOURCE_DIR}/cmake/DownloadSerial.cmake)

add_executable(houston main.cpp
        c11_binary_latch.cpp c11_binary_latch.h
        mutex_fifo_queue.h
        serial_io.cpp serial_io.h body_model.cpp body_model.h)
target_link_libraries(houston
        PRIVATE serial
        PRIVATE pthread)
