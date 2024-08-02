#ifndef MAIN
#define MAIN

#define DASHBOARD               0
#define PASSWORD                1
#define MENU                    2
#define MENU_ENTER              3
#define VIEWLOG                 0
#define CLEARLOG                1
#define DOWNLOADLOG             2
#define SETTIME                 3
#define CHANGEPASS              4


#include "clcd.h"

#include "adc.h"
#include "clcd.h"
#include "eeprom.h"
#include "matrix_keypad.h"
#include "timer0.h"
#include "external_eeprom.h"
#include "ds1307.h"
#include "i2c.h"
#include "uart_1.h"

short count = 0,flag_1=1;
char main_f=0,menu_f = 0;
char org[5];
unsigned char address = 0x00;

void dashboard(char *time,char *gear,int speed);
void store_event(char *time, char *gear, int speed);               

void password(char key);
void menu(char key);
void view_log(char key);
void download_log(char key);
void clear_log(char key);
void settime(char key);
void change_pass(char key);

#endif