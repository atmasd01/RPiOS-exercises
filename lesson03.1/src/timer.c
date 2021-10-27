#include "utils.h"
#include "printf.h"
#include "peripherals/timer.h"

//const unsigned int interval = 200000;
//unsigned int curVal = 0;

#define RESET 38461538

void timer_init ( void )
{
	put32(TIMER_CS, EN_TIMER_IRQ | EN_TIMER | RESET);
	put32(COUNT_TIMER, CORE0_TIMER_IRQ);
}
void handle_timer_irq( void ) 
{
	put32(ICR_TIMER, CLR_TIMER_IRQ);
	printf("TIMER INTERUPT RECIVED\n\r");
}
