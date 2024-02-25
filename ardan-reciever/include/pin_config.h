/**
 * @file pinConfig.h
 * @author dominic gasperini
 * @brief this file holds the pin layout for the board I/O
 * @version 2.0
 * @date 2024-02-25
 */

/*
==========================================================
                        Includes
==========================================================
*/

#include <esp_pm.h>

/*
===========================================================
                    Power Configuration
===========================================================
*/

esp_pm_config_esp32_t power_configuration{
    .max_freq_mhz = 240,
    .min_freq_mhz = 240,
    .light_sleep_enable = false,
};

/*
===========================================================
                    Pin Definitions
===========================================================
*/

// Outputs
