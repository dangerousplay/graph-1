cmake_minimum_required(VERSION 3.17)
project(graph_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph_1 src/main.cpp src/graph.h src/list.h src/list.cpp src/graph.cpp)

find_package(Catch2 REQUIRED)

add_executable(exercise_test tests/test_main.cpp src/graph.h src/list.h src/list.cpp src/graph.cpp tests/test_graph.h)
target_link_libraries(exercise_test Catch2::Catch2)

include(CTest)
include(ParseAndAddCatchTests)