cmake_minimum_required(VERSION 3.5)

project(IntelligileOpenGL LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

#add_subdirectory(/home/yaman/Git/glfw /home/yaman/Git/glfw/src)
add_subdirectory(Libraries/glad)
add_subdirectory(Libraries/glfw)

#find_package(OpenGL REQUIRED)

set(SOURCE_FILES main.cpp)

add_executable(IntelligileOpenGL ${SOURCE_FILES})
target_link_libraries(IntelligileOpenGL glfw)
target_link_libraries(IntelligileOpenGL glad)
#target_link_libraries(IntelligileOpenGL OpenGL::GL)
