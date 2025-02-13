cmake_minimum_required(VERSION 3.10)
project(tma_library)



option(LOGGING "Enabled logging " OFF)



set(SEARCH_LIBSTDCXX_PATHS
    /lib/x86_64-linux-gnu/
    /lib64/
)

find_library(LIBSTDCXX_PATH
    NAMES libstdc++.so.6
    PATHS ${SEARCH_LIBSTDCXX_PATHS}
    NO_DEFAULT_PATH
)

if(LIBSTDCXX_PATH)
    get_filename_component(LIBSTDCXX_DIR ${LIBSTDCXX_PATH} DIRECTORY)
    message(STATUS "Found libstdc++ in: ${LIBSTDCXX_DIR}")
else()
    message(FATAL_ERROR "libstdc++ not found in provided paths.")
endif()



if(LOGGING)
message(STATUS "Logging ON ")
add_definitions(-DLOGGING)
endif()



add_library(tma SHARED src/tma.cpp)

target_include_directories(tma PUBLIC ${CMAKE_SOURCE_DIR}/src)

set_target_properties(tma PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)
set_target_properties(tma PROPERTIES BUILD_RPATH "${LIBSTDCXX_DIR}")
