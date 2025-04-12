cmake_minimum_required(VERSION 3.10)
project(lvgl-demo)

# 设置编译选项
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")


# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 启用 Ninja 颜色支持
add_compile_options(-fdiagnostics-color=always)

# 警告选项（与Makefile保持一致）
set(WARNINGS
    -Wall -Wextra
    -Wshadow -Wundef -Wmaybe-uninitialized -Wmissing-prototypes -Wno-discarded-qualifiers
    -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized
    -Wno-unused-parameter -Wno-missing-field-initializers -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default
    -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated
    -Wempty-body -Wshift-negative-value -Wstack-usage=2048
    -Wtype-limits -Wsizeof-pointer-memaccess -Wpointer-arith
)
add_compile_options(${WARNINGS})

# 选择底层驱动（X11或SDL2）
option(USE_X11 "Use X11 driver" ON)
option(USE_SDL2 "Use SDL2 driver" OFF)

if(USE_SDL2)
    set(LV_DRIVER_USE "USE_SDL")
    set(LIBS_TO_LINK SDL2)
else()
    set(LV_DRIVER_USE "USE_X11")
    set(LIBS_TO_LINK X11)
endif()

# 添加自定义定义
add_definitions(-DSIMULATOR=1 -DLV_BUILD_TEST=0 -D${LV_DRIVER_USE})

# 包含目录
include_directories(
    ${PROJECT_SOURCE_DIR}/ui/simulator/inc
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/lvgl
    ${PROJECT_SOURCE_DIR}/main/src/
    
)

# 查找所有源文件
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/lv_drivers/*.c"
    "${PROJECT_SOURCE_DIR}/lvgl/*.c"
    "${PROJECT_SOURCE_DIR}/main/*.c"
)

# 排除不需要的文件（如果有）
# file(GLOB_RECURSE EXCLUDE_SOURCES
#     "${PROJECT_SOURCE_DIR}/path/to/exclude/*.c"
# )
# list(REMOVE_ITEM SOURCES ${EXCLUDE_SOURCES})

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(main ${SOURCES} ${CMAKE_AUTOGEN_FILES})  # 确保它们被正确排除


# 链接库
target_link_libraries(main
    ${LIBS_TO_LINK}
    pthread
    m
)

# 设置构建目录
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)