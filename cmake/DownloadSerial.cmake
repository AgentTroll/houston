cmake_minimum_required(VERSION 3.17)

include(FetchContent)

if (NOT serial)
    FetchContent_Declare(
            serial
            GIT_REPOSITORY https://github.com/wjwwood/serial.git)
    FetchContent_Populate(serial)

    file(COPY "${serial_SOURCE_DIR}/include/"
            DESTINATION "${serial_BINARY_DIR}/include")
    file(COPY "${serial_SOURCE_DIR}/build/devel/lib/libserial.so"
            DESTINATION "${serial_BINARY_DIR}/lib/")

    add_library(serial SHARED IMPORTED)
    set_property(TARGET serial
            PROPERTY IMPORTED_LOCATION "${serial_BINARY_DIR}/lib/libserial.so")
    target_include_directories(serial
            INTERFACE "${serial_BINARY_DIR}/include/")
endif ()
