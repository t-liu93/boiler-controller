#include "src/hw_control.h"
#include "src/communication.h"

void setup()
{
    wifi_initialization();
    pin_initialization();
    mqtt_initialization();
}

void loop()
{
    unsigned long cur_millisec = millis();

    if (wifi_is_connected())
        normal_led_blinking(LED_BUILTIN, cur_millisec);
    else
        one_second_led_blinking(LED_BUILTIN, cur_millisec);

    mqtt_poll();
}
