#include "inc/audiocore.h"

volatile unsigned long g_tick = 0;

//-- spark variables
volatile int s_led = 0;
volatile uint8_t s_volume = 0;
char s_filter_shape[50]="Fast Rolloff";
