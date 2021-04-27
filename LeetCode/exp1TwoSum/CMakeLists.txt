# CMake 最低版本号要求
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# 项目信息
PROJECT(twoSum)

# ADD_SUBDIRECTORY(src bin)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

# 添加头文件路径
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/components/pre_config")

# 添加 components/pre_config 子目录
ADD_SUBDIRECTORY(components/pre_config)

# 添加链接库
TARGET_LINK_LIBRARIES(twoSum PreConfigLib)


MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})