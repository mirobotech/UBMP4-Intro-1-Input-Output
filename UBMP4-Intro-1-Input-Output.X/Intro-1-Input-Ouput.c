/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.

int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
    {
        if(SW3 == 1)
        {
            LED1 = 0;
        }
     
    

        // Add code for your Program Analysis and Programming Activities here:
        // Make a tone while SW2 is held
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

/* Program Analysis
 * 
 * 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
 *    Do the LEDs keep flashing when SW2 is held? Look at the program and
 *    explain why this happens when SW2 is held.
 * 
 * It will flash around once if pressed and released quickly.The LEDs keep 
 * flashing when SW2 is held because the if statement keeps it going if SW2 is 0.
 * 
 * 2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
 * 
 * LED3 = 0 changes state to OFF and LED3 = 1 changes state to ON
 * 
 * 3. What voltage do you expect the microcontroller to output to LED D3 when
 *    the statement LED3 = 0; runs? What voltage do you expect the output to be
 *    when the statement LED3 = 1; runs?
 * 
 * The voltage would be 0 if LED3 = 0. I would expect the voltage to be 1.8 
 * if LED3 = 1.
 * 
 *    You can confirm the output voltage with a voltmeter if you have access
 *    to one. If you tried that, did the voltage match your prediction?
 * 
 * 4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
 *    'LED3 = 1;' uses a single equal sign. What operation is performed by one
 *    equal sign? What operation is performed by two equal signs?
 * 
 *  One single equal sign is assigning a value to something. Two equal signs 
 * performs what it's equal to. 
 * 
 * 5. The following program code includes instructions that write to the PORTC
 *    output latches directly. Try it by copying and pasting this code below
 *    the existing SW2 'if' structure, at the location shown by the comment.

        if(SW3 == 0)
        {
            LATC = 0b00000000;
            __delay_ms(100);
            LATC = 0b11110000;
            __delay_ms(100);
        }

 *    What happens when pushbutton SW3 is pressed? Identify at least one
 *    advantage and one disadvantage of controlling the LEDs using 'LATC' writes
 *    rather than through individual 'LEDn = x;' statements.
 * 
 * When SW3 is pressed, the 4 LEDs light up at the same time for 1 second. One 
 * disadvantage is that the amount of time it blinks is different each time 
 * SW3 is held down.
 * 
 * 
 * 
 * 6. Next, compare the operation of 'if' and 'while' structures to simulate
 *    momentary buttons. Replace the code you added in 5, above, with this code:

        // Momentary button using if structure
        if(SW3 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

        // Momentary button using while structure
        while(SW4 == 0)
        {
            LED5 = 1;
        }
        LED5 = 0;

 *    First, try pressing and releasing SW3 and SW4 one at a time.
 * 
 *    Next, press and hold SW3 while pressing and releasing SW4. Does it work
 *    as expected?
 * 
 * Yes
 * 
 *    Next, try press and holding SW4 while pressing and releasing SW3. Does it
 *    work as expected? Explain the difference in operation between the 'if' and
 *    'while' structures making up the momentary button code.
 * 
 * No. The difference in the operation is that if SW3 is press first you can 
 * use SW4 but can't do the opposite.
 * 
 * 7. Let's explore logical conditions using 'if' statements. Replace the code
 *    added in 6, above, with this nested if code to make a logical AND
 *    condition that will light LED D4 only if both SW3 and SW4 are pressed:

        // Nested if 'AND' code
        if(SW3 == 0)
        {
            if(SW4 == 0)
            {
                LED4 = 1;
            }
            else
            {
                LED4 = 0;
            }
        }
        else
        {
            LED4 = 0;
        }

 *    Test the code to ensure it works as expected. Does the order of the if
 *    conditions matter? (eg. swap the conditional checks for SW3 and SW4)
 * 
 * The conditions don't matter as long as you press both buttons
 * 
 * 8. Next, replace the code from 7 with the following code which implements a
 *    logical AND conditional operator composed of two ampersands '&&':
 
        // Conditional 'AND' code
        if(SW3 == 0 && SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Does '&&' work the same way as the nested if structures? Can you think of
 *    at least one advantage of using a logical conditional operator instead of
 *    nested if structures?
 * 
 * It is more neat and easier to read
 * 
 * 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
 *    a logical OR conditional operator. Your code should look like this:
  
        // Conditional 'OR' code
        if(SW3 == 0 || SW4 == 0)
        {
            LED4 = 1;
        }
        else
        {
            LED4 = 0;
        }

 *    Describe the conditions under which LED4 turns on.
 * 
 * If either SW3 or SW4 is pressed LED4 turns on.
 * 
 * 
 * 
 * Programming Activities
 * 
 * 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
 *    or more of the delay values in the program to 500ms and see what happens.
 * 
 *    Can the delay be made even longer? Try 1000 ms. How big can the delay be
 *    before MPLAB-X produces an error message? (Hint: can you think of a fast
 *    and efficient way of guessing an unknown number?)
 * 
 * 4205 ms
 * 
 * 
 *  2. The '__delay_ms();' function only accepts integers as delay values. To
 *    make delays shorter than 1ms, specify a delay in microseconds using the
 *    '__delay_us();' function. You won't be able to see such short LED flashes
 *    with your eyes, but you could measure them using an oscilloscope, or hear
 *    them if they are used to turn the piezo beeper on and off. Try this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

 *    Try changing the delay values in both of the __delay_us(); functions.
 *    Does the pitch of the tone increase or decrease if the delay value is
 *    made smaller?
 * 
 * Increases the delay value makes to tone lower and decreasing the value makes
 * the tone higher.
 * 
 * 
 * 
 * 3. This code demonstrates a more compact way of toggling the beeper output
 *    using a logical NOT operator '!'. Replace the code above, with this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(567);
        }

 *    One difference between this code and the code in 2, above, is the state
 *    of the BEEPER pin when SW5 is released. What state will the BEEPER output
 *    be in after this code runs? While one advantage of this method is smaller
 *    code, can you think of one or more disadvantages based on its output when
 *    the button is released?
 * 
 * A disadvantage is that there's only 1 variable 
 * 
 * 4. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 * 
 *    Test each of your flashing patterns. Describe what happens when more than
 *    one button is held. Do all of the patterns try to flash the LEDs at the
 *    same time, or sequentially? Explain why this is.
 * 
 *  while(1)
        {
        // If SW2 is pressed, make a flashy light pattern
        if(SW3 == 0)
        {
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(250);
            LED6 = 1;
            __delay_ms(400);
            LED3 = 1;
            __delay_ms(550);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(250);
            LED3 = 0;
            __delay_ms(400);
            LED6 = 0;
            __delay_ms(550);
        }
         if(SW4 == 0)
        {
            LED6 = 1;
            __delay_ms(250);
            LED5 = 1;
            __delay_ms(1000);
            LED3 = 1;
            __delay_ms(1500);
            LED4 = 1;
            __delay_ms(1750);
            LED4 = 0;
            __delay_ms(250);
            LED5 = 0;
            __delay_ms(1000);
            LED3 = 0;
            __delay_ms(1500);
            LED6 = 0;
            __delay_ms(1750);
        } if(SW5 == 0)
        {
            LED5 = 1;
            __delay_ms(250);
            LED6 = 1;
            __delay_ms(1000);
            LED3 = 1;
            __delay_ms(1500);
            LED4 = 1;
            __delay_ms(1750);
            LED4 = 0;
            __delay_ms(250);
            LED5 = 0;
            __delay_ms(1000);
            LED3 = 0;
            __delay_ms(1500);
            LED6 = 0;
            __delay_ms(1750);
  
        }
 * 
 * When more than one button is held, it runs whatever the buttons you 
 * programmed it to do in till you release it. The patterns flash the LEDS 
 * sequentially because it runs whatever comes first.
 * 
 * 5. Create a program that makes a different tone for each pushbutton.
 * 
 *    Test each tone by pressing each button individually. Next, press two or
 *    more buttons at the same time. Describe what the tone waveform would look
 *    like when more than one button is held.
 * 
 * if(SW2 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(1);
        } 
        if(SW3 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(500);
        }
        if(SW4 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(1000);
        }
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(4205);
        }
        {
            RESET();
        }
 * 
 * 
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
 *    even after SW3 is released, and turn off when SW4 is pressed. Test your
 *    program to make sure it works.
 * 
 * {
        if(SW3 == 0)
        {
            LED4 = 1;
        }
        if (SW4 == 0)
        {
                LED4 = 0;
                  __delay_ms(100);
        }
 * 
 * 
 * 7. Running your program from 6, above, describe what happens when both SW3
 *    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
 *    of LED D4 compare between its normal on state following SW3 being pressed
 *    to this new state when both SW3 and SW4 are bing held? Can you explain
 *    why it changes?
 * 
 * When both SW3 and SW4 are pressed the LED D4 does not stay on.
 * 
 * 
 * 8. As you can imagine, an industrial machine that is able to turn on even
 *    while its 'Stop' button is pressed represents a significant safety hazard.
 *    Using a logical conditional operator, modify the start-stop program from
 *    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
 *    released.
 * 
 * 
 * 
 * 9. LED D1 is normally used to indicate that a program is running, but it can
 *    be controlled by your program as well. If you take a look at the UBMP4
 *    schematic, you will see that LED D1's cathode (or negative) pin is
 *    connected to the microcontroller instead of the anode (positive) pin as
 *    with the other LEDs. This means that you need to make D1's output a zero
 *    to turn D1 on. Try it! Make a program that controls or flashes LED D1.
 */