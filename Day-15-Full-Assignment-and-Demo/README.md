# Day 15 - Full Assignment and Demo

## Requirements

1. Toggle LED every 500 ms.
2. Toggle buzzer every 150 ms.
3. Count up on the seven-segment display every 1 second.
4. Check Button 1 every 200 ms and increase LED brightness.
5. Check Button 2 every 200 ms and decrease LED brightness.

## Implementation

- Microcontroller: ATmega32
- Clock frequency: 8 MHz
- Timer: Timer1
- Mode: Fast PWM 8-bit
- Prescaler: 64
- PWM output: PD5 / OC1A
- Buzzer: PC1
- Seven-segment: PORTA
- Brightness UP button: PB0
- Brightness DOWN button: PB1
- Timing tasks implemented using Timer1 Overflow Interrupt and software counters.

## Output Files

- Proteus simulation project
- Source code
- Team4_AllTasks.hex
- Final assignment demonstration video
