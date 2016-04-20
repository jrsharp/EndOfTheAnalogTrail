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

static int stars[] = { 0, 1, 2, 3, 7, 8, 18, 19, 20, 21, 22, 23, 24, 25, 26, 37, 38, 39, 40, 41,
    46, 51, 56, 57, 58, 59, 60, 61, 62, 63, 69, 73, 74, 75, // end of panel 1
    76, 77, 86, 87, 88, 89, 90, 98, 99, 100, 104, 105, 106, 107, 119, 120, 121, 122, 123, 124, 
    133, 134, 135, 136, // end of panel 2
    137, 138, 139, 140, 141, 142, 143, 151, 152, 153, 154, 162, 163, 164, 165, 166, 170, 171, 
    172, 173, 174, 175, 176, 177, 183, 184, 187, 188, 193, 194, 195, // end of panel 3
    196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212,
    213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229 // end of panel 4
    };

static int lightning[] = { 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 27, 28, 29, 30, 31, 32, 
    33, 34, 35, 36, 42, 43, 44, 45, 47, 48, 49, 50, 52, 53, 54, 55, 64, 65, 66, 67, 68, 70, 71, 
    72, // end of panel 1
    78, 79, 80, 81, 82, 83, 84, 85, 91, 92, 93, 94, 95, 96, 97, 101, 102, 103, 108, 109, 
    110, 111, 112, 113, 114, 115, 116, 117, 118, 125, 126, 127, 128, 129, 130, 131, 132, // end of panel 2
    144, 145, 146, 147, 148, 149, 150, 151, 155, 156, 157, 158, 159, 160, 161, 167, 168,
    169, 178, 179, 180, 181, 182, 185, 186, 189, 190, 191, 192 // end of panel 3
    };

static int campfire[] = { 230, 231, 232 };
static int phone[] = { 233 };

static int starsLen = sizeof(stars)/sizeof(int);
static int lightningLen = sizeof(lightning)/sizeof(int);

void flashLightning();

int main() {
    // Initialize StripLights
    StripLights_Start();
	
	// Set dim level 0 = full power, 4 = lowest power
    StripLights_Dim(4); 
	
	// Clear all memory to black
	StripLights_MemClear(StripLights_BLACK);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    int foo = rand();
    int i;

    // Wait for last update to finish
	while( StripLights_Ready() == 0); 
        
    for (i = 0; i < starsLen; i++) {
        StripLights_Pixel(stars[i], 0, StripLights_RED );
    }

    for (i = 0; i < 3; i++) {
        StripLights_Pixel(campfire[i], 0, StripLights_GREEN);
    }
    
    StripLights_Pixel(phone[0], 0, StripLights_YELLOW);
    
    for(;;)
    {
        // Wait for last update to finish
	    while( StripLights_Ready() == 0); 
        /* Place your application code here. */
        StripLights_Trigger(1);
        CyDelay(1000);
        flashLightning();
        CyDelay(2000);
    }
}

void flashLightning() {
    int i;
    for (i = 0; i < lightningLen; i++) {
        StripLights_Pixel(lightning[i], 0, 0x00222222);
    }
    while( StripLights_Ready() == 0);
    StripLights_Trigger(1);
    while( StripLights_Ready() == 0);
    CyDelay(250);
    for (i = 0; i < lightningLen; i++) {
        StripLights_Pixel(lightning[i], 0, 0x00000000);
    }
    while( StripLights_Ready() == 0);
    StripLights_Trigger(1);
    while( StripLights_Ready() == 0);
    CyDelay(750);
}

/* [] END OF FILE */
