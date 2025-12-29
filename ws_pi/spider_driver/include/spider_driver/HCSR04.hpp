#pragma once

#include <chrono>
#include <thread>
#include <fstream>
#include <string>

void set_gpio_value(int pin, int value) {
    std::ofstream("/sys/class/gpio/gpio" + std::to_string(pin) + "/value") << value;
}

int get_gpio_value(int pin) {
    int value;
    std::ifstream file("/sys/class/gpio/gpio" + std::to_string(pin) + "/value");
    file >> value;
    return value;
}

class HCSR04
{
public:
    HCSR04(int trig_pin, int echo_pin)
        : trig_pin_(trig_pin), echo_pin_(echo_pin) {}

    double read()
    {
        // Enviar pulso de 10us
        set_gpio_value(trig_pin_, 0);
        std::this_thread::sleep_for(std::chrono::microseconds(2));
        set_gpio_value(trig_pin_, 1);
        std::this_thread::sleep_for(std::chrono::microseconds(10));
        set_gpio_value(trig_pin_, 0);

        std::chrono::high_resolution_clock::time_point t0, t1;

        if (!wait_for(1, std::chrono::microseconds(25000), t0))
            return -1.0;
        if (!wait_for(0, std::chrono::microseconds(25000), t1))
            return -1.0;

        double dt = std::chrono::duration<double>(t1 - t0).count();
        constexpr double SOUND_SPEED = 343.0; // m/s
        double distance_m = (dt * SOUND_SPEED) / 2.0;

        return distance_m;
    }

private:
    int trig_pin_;
    int echo_pin_;

    bool wait_for(int value,
                  std::chrono::microseconds timeout,
                  std::chrono::high_resolution_clock::time_point &t)
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (true) {
            if (get_gpio_value(echo_pin_) == value) {
                t = std::chrono::high_resolution_clock::now();
                return true;
            }
            if (std::chrono::high_resolution_clock::now() - start > timeout)
                return false;
            std::this_thread::sleep_for(std::chrono::microseconds(2));
        }
    }
};
