/* All ARM assignments from CAO labs
 * Date: March 2024
 */

#include "leddriver.h"
#include "delay.h"
#include "helper.h"

/* LED0 connected to PlO3_0
 * LED0 lit by writing 0 to pin
 * it is 'input mode' after a reset
 * (set to 0 if reset, current should flow, 
 * this checks if board is powered)*/

int dataReg = 0x50033FFC;
int dataDir = 0x50038000;

int main(){
    return 0;
}