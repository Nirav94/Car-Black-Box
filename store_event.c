#include <xc.h>
#include "main.h"


void store_event(char *time, char *gear, int speed) {
    short k=0;
    count++;
    for (int i = 0; i < 12; i++) {
        if (i < 8) {
            if (i == 2 || i == 5)
                continue;
            else {
                write_external_eeprom(address, time[i]);
            }
        } else if (i < 10) {
            write_external_eeprom(address, gear[k++]);
        } else {
            if (i == 10)
                write_external_eeprom(address, (speed / 10)+48);
            else
                write_external_eeprom(address, (speed % 10)+48);
        }
        address++;
    }
    if(address > (10*9)){
        address = 0x00;
    }
}