/*
 * File:   
 * Author: <YASHWANTH J>
 *
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include "main.h"


void menu(char key)
{
    //logic for menu
    char *menu[5] = {"VIEW LOG      ","CLEAR LOG   ","DOWNLOAD LOG   ","SET PASSWORD    ","CHANGE PWD "};
    static short i = 0,k=0,flag = 0;
    
    if(key == MK_SW12 && k <= 3)
    {
        if(flag)
            i++;
        flag = 1;k++;
        CLEAR_DISP_SCREEN;
    }
    if(key == MK_LONG_SW11)
    {
        main_f = 3;
        menu_f = k;
        CLEAR_DISP_SCREEN;
        for(unsigned long int l = 400000;l--;);
        return;
    }
    
    if(key == MK_SW11 && k > 0)
    {
        if(!flag)
            i--;
        flag = 0;k--;
        CLEAR_DISP_SCREEN;
    }
    
    if(!flag)                       //printing arrow based on flag
        clcd_print("->",LINE1(0));
    else
        clcd_print("->",LINE2(0));
    
    if(i <= 3){
        clcd_print(menu[i],LINE1(4));
        clcd_print(menu[i+1],LINE2(4));}
    else{
        clcd_print(menu[i-1],LINE1(4));
        clcd_print(menu[i],LINE2(4));
    }
}