cmake_minimum_required(VERSION 2.8)
project(helloworld)
 
# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Add header file include directories
include_directories(./ ./hello ./world)

# Add block directories
add_subdirectory(hello)
add_subdirectory(world)

# Target
add_executable(helloworld ${DIRSRCS})
target_link_libraries(helloworld hello world)