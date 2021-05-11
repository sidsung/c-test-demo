# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

# 设置目标链接库文件的存放位置
SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib/pre_config")

# 生成动态库
ADD_LIBRARY(PreConfigLib SHARED ${DIR_LIB_SRCS})

# 生成静态库
ADD_LIBRARY(PreConfigLibStatic STATIC ${DIR_LIB_SRCS})
