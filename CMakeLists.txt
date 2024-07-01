# CMakeList.txt: EventBus 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("EventBus")

# 设置头文件目录.
set(PATH_INCLUDE "${PROJECT_SOURCE_DIR}/include")
# 设置源文件目录.
set(PATH_SRC "${PROJECT_SOURCE_DIR}/src")
# 设置库文件目录.
set(PATH_LIB "${PROJECT_SOURCE_DIR}/lib")

# 扫描源文件列表.
file(GLOB_RECURSE SOURCE_FILES "${PATH_SRC}/*.cpp")

add_library("eventBus" ${SOURCE_FILES})
# 包含头文件.
target_include_directories("eventBus" PRIVATE ${PATH_INCLUDE})

add_subdirectory("tests")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET "eventBus" PROPERTY CXX_STANDARD 17)
endif()

# TODO: 如有需要，请添加测试并安装目标。
