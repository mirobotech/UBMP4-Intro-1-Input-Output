/*==============================================================================
 Project: Intro-1-Input-Output          Activity: mirobo.tech/intro-1
 Date:    January 10, 2024
 
 This introductory input and output programming activity for the mirobo.tech
 CHRP4 and UBMP4 demonstrates pushbutton input, LED (bit) output, port (byte)
 output, the use of MPLAB's built-in time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate the logical
 AND and OR conditional operators, the use of time delay functions to create
 sound output, and software-based simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is a required part of every C program. The microcontroller
// begins executing the program starting at the first line in the main function.

int main(void)
{
    // The configuration functions run once during program start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure I/O for on-board UBMP4 devices
    
    // The contents of the while loop repeat continuously.
    while(1)
	{
        // If SW2 is pressed, make a flashy light pattern
        if(SW2 == 0)
        {
            LED2 = 1;
            __delay_ms(100);
            LED3 = 1;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED2 = 0;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
        }

        // Add your Program Analysis Activities and Programming Activities code here:

        // Reset the microcontroller and start the bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

/* Learn More -- Program Analysis Activities
 * 
 * 1. Let's analyze this program! Program analysis is an important skill to 
 *    develop to better understand a program's operation. Start by running the
 *    program in your circuit board. Press and immediately release SW2 and watch
 *    what the LEDs do. How many LEDs flash? How many times to they flash? Next,
 *    press and hold SW2 and observe the LEDs and flashing pattern. Does the
 *    pattern stop immediately when you let go of SW2?
 * 
 *    Now, examine the program and try to match your observations of the light
 *    pattern to the program code. How many digitalWrite and delay statements
 *    are grouped together inside the curly braces that follow the SW2state 'if'
 *    statement? Did all of these actions happen when you pressed and let go of
 *    SW2? Can you explain why the microcontroller will always complete all of
 *    the actions inside the braces, and not skip any of the steps each time
 *    pushbutton SW2 is pressed?
 * 
 * 2. Explain the difference between the statements: LED2 = 1; and LED2 = 0;
 *    How does setting LED2 to 1 or 0 in the program code actually turn LED2 on
 *    or off on the circuit board?
 * 
 * 3. Understanding how a circuit works is another important skill to develop
 *    in interfacing (controlling hardware with software). What voltage do you
 *    expect the microcontroller to output to LED D2 when the statement
 *    'LED2 = 0;' runs? What voltage do you expect the output to be when the
 *    statement 'LED2 = 1;' runs?
 * 
 *    If you have access to a voltmeter, you can use it confirm the output
 *    voltage of the microcontroller in the circuit. Try measuring across one
 *    of the LEDs as the program outputs a 0, and again when it outputs a 1.
 *    The voltage will change quickly so you may need to use a 'peak hold' or
 *    'max' feature if your multimeter has one, or slow down the light pattern
 *    in your program by increasing the time delays.
 * 
 *    Next, refer to the schematic and find one of the microcontroller pins that
 *    connects to one of the LEDs. Carefully measure between the microcontroller
 *    pin and the negative pad of battery connector BT1 on the circuit board as
 *    you run the program and press SW2. Compare your measurements. Did one of
 *    these voltages match your prediction? Which one? Can you explain why?
 * 
 * 4. The statement 'LED2 = 1;' contains a single equal sign while the stateemnt
 *    'if(SW2 == 0)' contains two equal signs. What operation is performed by a
 *    statement using one equal sign? What operation is performed by a statement
 *    using two equal signs? How are the two operations different?
 * 
 * 5. Find the switch circuits on the schematic diagram. Why do you think the
 *    program code uses the statement 'if(SW2 == 0)' to sense if a switch is
 *    pressed? Can you use the schematic to explain why the input voltage on
 *    one of the microcontroller's switch inputs will be low when the switch
 *    is pressed?
 *  
 * 6. The four LEDs controlled by this program are all connected to PORTC's
 *    output latches (called LATC). Let's test another way of controlling the
 *    LEDs by writing to the LATC register directly. This will allow us to
 *    control all of the outputs simultaneously with a single program statement.
 * 
 *    Copy the block of code (below) and pasted it after the SW2 'if' structure
 *    closing brace in your program (shown by the comment in the program).

        if(SW3 == 0)
        {
            LATC = 0b00000000;
            __delay_ms(100);
            LATC = 0b11110000;
            __delay_ms(100);
        }

 *    Re-build the program and upload it into your circuit. What happens when
 *    pushbutton SW3 is pressed? Can you think of at least one advantage and one
 *    disadvantage of controlling all of the LEDs using 'LATC' statements rather
 *    than by using individual 'LEDn = x;' statements?
 * 
 * 7. Let's compare the operation of 'if' and 'while' structures to simulate the
 *    operation of real-world momentary buttons. Add the following code below
 *    the existing 'if(SW2 == 0)' block in the program (replacing the SW3 code
 *    added above), and then build and re-upload the program into to your
 *    circuit board.

        // Momentary button using an if structure
        if(SW3 == 0)
        {
            LED3 = 1;
        }
        else
        {
            LED3 = 0;
        }

        // Momentary button using a while structure
        while(SW4 == 0)
        {
            LED4 = 1;
        }
        LED4 = 0;

 *    First, try pressing and releasing SW3 and SW4 one at a time. They should
 *    act the same way, turning their respective LEDs on as each switch is
 *    pressed, and off as each switch is released.
 * 
 *    Next, press and hold SW3 while pressing and releasing SW4. Does SW4 work
 *    as expected?
 * 
 *    Last, press and hold SW4 while pressing and releasing SW3. Does SW3 work
 *    as expected?
 * 
 *    Can you explain the difference in operation between the 'if' and 'while'
 *    structures in the two different examples of momentary button code?
 * 
 * 8. Let's explore logical conditions made using 'if' statements. Replace the
 *    program code added in steps 6 and 7, above, with this 'nested if' code
 *    to create a logical AND condition that will light LED D3 only if both
 *    SW3 and SW4 are pressed:

        // Nested if 'AND' code
        if(SW3 == 0)
        {
            if(SW4 == 0)
            {
                LED3 = 1;
            }
            else
            {
                LED3 = 0;
            }
        }
        else
        {
            LED3 = 0;
        }

 *    Test the code to ensure it works as expected. Does the order of the if
 *    conditions matter? (e.g. swap the conditional checks for SW3 and SW4)
 * 
 * 9. Next, replace the code from activity 8, above, with the following code
 *    which implements the logical AND conditional operator ? it's composed of
 *    two ampersands '&&' and becomes part of the 'if' statement:
 
        // Conditional 'AND' code
        if(SW3 == 0 && SW4 == 0)
        {
            LED3 = 1;
        }
        else
        {
            LED3 = 0;
        }

 *    Does '&&' work the same way as the nested if structures? Can you think of
 *    at least one advantage of using a logical conditional operator instead of
 *    nested if structures?
 * 
 * 10. Replace the double ampersand '&&' with double vertical bars '||' to make
 *    a logical OR conditional operator. Your code should now look like this:
  
        // Conditional 'OR' code
        if(SW3 == 0 || SW4 == 0)
        {
            LED3 = 1;
        }
        else
        {
            LED3 = 0;
        }

 *    Describe the conditions under which LED3 turns on.
 * 
 * Programming Activities
 * 
 * 1. The statement '__delay_ms(100);' creates a 100 ms delay. Try changing one
 *    or more of the delay values in the program to 500 ms and see what happens.
 * 
 *    Can the delay be made even longer? Try 1000 ms. How big can the delay get
 *    before MPLAB-X produces an error message? (Hint: can you think of a fast
 *    and efficient way of guessing an unknown number?)
 * 
 * 2. The '__delay_ms();' function accepts only integers as delay values. To
 *    create delays shorter than 1 ms, a different function must be used. Use
 *    the '__delay_us();' function to specify delays in microseconds.
 * 
 *    You won't be able to see microsecond length LED flashes with your eyes,
 *    but you can measure them using an oscilloscope or hear them if they are
 *    used to turn the piezo beeper on and off. Try the following code in your
 *    program. The delay was chosen to be the time period of music note A5
 *    which should play a tone at a frequency of 880Hz.
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

 *    Try changing the values used in both of the __delay_us(); functions. Does
 *    the pitch of the tone increase or decrease if the delay values are made
 *    smaller? Does the opposite happen if the delays are made larger?
 * 
 * 3. This code demonstrates a more compact way of 'toggling' the beeper output
 *    using a logical NOT operator '!'. Replace the code above, with this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(567);
        }

 *    One difference between this code and the code in activity 2, above, will
 *    be the state of the BEEPER pin when SW5 is released. Because we don't know
 *    how many times this code will run, we also won't know the state of the
 *    BEEPER pin after the code runs. While one advantage of this method is that
 *    it uses less program code, can you think of one or more disadvantages
 *    of not knowing the output state of a pin that might prevent you from using
 *    code like this in your programs?
 * 
 * 4. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 * 
 *    Test each of your flashing patterns to verify that they work as expected.
 *    Describe what happens when more than one button is held. Do all of the
 *    patterns flash the LEDs at the same time, or in sequence? What sequence
 *    do they follow? Explain why this happens.
 * 
 * 5. Create a program that makes a different tone for each pushbutton.
 * 
 *    Test each tone by pressing each button individually. Next, press two or
 *    more buttons at the same time. Describe what you think the tone waveforms
 *    will look like when two or more buttons are held. (You can verify your
 *    prediction if you have access to an oscilloscope and connect it across
 *    the piezo beeper's output resistor on the circuit board.)
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. Use SW3 as the Start button to turn LED D3 on when
 *    it is pressed, and keep LED D3 on even after SW3 has been released. Use
 *    SW4 as the Stop button to turn LED D3 off when it is pressed. Test your
 *    program to make sure that it works the way you expect it to.
 * 
 * 7. Running your program from step 6, above, describe what happens when both
 *    pushbuttons SW3 and SW4 are held. Does LED D3 turn on? Does LED D3 stay
 *    on? If so, is its brightness the same when both buttons are held as when
 *    just SW3 is pressed? If the brightness is different, can you explain what
 *    part of the code might be causing it to change, and why it changes?
 *    Hint: pretend to be the computer and try to simulate what the program is
 *    doing.
 * 
 * 8. As you might imagine, an industrial machine that is able to turn on an
 *    output even while its 'Stop' button is pressed represents a significant
 *    safety hazard. Using one or more of the logical conditional operators
 *    introduced in the analysis activities, above, modify your start-stop
 *    program to make it safer. SW3 should only be able to turn LED D3 on if
 *    switch SW4 is not being pressed at the same time.
 * 
 * 9. Create a program that uses the pushbuttons and LEDs to make a turn signal
 *    circuit for a bicycle. Choose two buttons to use to indicate left or right
 *    turns, and think about the best way to implement turn signals if a pair
 *    of similar momentary pushbuttons were mounted on a bicycle's handlebars.
 *    Would the user have to hold a button to keep the turn signal flashing,
 *    or would pressing a button once start the turn signal and keep it going
 *    until the button is pressed again to cancel it? What will the turn signal
 *    indication look like if the four LEDs were to be mounted horizontally
 *    under the seat of the bicycle? Write a program that implements your best
 *    turn signal solution using the concepts learned in this activity. Test
 *    your solution to ensure it behaves as expected under unusual use cases
 *    such as the user holding both buttons, for example.
 *
 *10. Modify your bike turn signal program, above, to use one or both of the
 *    other buttons to add brake functionality, and/or to implement a rapidly
 *    flashing tail-light for enhanced visibility. Test your program to ensure
 *    that all of its functions work as expected under all conditions.
 *
 *11. LED D1 is normally used to indicate that a program is running, but it can
 *    be controlled by your program as well. If you examine your circuit's
 *    schematic, you will see that LED D1's cathode (or negative) pin is
 *    connected to the microcontroller instead of its anode (positive) as with
 *    the other LEDs. This means that the LED D1 output must be made a low
 *    voltage for D1 to turn on.
 * 
 *    Try it! Make a program that controls or flashes LED D1 as part of a light
 *    pattern. (Be careful that you don't change the SW1 reset code when making
 *    your light pattern, or you may not be able to use pushbutton SW1 to reset
 *    the board and start the bootloader. If this ever happens, simply unplug
 *    the USB cable and press and hold SW1 while re-connecting the USB cable.
 *    LED D1 will remain off until you release SW1, and the bootloader will be
 *    forced to start after SW1 is released. Then, be sure to re-enable the SW1
 *    reset code that your previous code edits accidentally disabled.)
 */
