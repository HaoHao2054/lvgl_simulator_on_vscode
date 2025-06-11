# --- Librarys ---
# Sources for LVGL core, widgets, themes, and extras
file(GLOB_RECURSE LVGL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(lvgl STATIC
    ${LVGL_SOURCES}
)

target_include_directories(lvgl PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}" 

)
message(STATUS "lvgl_port/CMakeLists.txt: Defined lvgl_core library.")