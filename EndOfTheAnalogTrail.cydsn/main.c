/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdlib.h>

extern const uint32 StripLights_CLUT[ ];

static int stars[] = { 0, 1, 2, 3, 7, 8, 18, 19, 20, 21, 22, 23, 24, 25, 26, 37, 38, 39, 40, 41, 46, 51, 57, 58, 59, 60, 61, 62, 63, 64, 69, 74, 75 };
static int lightning[] = { 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 42, 43, 44, 45, 47, 48, 49, 50, 52, 53, 54, 55, 56, 65, 66, 67, 68, 70, 72, 72 };
static int campfire[] = { 236, 237, 238 };
static int phone[] = { 239 };

int main() {
    // Initialize StripLights
    StripLights_Start();
	
	// Set dim level 0 = full power, 4 = lowest power
    StripLights_Dim(3); 
	
	// Clear all memory to black
	StripLights_MemClear(StripLights_BLACK);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    int foo = rand();
    int i;
    int starsLen = sizeof(stars)/sizeof(int);
    int lightningLen = sizeof(lightning)/sizeof(int);
 
    // Wait for last update to finish
	while( StripLights_Ready() == 0); 
        
    for (i = 0; i < starsLen; i++) {
        StripLights_Pixel(stars[i], 0, StripLights_CYAN );
    }
    
    for (i = 0; i < lightningLen; i++) {
        StripLights_Pixel(lightning[i], 0, StripLights_WHITE);
    }
    
    for (i = 0; i < 3; i++) {
        StripLights_Pixel(campfire[i], 0, StripLights_RED);
    }
    
    StripLights_Pixel(phone[0], 0, StripLights_BLUE);
    
    StripLights_Trigger(1);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
