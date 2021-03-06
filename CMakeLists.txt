cmake_minimum_required(VERSION 3.14)
project(GraphLibrary)

find_package(Git)

set(CMAKE_CXX_STANDARD 17)
include_directories("include")
file(GLOB sources "source/**/*.cpp")
add_library(GraphLibrary ${sources} include/DataStructures/WeightedEdge.h include/DataStructures/WeightedGraph.h source/DataStructures/WeightedEdge.cpp source/DataStructures/WeightedGraph.cpp include/DataStructures/UndirectedGraph.h source/DataStructures/UndirectedGraph.cpp include/DataStructures/UndirectedWeightedGraph.h source/DataStructures/UndirectedWeightedGraph.cpp include/DataStructures/Generic.h include/DataStructures/UndirectedGeneric.h source/Algorithms/BreadthFirstSearcher.cpp source/Algorithms/DepthFirstSearcher.cpp include/Algorithms/DijkstraShortestPaths.h include/Algorithms/BellmanFordShortestPaths.h include/Algorithms/FloydShortestPaths.h)

add_custom_target(GitTraceAdd
        COMMAND "${GIT_EXECUTABLE}" add -A . --ignore-errors
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_custom_target(GitTraceCommit
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify -m "compile"
        --author="tracer-ps4-2021 <tracer-ps4-2021@ics.nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_dependencies(GitTraceCommit GitTraceAdd) # Avoid data race
add_dependencies(GraphLibrary GitTraceCommit)
add_custom_command(TARGET GraphLibrary POST_BUILD
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify -m "compile succeed"
        --author="tracer-ps4-2021 <tracer-ps4-2021@ics.nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Your custom tests below
add_executable(Test01 tests/11-test.cpp)
target_link_libraries(Test01 GraphLibrary)
