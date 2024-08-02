/*
 * File:   
 * Author: <YASHWAANTH J>
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include "main.h"
#include "clcd.h"
#include "matrix_keypad.h"
#include "external_eeprom.h"

char event[15];
short j = 0,flag=0;
unsigned char address = 0x00;
void get_details()
{
    unsigned char temp = address;
    for(int i=0;i<14;i++)
    {
        if(i == 2 || i == 5)
            event[i] = ':';
        else if(i == 8 || i == 11)
            event[i] = ' ';
        else
            event[i] = read_external_eeprom(temp++);
    }
    event[14] = '\0';
}

void view_log(char key)
{   
    if(key == MK_LONG_SW12)
    {
        main_f = MENU;
        CLEAR_DISP_SCREEN;
        return;
    }
    if(count == 0)
    {
        clcd_print("No logs found   ",LINE1(0));
        clcd_print("                  ",LINE2(0));
    }
    else
    {
        if (flag == 0)
        {
            flag = 1;
            get_details();
        }
        if(key == MK_SW12 && j < (count-1))
        {
            flag = 0;j++;
            address = address+10;
        }
        else if(key == MK_SW11 && j > 0)
        {
            flag = 0;j--;
            address = address-10;
        }
        
        clcd_print("#  Time          ",LINE1(0));
        clcd_putch(j+48,LINE2(0));
        clcd_print(event,LINE2(2));
    }
}