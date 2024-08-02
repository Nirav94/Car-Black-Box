/*
 * File:   
 * Author: YASHWANTH J
 *
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include "main.h"
#include<string.h>

short second=120;
void password(char key)
{
    //password logic
    static short attempt=3,once=1,index=0;
    static char duplicate[5];
    if(attempt)
    {
        if(index == 4)
        {
            duplicate[4] = '\0';
            unsigned char adrs = 0xc8;
            for(int i=0;i<4;i++)
            {
                org[i] = read_external_eeprom(adrs++);
            }
            org[4] = '\0';
            if(strcmp(org,duplicate) != 0)
            {
                for(unsigned long int i=200000;i--;);
                clcd_print("Wrong Password",LINE1(0));
                clcd_print("Attempt Left ",LINE2(0));
                clcd_putch('0'+(attempt-1),LINE2(15));
                for(unsigned long int i=200000;i--;);
                index = 0;
                attempt -= 1;
                CLEAR_DISP_SCREEN;
            }
            else{
                main_f = 2;
                CLEAR_DISP_SCREEN;
                index = 0;
                return;
            }
        }
        else if(index < 4)
        {
            if(key == MK_SW11)
            {
                dup[index++] = '1';
                clcd_putch('*',LINE2(index+5));
            }
            else if(key == MK_SW12)
            {
                dup[index++] = '0';
                clcd_putch('*',LINE2(index+5));
            }
            else
            {
                clcd_print(" Enter password ",LINE1(0));
                clcd_putch('_',LINE2(index+6));
            }
        }
    }
    else if(!attempt)
    {   
        TMR0ON =1;
        clcd_print("USER BLOCKED    ",LINE1(0));
        clcd_print("WAIT ->          ",LINE2(0));
        clcd_putch('0'+((second/10)%10),LINE2(9));
        clcd_putch('0'+(second%10),LINE2(10));
        clcd_putch('0'+(second/100),LINE2(8));
        if(!second)
        {
            attempt = 3;
            second = 120;
            CLEAR_DISP_SCREEN;
        }
    }
    if(once){
        CLEAR_DISP_SCREEN;
        once=0;
        index = 0;
    }
}