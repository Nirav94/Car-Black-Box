
#include <xc.h>
#include "main.h"


short a;

void download_log(char key)
{
    char address1=0x00;
    unsigned char event[10][15];
    while(a < count)
    {
        for(int i=0;i<14;i++)
        {
            if(i == 2 || i == 5)
                event[a][i] = ':';
            else if(i == 8 || i == 11)
                event[a][i] = ' ';
            else
                event[a][i] = read_external_eeprom(address1++);
        }
        event[a++][13] = '\0';
    }
    a=0;
    while(a < count)
    {
        puts(event[a++]);
        puts("\n\r");
    }
    if(!count)
    {
        clcd_print("NO LOGS FOUND    ",LINE1(0));
        for(unsigned long int i=400000;i--;);
        main_f = MENU;
    }
    else{
        clcd_print("LOGS DOWNLOADED ",LINE1(0));
        clcd_print("Successfully    ",LINE2(0));
        for(unsigned long int i=400000;i--;);
        main_f = MENU;
    }
}

