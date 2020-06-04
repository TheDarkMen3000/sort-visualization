cmake_minimum_required(VERSION 3.6)

project(sorting)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(COPY lua DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(lib/glew)
add_subdirectory(lib/glfw)

add_subdirectory(lib/lua)
add_subdirectory(lib/sol2)

include_directories(lib/lua/src ${CMAKE_BINARY_DIR}/lib/lua)

add_subdirectory(src)