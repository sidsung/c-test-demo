cmake_minimum_required (VERSION 2.6)

project(hello_cmake)

#//头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

#添加静态库目录
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/static)

#//生成可执行文件
add_executable(hello_cmake main.c)

#//链接库到可执行文件
target_link_libraries(hello_cmake libhello_static.a)