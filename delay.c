#include <stdint.h>
#include "LPC13xx.h"

#define CLK_FREQ	72000000	// Default to 72MHz, use init-function if other frequency is used

static uint32_t ticks_in_ms = CLK_FREQ/1000; 
static uint32_t ticks_in_us = CLK_FREQ/1000000;

void init_delay (void)
{
	SystemCoreClockUpdate ();

	ticks_in_ms = (SystemCoreClock/1000);
	ticks_in_us = (SystemCoreClock/1000000);
}


void delay_us (uint32_t us) __attribute__ ((optimize("O2"), noclone));
void delay_ms (uint32_t ms) __attribute__ ((optimize("Os"), noclone));

void delay_ms (uint32_t ms)
{
//	while (ms--)
//	{
//		delay_us (1000);
//	}

//	The code below will generate identical assembly
//	for GCC7 and GCC8

	if (ms != 0)
	{
		do
		{
			delay_us (1000);
		}
		while (--ms);
	}
}



void delay_us (uint32_t us)
{
	uint32_t local_ticks_in_us = ticks_in_us/8;
	while (us--)
	{
		uint32_t i = local_ticks_in_us;
		do { __NOP (); __NOP (); } while (--i);
	}
}
