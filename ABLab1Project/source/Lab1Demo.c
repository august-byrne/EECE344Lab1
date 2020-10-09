/*******************************************************************************
* EECE344 Lab 1 Demo Code
*	Displays 'Hello[n]' on the terminal, where n starts at zero and increments
*   each time through the loop. The user selects 'Enter' to go through the loop
*   again, and 'q' to quit.
*
* Todd Morton, 09/21/2020
*******************************************************************************/
#include "MCUType.h"               /* Include header files                    */
#include "BasicIO.h"
#include "K65TWR_ClkCfg.h"

void main(void){

    INT8U cur_count = 0;            /* Current count value                    */
    INT8C char_in;                  /* Received character                     */

    K65TWR_BootClock();             /* Initialize MCU clocks                  */
    BIOOpen(BIO_BIT_RATE_115200);   /* Initialize Serial Port                 */
    BIOPutStrg("Program is running from start\n\r");	//Program running notification
    char_in = BIOGetChar();         /* Wait for character to be entered       */
    while(1){
    	if(char_in != 'q'){          /* Display message if 'q' is not entered   */
			BIOPutStrg("Hello[");
			BIOOutDecWord(cur_count,3,BIO_OD_MODE_LZ);
			BIOPutStrg("]\n\r");
			cur_count++;                /* Increment counter                      */
		}else{					//restarts the counter and gives a message when 'q' is entered
			cur_count = 0;
			BIOPutStrg("Program is running from restart\n\r");
		}
        char_in = BIOGetChar();     /* Wait for new character                 */
    }
}
