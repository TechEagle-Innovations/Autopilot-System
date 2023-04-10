#pragma once
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <AP_HAL/AP_HAL.h>
#include <utility>
#include <AP_HAL/I2CDevice.h>

#define Cell_I2C_ADDRESS      0x50

class AP_LoadCell
{
    public:

        AP_LoadCell();
        void init(int8_t bus);
        void update();
        void read_data();
        

    private:
        AP_HAL::OwnPtr<AP_HAL::Device> dev;
        uint16_t thrust;
        // const uint8_t write_data = 2;
        uint8_t test_data[2];
        bool new_data;
        HAL_Semaphore sem;



};


// namespace AP {
//     AP_LoadCell &loadcell();
// };