#include <xc.h>
#include "main.h"

extern short second;
void __interrupt() isr(void)
{
	static unsigned short count;
	if (TMR0IF)
	{
		TMR0 = TMR0 + 8;

		if (count++ == 20000)
		{
			count = 0;
            second--;
		}
		TMR0IF = 0;
	}
}