cmake_minimum_required(VERSION 3.2.1)
project(CFPP CXX)

add_subdirectory(source)
add_library(cfpp ${sources})

set_target_properties(cfpp 
    PROPERTIES CXX_STANDARD 11
               CXX_STANDARD_REQUIRED ON
           )

target_include_directories(cfpp
    PUBLIC include
    )

find_library(coreFoundationLib CoreFoundation)
find_library(ioKitLib IOKit)
target_link_libraries(cfpp PRIVATE ${ioKitLib} ${coreFoundationLib})
