# FastLED
# https://github.com/FastLED/FastLED
# MIT License

cmake_minimum_required(VERSION 3.5)

# FastLED uses a unity build pattern.
set(FastLED_SRCS 
    "src/_build.cpp"
    "src/fl/_build.cpp"
    "src/platforms/_build.cpp"
    "src/third_party/_build.cpp"
)

# Register the component with ESP-IDF
idf_component_register(SRCS ${FastLED_SRCS}
                       INCLUDE_DIRS "src"
                       REQUIRES esp_driver_rmt esp_lcd driver esp_mm esp_wifi esp_netif esp_timer esp_http_server esp_adc esp_event nvs_flash lwip)

# FastLED needs to know it's on ESP32 to enable the correct platform headers.
# We also use raw pin order by default for ESP-IDF.
target_compile_definitions(${COMPONENT_LIB} PUBLIC 
    ESP32
    F_CPU=400000000L
)

# FastLED has many warnings with modern GCC, disable -Werror
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-error" "-Wno-unused-variable" "-Wno-unused-function" "-Wno-ignored-qualifiers")
