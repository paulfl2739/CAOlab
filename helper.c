/** Chapter 11.3.2 Helper functions*/

#include <stdint.h>
#include "LPC13xx.h"
#include "leddriver.h"


static void init(void);

static void led_off(void){
    *(volatile uint32_t *)0x50033FFC |= 1;
    }
static void led_on(void){
    *(volatile uint32_t *)0x50033FFC &= -2;
    }