#include <predef.h>
#include <stdio.h>
#include <ctype.h>
#include <startnet.h>
#include <autoupdate.h>
#include <smarttrap.h>
#include <taskmon.h>
#include <NetworkDebug.h>
#include <pinconstant.h>
#include <pins.h>
#include <basictypes.h>



extern "C" {
void UserMain(void * pd);
void InitLEDS (void);
}

#define LED1 J2[15]

const char * AppName="tutorial";

void UserMain(void * pd) {
    InitializeStack();
    OSChangePrio(MAIN_PRIO);
    EnableAutoUpdate();
    StartHTTP();
    EnableTaskMonitor();

    #ifndef _DEBUG
    EnableSmartTraps();
    #endif

    #ifdef _DEBUG
    InitializeNetworkGDB_and_Wait();
    #endif

    iprintf("Application started: %s\n", AppName);

    InitLEDS();

    while (1) {
    	// Put your LED pattern code here
    	// Use the IO Pin Class methods to turn the LEDS on
    	// and off
    	// LEDs are active low
    	LED1 = 0;
        OSTimeDly(TICKS_PER_SECOND);
    }
}

// Complete this function using the IO Pin Class methods
// for each LED. LED1 is given as an example.

void InitLEDS(void) {
	LED1.function(PINJ2_15_GPIO);
}