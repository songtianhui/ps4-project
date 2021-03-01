cmake_minimum_required(VERSION 3.14)
project(GraphLibrary)

find_package(Git)

set(CMAKE_CXX_STANDARD 17)
include_directories("include")
file(GLOB sources "source/**/*.cpp")
add_library(GraphLibrary ${sources})

add_custom_target(GitTrace1
        COMMAND "${GIT_EXECUTABLE}" add -A . --ignore-errors
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_custom_target(GitTrace2
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify -m "> compile failed"
        --author="tracer-ps4-2021 <tracer-ps4-2021@ics.nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_dependencies(GraphLibrary GitTrace1)
add_dependencies(GraphLibrary GitTrace2)
add_custom_command(TARGET GraphLibrary POST_BUILD
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify --amend -m "> compile passed"
        --author="tracer-ps4-2021 <tracer-ps4-2021@ics.nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Your custom tests below
add_executable(Test01 tests/01-hello-world.cpp)
target_link_libraries(Test01 GraphLibrary)