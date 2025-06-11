cmake_minimum_required(VERSION 3.10)
project(lvgl-demo)

# --- Output Directory Configuration ---
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin) # For older CMake compatibility

# --- Other Tools Configuration  ---
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)             # Enable compile command to ease indexing with e.g. clangd
add_compile_options(-fdiagnostics-color=always)     # Ninja 

# --- Toolchain Configuration ---
include(${CMAKE_SOURCE_DIR}/toolchain-x86-gnu.cmake)

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

# --- Include Directories ---
add_subdirectory(lvgl_port)  # Include the LVGL port directory

# --- Define the project executable ---
add_executable(${PROJECT_NAME}
    main.cpp
    config/config.cpp
    user/ui.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}"    
    "${CMAKE_SOURCE_DIR}/user"
    "${CMAKE_SOURCE_DIR}/config"
    "${CMAKE_SOURCE_DIR}/lvgl_port/"
    "${CMAKE_SOURCE_DIR}/lvgl_port/lvgl"  # Include LVGL core
    "${CMAKE_SOURCE_DIR}/lvgl_port/lv_drivers"  # Include LVGL drivers
)

# Link against the libraries built in other directories
target_link_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_BINARY_DIR}/lib"  # Ensure the libraries are found in the build directory
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    lvgl  # Link against the lvgl library
    ${LIBS_TO_LINK}
    pthread
    m
    
)



