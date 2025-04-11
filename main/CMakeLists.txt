# Add sources from ui directory
file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c")

idf_component_register(
                         SRCS "main.c" 
                              "LCD_Driver/Vernon_ST7789T/Vernon_ST7789T.c" 
                              "LCD_Driver/ST7789.c"
                              "LVGL_Driver/LVGL_Driver.c"
                              "LVGL_UI/LVGL_Example.c"
                              "SD_Card/SD_SPI.c"
                              "RGB/RGB.c"
                              "Wireless/Wireless.c"
                              ${SRC_UI}

                         INCLUDE_DIRS 
                              "./LCD_Driver/Vernon_ST7789T" 
                              "./LCD_Driver" 
                              "./LVGL_Driver" 
                              "./LVGL_UI" 
                              "./SD_Card"
                              "./RGB" 
                              "./Wireless"
                              "."
                              "ui"
                       )
