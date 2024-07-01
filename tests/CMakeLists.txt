cmake_minimum_required(VERSION 3.8)

project("tests")

# 设置源文件列表.
aux_source_directory("${PROJECT_SOURCE_DIR}" SOURCE_FILES)

add_executable("main" ${SOURCE_FILES})

target_include_directories("main" PRIVATE ${PATH_INCLUDE})

target_link_libraries("main" PRIVATE "eventBus")

target_link_directories("main" PUBLIC ${PATH_LIB})