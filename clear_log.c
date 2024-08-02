/*
 * File:   
 * Author: <NAME>
 *
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include "main.h"


void clear_log(char key)
{
    count = 0;
    clcd_print(" LOGS CLEARED ",LINE1(0));
    for(unsigned long int l = 500000;l--;);

            {
                main_f = 2;
                CLEAR_DISP_SCREEN;
                return;
            }
}