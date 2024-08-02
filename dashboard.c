
/*
 * File:   
 * Author: YASHWANTH J
 *
 * Created on 1 December, 2023, 10:40 AM
 */

#include <xc.h>
#include "main.h"


void dashboard(char *time,char *gear,int speed)
{
    clcd_print(time,LINE2(0));
    clcd_print(gear,LINE2(9));
    clcd_putch((speed/10) + '0',LINE2(13));
    clcd_putch((speed%10) + '0',LINE2(14));
}
