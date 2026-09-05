#pragma once

// Minimal esp_sleep stub for the desktop simulator. Real wake-from-deep-sleep
// is emulated by SimulatorLifecycle (process relaunch); the firmware's
// main.cpp queries the wake cause to detect a timer wake from the clock sleep
// screen. In the simulator a wake is always reported as a power-button wake,
// so the timer path never fires here.

#ifdef __cplusplus
extern "C" {
#endif

typedef int esp_err_t;
#define ESP_OK 0

typedef enum {
  ESP_SLEEP_WAKEUP_UNDEFINED = 0,
  ESP_SLEEP_WAKEUP_ALL,
  ESP_SLEEP_WAKEUP_EXT0,
  ESP_SLEEP_WAKEUP_EXT1,
  ESP_SLEEP_WAKEUP_TIMER,
  ESP_SLEEP_WAKEUP_TOUCHPAD,
  ESP_SLEEP_WAKEUP_ULP,
  ESP_SLEEP_WAKEUP_GPIO,
  ESP_SLEEP_WAKEUP_UART,
  ESP_SLEEP_WAKEUP_UART1,
} esp_sleep_wakeup_cause_t;

esp_sleep_wakeup_cause_t esp_sleep_get_wakeup_cause(void);
esp_err_t esp_sleep_enable_timer_wakeup(uint64_t time_in_us);

#ifdef __cplusplus
}
#endif