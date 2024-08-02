/*
 * File:   
 * Author: Yashwanth j
 *
 * Created on 19 june, 2024, 10:40 AM
 */
#include <xc.h>
#include "main.h"

unsigned char time[9];
unsigned char clock_reg[3];

init_config()
{
    init_matrix_keypad();
    init_clcd();
    init_adc();
    init_i2c();
	init_ds1307();
    init_uart();
    GIE = 1;
    PEIE = 1;
    init_timer0();
   puts("hello\n\r");
}


static void get_time(void)
{
	clock_reg[0] = read_ds1307(HOUR_ADDR);
	clock_reg[1] = read_ds1307(MIN_ADDR);
	clock_reg[2] = read_ds1307(SEC_ADDR);

	if (clock_reg[0] & 0x40)
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
    time[2] = ':';
	time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	time[4] = '0' + (clock_reg[1] & 0x0F);
    time[5] = ':';
	time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	time[7] = '0' + (clock_reg[2] & 0x0F);
	time[8] = '\0';
}

void main(void) {
    init_config();
    short i = 0,flag_2=1;
    char key;
    char *str[8] = {"ON","GN","GR","G1","G2","G3","G4","C"};
    unsigned short adc_reg_val;
    int speed;
    unsigned char addr = 0xc8;
    write_external_eeprom(addr++,'1');
    write_external_eeprom(addr++,'1');
    write_external_eeprom(addr++,'1');
    write_external_eeprom(addr++,'1');
    while (1)
    {
        /*
         * get the time 
         * based on switch press change the event
         */
        if(key == MK_SW1)
        {
            i = 7;
            store_event(time,str[i],speed);
        }
         get_time();
          speed = (adc_reg_val-24)/10;
          
        if(flag_2){
            store_event(time,str[i],speed);
            flag_2=0;}
          
        key = read_switches(LEVEL_CHANGE);
        adc_reg_val = read_adc(CHANNEL4);
        if(key == MK_SW11 && flag_1)
        {
            main_f = 1;
            flag_1 = 0;
        }
        if(key == MK_SW2)
        {
            if(i < 6)
            {
                i++;
            store_event(time,str[i],speed);
            }
        }
        
        if(key == MK_SW3)
        {
            if(i > 1)
            {
                i--;
            store_event(time,str[i],speed);
            }
        }
      
        if(main_f == DASHBOARD)
        {
            clcd_print("TIME  GEAR SPEED",LINE1(0));
            dashboard(time,str[i],speed);
        }
        else if(main_f == PASSWORD)
        {
            password(key);
        }
        else if(main_f == MENU)
        {
            menu(key);
        }
        else if(main_f == MENU_ENTER)
        {
            
            if(menu_f == VIEWLOG)
            {
                view_log(key);
            }
            else if(menu_f == DOWNLOADLOG)
            {
               download_log(key);
            }
            else if(menu_f == CLEARLOG)
            {
                clear_log(key);
            }
            else if(menu_f == SETTIME)
            {
                settime(key);
            }
            else if(menu_f == CHANGEPASS)
            {
               change_pass(key);
            }
        }
    }
    return;
}

