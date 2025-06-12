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