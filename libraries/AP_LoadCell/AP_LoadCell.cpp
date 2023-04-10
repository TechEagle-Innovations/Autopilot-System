#include "AP_LoadCell.h"

extern const AP_HAL::HAL& hal;

AP_LoadCell::AP_LoadCell()
{
    printf("Constructor init\n");
}




void AP_LoadCell::init(int8_t bus)
{
    if (bus < 0) {
        // default to i2c external bus
        bus = 1;
    }
    dev = std::move(hal.i2c_mgr->get_device(0,22));
    if (!dev) {
        return;
    }
    printf("Load Cell: State Initialized\n");

     dev->register_periodic_callback(100000, FUNCTOR_BIND_MEMBER(&AP_LoadCell::read_data, void));
}


void AP_LoadCell::update()
{
    if(new_data)
        hal.console->printf("Load Cell: %f grams\n",thrust*3.16455);


    

}

void AP_LoadCell::read_data()
{

        if(!dev->read(test_data, sizeof(test_data)))
        {
            new_data = false;
        }
        else
        {
            thrust = test_data[1] << 8 | test_data[0];
            new_data = true;

        }
}


