#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H

/* F_CPU = 8MHz, Prescaler = 64 */

/* 1ms Normal Mode preload: 65536 - 125 */
#define TIMER1_NORMAL_PRELOAD_VALUE    65411U

/* 1ms CTC compare value: 125 - 1 */
#define TIMER1_CTC_COMPARE_VALUE       124U

#define TIMER1_INITIAL_TCNT1_VALUE     0x0000U
#define TIMER1_INITIAL_OCR1A_VALUE     0x0000U
#define TIMER1_INITIAL_OCR1B_VALUE     0x0000U

#endif
