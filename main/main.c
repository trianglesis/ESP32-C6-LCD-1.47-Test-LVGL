/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "ST7789.h"
#include "SD_SPI.h"
#include "RGB.h"
#include "Wireless.h"
#include "LVGL_Example.h"
#include "ui/ui.h"

void app_main(void)
{
    // Wireless_Init();
    // Flash_Searching();
    RGB_Init();
    // RGB_Example();
    SD_Init();                              // SD must be initialized behind the LCD
    LCD_Init();
    BK_Light(50);
    LVGL_Init();                            // returns the screen object

/********************* Demo *********************/
    // Lvgl_Example1();
    // lv_demo_widgets();
    // lv_demo_keypad_encoder();
    // lv_demo_benchmark();
    // lv_demo_stress();
    // lv_demo_music();
    int counter = 0;
    ui_init();
    while (1) {
        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        vTaskDelay(pdMS_TO_TICKS(10));
        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        lv_timer_handler();

        // Init SQ Line Studio elements
        lv_arc_set_value(ui_Arc1, counter);
        lv_label_set_text_fmt(ui_Label1, "%d", counter);
        lv_label_set_text(ui_Label2, "CO2 ppm");

        // Make up and down
        if (counter == 2500) {
            counter = 0;
        } else {
            counter++;
        }

    }
}
