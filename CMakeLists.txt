cmake_minimum_required(VERSION 3.3)

project(Utils)

add_definitions(-D_VARIADIC_MAX=10)

# Bring the headers
include_directories(include)

# Gather additional source files/headers
SET(SOURCES
        memaligned.cpp
        pow2assert.cpp
        dynamic_enum/DynamicEnum.cpp
        merge_structs/Merger.cpp)
SET(HEADERS
        pow2assert.h
        memaligned.h
        dynamic_enum/DynamicEnum.h
        merge_structs/Merger.h)

# Tell cmake that this will be a library (and not a exectutable)
add_library(${PROJECT_NAME} ${SOURCES} ${EXTRA_SOURCES} ${HEADERS})

source_group(Base ./)
source_group(DynamicEnum dynamic_enum/*)
source_group(MergeStructs merge_structs/*)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})