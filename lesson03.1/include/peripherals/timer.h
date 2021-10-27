#ifndef	_P_TIMER_H
#define	_P_TIMER_H

#include "peripherals/base.h"

#define TIMER_CS        (0x40000034)		//arm local timer address
#define ICR_TIMER       (0x40000038)		//Capture/Compare Rejister 1
#define COUNT_TIMER       (0x40000024)		//Counter


#define CLR_TIMER_IRQ	(1 << 31)	//clear interrupt
#define CORE0_TIMER_IRQ	(0)		//sets too zero
#define EN_TIMER_IRQ	(1 << 29)	//ENABLE interrupt request
#define EN_TIMER	(1 << 28)	//enable timer





#endif  /*_P_TIMER_H */
