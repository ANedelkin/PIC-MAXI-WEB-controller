/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F97J60
        Version           :  2.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB             :  MPLAB X 6.00

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  anselRA0bits.anselRA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { anselRA0bits.anselRA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { anselRA0bits.anselRA0 = 0; } while(0)

// get/set Potentiometer aliases
#define Potentiometer_TRIS                 TRISAbits.TRISA2
#define Potentiometer_LAT                  LATAbits.LATA2
#define Potentiometer_PORT                 PORTAbits.RA2
#define Potentiometer_ANS                  anselRA2bits.anselRA2
#define Potentiometer_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Potentiometer_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Potentiometer_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Potentiometer_GetValue()           PORTAbits.RA2
#define Potentiometer_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Potentiometer_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Potentiometer_SetAnalogMode()      do { anselRA2bits.anselRA2 = 1; } while(0)
#define Potentiometer_SetDigitalMode()     do { anselRA2bits.anselRA2 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set IO_RJ0 aliases
#define IO_RJ0_TRIS                 TRISJbits.TRISJ0
#define IO_RJ0_LAT                  LATJbits.LATJ0
#define IO_RJ0_PORT                 PORTJbits.RJ0
#define IO_RJ0_SetHigh()            do { LATJbits.LATJ0 = 1; } while(0)
#define IO_RJ0_SetLow()             do { LATJbits.LATJ0 = 0; } while(0)
#define IO_RJ0_Toggle()             do { LATJbits.LATJ0 = ~LATJbits.LATJ0; } while(0)
#define IO_RJ0_GetValue()           PORTJbits.RJ0
#define IO_RJ0_SetDigitalInput()    do { TRISJbits.TRISJ0 = 1; } while(0)
#define IO_RJ0_SetDigitalOutput()   do { TRISJbits.TRISJ0 = 0; } while(0)

// get/set IO_RJ1 aliases
#define IO_RJ1_TRIS                 TRISJbits.TRISJ1
#define IO_RJ1_LAT                  LATJbits.LATJ1
#define IO_RJ1_PORT                 PORTJbits.RJ1
#define IO_RJ1_SetHigh()            do { LATJbits.LATJ1 = 1; } while(0)
#define IO_RJ1_SetLow()             do { LATJbits.LATJ1 = 0; } while(0)
#define IO_RJ1_Toggle()             do { LATJbits.LATJ1 = ~LATJbits.LATJ1; } while(0)
#define IO_RJ1_GetValue()           PORTJbits.RJ1
#define IO_RJ1_SetDigitalInput()    do { TRISJbits.TRISJ1 = 1; } while(0)
#define IO_RJ1_SetDigitalOutput()   do { TRISJbits.TRISJ1 = 0; } while(0)

// get/set IO_RJ2 aliases
#define IO_RJ2_TRIS                 TRISJbits.TRISJ2
#define IO_RJ2_LAT                  LATJbits.LATJ2
#define IO_RJ2_PORT                 PORTJbits.RJ2
#define IO_RJ2_SetHigh()            do { LATJbits.LATJ2 = 1; } while(0)
#define IO_RJ2_SetLow()             do { LATJbits.LATJ2 = 0; } while(0)
#define IO_RJ2_Toggle()             do { LATJbits.LATJ2 = ~LATJbits.LATJ2; } while(0)
#define IO_RJ2_GetValue()           PORTJbits.RJ2
#define IO_RJ2_SetDigitalInput()    do { TRISJbits.TRISJ2 = 1; } while(0)
#define IO_RJ2_SetDigitalOutput()   do { TRISJbits.TRISJ2 = 0; } while(0)


/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/