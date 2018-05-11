// FreeRTOS includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "mcp23017.h"

// I2C driver
#include "driver/i2c.h"

// Error library
#include "esp_err.h"

#include "nvs_flash.h"
#include "esp_log.h"
#include "esp_system.h"
#include <stdio.h>

#define I2C_SDA	23	//	GPIO_NUM_23
#define I2C_SCL   22	//	GPIO_NUM_22


mcp23017_t mcp;

static const char* MAINTAG = "MAIN MCO23017 APP";

void blink(void *pvParameter) {
   // alternate every other output pin in group A
    while(1) {
        mcp23017_write_register(&mcp, MCP23017_GPIO, GPIOA, 0xAA);
        vTaskDelay(500 / portTICK_RATE_MS);

        mcp23017_write_register(&mcp, MCP23017_GPIO, GPIOA, 0x55);
        vTaskDelay(500 / portTICK_RATE_MS);
    }
}

// Initialize nonvolatile storage
esp_err_t nvs_init(void) {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
	return ret;
}

void app_main(void)
{
   // ESP_ERROR_CHECK(nvs_init());

    mcp.i2c_addr = MCP23017_DEFAULT_ADDR;
    mcp.port = I2C_NUM_1;
    mcp.sda_pin = I2C_SDA;
    mcp.scl_pin = I2C_SCL;

    mcp.sda_pullup_en = GPIO_PULLUP_ENABLE;
    mcp.scl_pullup_en = GPIO_PULLUP_ENABLE;

    esp_err_t ret = mcp23017_init(&mcp);
    ESP_ERROR_CHECK(ret);

    xTaskCreate(&blink,"blink",2048,NULL,5,NULL);
}