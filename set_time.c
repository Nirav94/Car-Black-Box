
/*
 * File:   
 * Author: <YASHWANTH J>
 * Created on 30 june, 2024, 10:40 AM
 */

#include <xc.h>
#include "main.h"

short hour,min,second,time_flag,set_delay=0,flag_main=0;
extern unsigned char time[9];

void display_time()
{
    clcd_putch('0'+(hour/10),LINE2(4));
    clcd_putch('0'+(hour%10),LINE2(5));
    clcd_putch(':',LINE2(6));
    clcd_putch('0'+(min/10),LINE2(7));
    clcd_putch('0'+(min%10),LINE2(8));
    clcd_putch(':',LINE2(9));
    clcd_putch('0'+(second/10),LINE2(10));
    clcd_putch('0'+(second%10),LINE2(11));
}

void settime(char key)
{
    //logic for set time
    clcd_print("   Set Time      ",LINE1(0));
    if(!set_delay){
        hour = ((time[0] -'0')/10)*10 + (time[1] -'0')%10;
        min = ((time[3] -'0')/10)*10 + (time[4] -'0')%10;
        second = ((time[6] -'0')/10)*10 + (time[7] -'0')%10;
    }
    if(key == MK_SW11)
    {
        if(time_flag == 0)
        {
            if(hour > 22)
                hour = 0;
            else
                hour++;
        }
        else if(time_flag == 1)
        {
            if(min > 58)
                min = 0;
            else
                min++;
        }
        else if(time_flag == 2)
        {
            if(second > 58)
                second = 0;
            else
                second++;
        }
    }
    else if(key == MK_SW12)
    {
        if(time_flag == 2)
            time_flag = 0;
        else
            time_flag++; 
    }
    
    if(key == 21)
    {
        CLEAR_DISP_SCREEN;
        write_ds1307(HOUR_ADDR,((hour/10) << 4) | (hour%10));
        write_ds1307(MIN_ADDR,((min/10) << 4) | (min%10));
        write_ds1307(SEC_ADDR,((second/10) << 4) | (second%10));
        if(flag_main++ > 200){
            CLEAR_DISP_SCREEN;
            main_f = 0;}
        return;
    }
    else if(key == 22)
    {
        main_f = 0;
        return;
    }
    
    if(++set_delay < 200)
    {
//        display_time();
        if(time_flag == 0){
            clcd_putch(' ',LINE2(4));
            clcd_putch(' ',LINE2(5));}
        else if(time_flag == 1){
            clcd_putch(' ',LINE2(7));
            clcd_putch(' ',LINE2(8));}
        else{
            clcd_putch(' ',LINE2(10));
            clcd_putch(' ',LINE2(11));
        }
    }else 
        display_time();
    if(set_delay >400)
    {
        set_delay = 1;
    }
    
}