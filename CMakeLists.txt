cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(webFramework VERSION 1.0)

add_subdirectory(src)

add_executable(webFramework src/main.cpp)
target_link_libraries(webFramework PUBLIC servers)
target_link_libraries(webFramework PUBLIC sockets)
target_link_libraries(webFramework PUBLIC apis)

