#pragma once

#include "fl/compiler_control.h"
#include "platforms/is_platform.h"

#ifdef FL_IS_ESP32

#include "esp_rom_sys.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace fl {
namespace platforms {

void delayMicroseconds(unsigned long us) { esp_rom_delay_us(us); }

void delay(unsigned long ms) { vTaskDelay(pdMS_TO_TICKS(ms)); }

unsigned long millis() {
    return static_cast<unsigned long>(esp_timer_get_time() / 1000);
}

unsigned long micros() {
    return static_cast<unsigned long>(esp_timer_get_time());
}

} // namespace platforms
} // namespace fl

#endif // FL_IS_ESP32
