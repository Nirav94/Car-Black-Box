/*
 * File:   
 * Author: <Yashwanth J>
 *
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include <string.h>
#include "main.h"


static short flag = 0,l=0;
char new[5],sec[5];
void password_c(char string[],char key)
{
    if(key == MK_SW11)
    {
        string[l] = '1';
        clcd_putch('*',LINE2(l+4));l++;
    }
    else if(key == MK_SW12)
    {
        string[l] = '0';
        clcd_putch('*',LINE2(l+4));l++;
    }
    else
        clcd_putch('_',LINE2(l+4));
}

void delay(char *str1,char *str2)
{
    clcd_print(str1,LINE1(0));
    clcd_print(str2,LINE2(0));
    for(unsigned long int i=400000;i--;);
    CLEAR_DISP_SCREEN;
    return;
}

void get_password(char *pass)
{
    unsigned char adrs = 0xc8;
    for(int i=0;i<4;i++)
    {
        pass[i] = read_external_eeprom(adrs++);
    }
    pass[4] = '\0';
}

void change_pass(char key)
{
    //change password logic
    if(l < 4)
    {
        if(!flag)
        {
            clcd_print(" ENTER PASSWORD ",LINE1(0));
            password_c(new,key);
        }
        else if(flag == 1)
        {
            clcd_print(" NEW PASSWORD  ",LINE1(0));
            password_c(new,key);
        }
        else
        {
            clcd_print("RE-ENTER PASSWORD",LINE1(0));
            password_c(sec,key);
        }
    }
    else
    {
        new[4] = '\0';
        if(!flag)
        {
            get_password(sec);
            if(strcmp(sec,new) == 0){
                l = 0;
                flag = 1;
                CLEAR_DISP_SCREEN;
                return;
            }else{
                l = 0;flag = 0;
                delay(" WRONG  PASSWORD","ENTER CORRECT PWD");
            }
        }
        else if(flag == 1)
        {

            flag = 2;l=0;
            CLEAR_DISP_SCREEN;
            return;
        }
        else if(flag == 2)
        {
            sec[4] = '\0';
            if(strcmp(sec,new) == 0){
                unsigned char addr = 0xc8;
                
                for(short i=0;i<4;i++)          //setting new password to eeprom
                    write_external_eeprom(addr++,sec[i]);
                
                main_f=0;flag_1 = 1;
                delay("PASSWORD CHANGED     "," SUCCESSFULL     ");
                CLEAR_DISP_SCREEN;
                return;
            }
        }
    }
}