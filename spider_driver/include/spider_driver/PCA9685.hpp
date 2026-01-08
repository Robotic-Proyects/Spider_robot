#ifndef PCA9685_HPP_
#define PCA9685_HPP_

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstdint>
#include <cstdio>

class PCA9685
{
public:
    PCA9685(uint8_t address = 0x40, const char* i2c_dev = "/dev/i2c-1")
    : address_(address), i2c_dev_(i2c_dev), fd_(-1) {}

    bool begin()
    {
        fd_ = open(i2c_dev_, O_RDWR);
        if(fd_ < 0) return false;
        if(ioctl(fd_, I2C_SLAVE, address_) < 0) return false;

        write8(0x00, 0x00); // modo inicial
        return true;
    }

    void setPWMFreq(float freq)
    {
        float prescaleval = 25000000.0; // 25MHz
        prescaleval /= 4096.0;
        prescaleval /= freq;
        prescaleval -= 1.0;
        uint8_t prescale = static_cast<uint8_t>(prescaleval + 0.5);

        uint8_t oldmode = read8(0x00);
        uint8_t newmode = (oldmode & 0x7F) | 0x10; // sleep
        write8(0x00, newmode);
        write8(0xFE, prescale); // prescale register
        write8(0x00, oldmode);
        usleep(5000);
        write8(0x00, oldmode | 0xA1); // restart
    }

    void setPWM(uint8_t channel, uint16_t pwm)
    {
        if(channel > 15) return;
        uint16_t on = 0;
        uint16_t off = pwm;
        write8(0x06 + 4 * channel, on & 0xFF);
        write8(0x07 + 4 * channel, on >> 8);
        write8(0x08 + 4 * channel, off & 0xFF);
        write8(0x09 + 4 * channel, off >> 8);
    }

private:
    uint8_t address_;
    const char* i2c_dev_;
    int fd_;

    void write8(uint8_t reg, uint8_t value)
    {
        uint8_t buf[2] = {reg, value};
        write(fd_, buf, 2);
    }

    uint8_t read8(uint8_t reg)
    {
        write(fd_, &reg, 1);
        uint8_t val;
        read(fd_, &val, 1);
        return val;
    }
};

#endif