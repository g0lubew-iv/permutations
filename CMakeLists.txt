cmake_minimum_required(VERSION 3.14)

project(
        permutations
        VERSION 1.0.0
        DESCRIPTION "Library for implementation of math permutations"
        LANGUAGES CXX
)

include(GNUInstallDirs)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)

find_package(doctest REQUIRED)

add_library(permutations INTERFACE)

target_include_directories(
        permutations INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(permutations INTERFACE cxx_std_20)

set_target_properties(
        permutations PROPERTIES
        PUBLIC_HEADER "${PERMUTATIONS_HEADERS}"
)

add_subdirectory(tests)

#install(
#        TARGETS permutations
#        DESTINATION ${CMAKE_INSTALL_PREFIX}
#        PUBLIC_HEADER DESTINATION include/
#)
#
#if (win32)
#    install(
#            TARGETS permutations
#            RUNTIME_DEPENDENCIES
#            PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
#            POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
#            DESTINATION ${CMAKE_INSTALL_PREFIX}
#    )
#endif ()