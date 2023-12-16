/* Copyright (c) 2014 Marian Longa. All rights reserved.
 * http://marianlonga.com, http://github.com/marianlonga/LCD-display */

#include "LCD-library.h"

void __delay(int time)  {for(int i = 0; i < time; i++);}
void _delay_us(int us) {for(int i = 0; i < us; i++) __delay_us(1);}
void _delay_ms(int ms) {for(int i = 0; i < ms; i++) __delay_ms(1);}
void __delay_s(int s)   {for(int i = 0; i < s; i++) for(int j = 0; j < 1000; j++) _delay_ms(1);}

void LCD_Wait() {
    if(LCD_UseBusyFlag) {
        if(LCD_dataLength == 8) {
            LCD_dataTRIS = 0xFF; // set RD to input pins
            LCD_rs       = 0; // command register
            LCD_rw       = 1; // read

            // I must read the busy flag between en=HIGH and en=LOW
            LCD_en = 1; __delay(2);
            while(LCD_busy) {
                LCD_en=0; __delay(2);
                LCD_en=1; __delay(2);
            }
            LCD_en = 0; __delay(2);

            LCD_dataTRIS = 0x00; // set RD back to outputs
        }
        else if(LCD_dataLength == 4) {
            LCD_dataTRIS |= 0b11110000; // set upper 4 bits of data register to input pins
            LCD_rs       = 0; // command register
            LCD_rw       = 1; // read

            // I must read the busy flag from the high nibble between en=HIGH and en=LOW. I must also read the low nibble (and ignore it).
            LCD_en = 1; __delay(2);
            while(LCD_busy) {
                LCD_en=0; __delay(2);
                LCD_en=1; __delay(2);
                LCD_en=0; __delay(2);
                LCD_en=1; __delay(2);
            }
            LCD_en=0; __delay(2);
            LCD_en=1; __delay(2);
            LCD_en=0; __delay(2);
            
            LCD_dataTRIS &= 0b00001111; // set upper 4 bits of data register back to outputs
          
        }
    }
    else _delay_us(LCD_CommandDelay);
}

void LCD_8bitCodeNoWait(int code) {
    LCD_rs   = (code & 0b1000000000) >> 9;
    LCD_rw   = (code & 0b0100000000) >> 8;
    LCD_data =  code & 0b0011111111;
    LCD_en   = 1; // enable pin HIGH-->LOW
    LCD_en   = 0;
}
void LCD_8bitCode(int code) {
    LCD_8bitCodeNoWait(code);
    LCD_Wait();
}

void LCD_4bitCodeNoWait(int code) { // USES HIGHEST 4 BITS OF DATA REGISTER!
    LCD_rs   = (code & 0b100000) >> 5;
    LCD_rw   = (code & 0b010000) >> 4;
    LCD_data &= 0b00001111; // clear highest 4 bits of data register (where we'll send data)
    LCD_data |= (code & 0b001111) << 4; // put the data to highest 4 bits of data register
    LCD_en   = 1; // enable pin HIGH-->LOW
    LCD_en   = 0;
}
void LCD_4bitCode(int code) {
    LCD_4bitCodeNoWait(code);
    LCD_Wait();
}

void LCD_Code(int code) {
    if(LCD_dataLength == 8) LCD_8bitCode(code);
    if(LCD_dataLength == 4) {
        LCD_4bitCode(code >> 4); // upper nibble is executed
        LCD_4bitCode(((code & 0b1100000000)>>4) + (code & 0b1111)); // lower nibble is executed
    }
}

void LCD_Init() {
    LCD_dataTRIS = LCD_isBacklightOnTRIS = LCD_rs_dir = LCD_rw_dir = LCD_en_dir = 0; // all LCD pins to output
    LCD_en       = LCD_rs     = LCD_rw     = LCD_data   = 0;// default values for LCD pins are 0

    // convert human-readable config to machine-readable
    int LCD_dl, LCD_n, LCD_f;
    if(LCD_dataLength ==  8) LCD_dl = 1; else if(LCD_dataLength == 4) LCD_dl = 0;
    if(LCD_rows        ==  2) LCD_n  = 1; else if(LCD_rows        == 1) LCD_n  = 0;
    if(LCD_CharHeight        == 10) LCD_f  = 1; else if(LCD_CharHeight        == 8) LCD_f  = 0;

    if(LCD_dataLength == 8) {

        // Official init starts here
        _delay_ms(50);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2)); // set function set
        _delay_ms(10);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2)); // set function set
        _delay_us(200);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2)); // set function set

        _delay_us(200); // although not in datasheet, this delay is necessary for initialization

        LCD_8bitCode(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2)); // set function set
        LCD_8bitCode(0b0000001000); // display OFF
        LCD_8bitCode(0b0000000001); // clear display
        LCD_8bitCode(0b0000000100 + (LCD_isIncrement<<1) + LCD_isShift); // set entry mode
        // Official init ends here

        LCD_8bitCode(0b0000001000 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1) + LCD_isCursorBlinking); // display ON, cursor ON, cursor not blinking
    }
    else if(LCD_dataLength == 4) {
        // Official init starts here
        _delay_ms(50);
        LCD_4bitCodeNoWait(0b000011); // set function set
        _delay_ms(10);
        LCD_4bitCodeNoWait(0b000011); // set function set
        _delay_us(200);
        LCD_4bitCodeNoWait(0b000011); // set function set

        _delay_us(200); // although not in datasheet, this delay is necessary for initialization

        LCD_4bitCode(0b000010); // set function set // 4 bits
        LCD_4bitCode(0b000010); LCD_4bitCode(0b000000 + (LCD_n<<3) + (LCD_f<<2));  // set function set // 4 bits
        LCD_4bitCode(0b000000); LCD_4bitCode(0b001000); // display OFF
        LCD_4bitCode(0b000000); LCD_4bitCode(0b000001); // clear display
        LCD_4bitCode(0b000000); LCD_4bitCode(0b000100 + (LCD_isIncrement<<1) + LCD_isShift); // set entry mode
        // Official init ends here

        LCD_4bitCode(0b000000); LCD_4bitCode(0b001000 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1) + LCD_isCursorBlinking); // display on/off control
    }
    LCD_SetCursorAt(LCD_posX, LCD_posY); // set initial position of cursor
}

//display char on LCD
void LCD_PrintChar(char inputChar) {
    LCD_Code(0b1000000000 + inputChar); // char is an 8bit binary ASCII code, compatible with character codes which can be displayed on HD44780
    // update cursor position based on the increment/decrement setting
    if(LCD_isIncrement) LCD_posX++; else LCD_posX--;
    // if we don't want cursor to move, its position is returned back
    if(!LCD_isCursorMoving) {
        if(LCD_isIncrement) LCD_MoveCursorLeft(1);
        else LCD_MoveCursorRight(1);
    }
}

// displays string
void LCD_PrintStr(const char *str) {
    // if cursor isn't moving, save initial (x,y) position
    int initialX = LCD_posX;
    int initialY = LCD_posY;

    for(int i = 0; i < strlen(str); i++) {
        if (str[i] == '\r'){
            LCD_SetCursorAt(1, 2);
            i++;
        }
        else{
            LCD_PrintChar(str[i]);
            // if we don't want cursor to move, it will display all characters on one place so we must move it
            if(!LCD_isCursorMoving) {
                if(LCD_isIncrement) LCD_MoveCursorRight(1);
                else LCD_MoveCursorLeft(1);
            }
        }
    }
    // if cursor isn't moving, return cursor back to initial position
    if(!LCD_isCursorMoving) LCD_SetCursorAt(initialX, initialY);
}

// displays string waiting "delay" milliseconds after each letter
void LCD_TypeStr(const char *str, int delay) {
    // if cursor isn't moving, save initial (x,y) position
    int initialX = LCD_posX;
    int initialY = LCD_posY;

    for(int i = 0; i < strlen(str); i++) {
        LCD_PrintChar(str[i]);
        // if we don't want cursor to move, it will display all characters on one place so we must move it
        if(!LCD_isCursorMoving) {
            if(LCD_isIncrement) LCD_MoveCursorRight(1);
            else LCD_MoveCursorLeft(1);
        }
        _delay_ms(delay);
    }
    // if cursor isn't moving, return cursor back to initial position
    if(!LCD_isCursorMoving) LCD_SetCursorAt(initialX, initialY);
}

void LCD_PrintNum(long int number) {
    char strNumber[20];
    sprintf(strNumber, "%d", number);
    //itoa(strNumber, number, 10); // convert int to string
    LCD_PrintStr(strNumber);
}

/*void LCD_displayNumberRight(long int number) {
    char strNumber[20];
    sprintf(strNumber, "%d", number);
    //itoa(strNumber, number, 10); // convert int to string
    LCD_moveLeft(strlen(strNumber)-1);
    LCD_PrintStr(strNumber);
    if(!LCD_isCursorMoving) LCD_moveRight(strlen(strNumber)-1);
}*/

void LCD_Clear() {
    LCD_Code(0b0000000001); // clear display
    LCD_posX = LCD_posY = 1; // cursor is reset to (1,1)
    _delay_ms(200);
}

// if display is turned on, turn it off
// display OFF, cursor OFF, blinking OFF
void LCD_TurnOff() {
    if(LCD_isDisplayOn) {
        LCD_Code(0b0000001000);
        LCD_isDisplayOn = FALSE;
    }
}

//void LCD_on()    {LCD_code(0b0000001110);} // display ON, cursor ON, blinking OFF
void LCD_TurnOn() {
    if(!LCD_isDisplayOn) {
       LCD_Code(0b0000001100 + (LCD_isCursorOn<<1) + LCD_isCursorBlinking); // turn display on with previous settings
       LCD_isDisplayOn = TRUE;
    }
}

void LCD_SetCursorAt(int pos, int row) {
    if(pos >= 1 && pos <= LCD_columns && row >= 1 && row <= LCD_rows){ // is the chosen cursor position in range?
        LCD_posX = pos; // set the variables
        LCD_posY = row;
        switch(row) { // set the DDRAMA address in LCD
            case 1:  LCD_Code(0b0010000000 + 0x00 + (pos-1)); break;
            case 2:  LCD_Code(0b0010000000 + 0x40 + (pos-1)); break;
            //case  3: LCD_code(0b0010000000 + 0x14 + (pos-1)); break;
            //case  4: LCD_code(0b0010000000 + 0x54 + (pos-1)); break;
            default: LCD_Code(0b0010000000 + 0x00 + (pos-1)); break; // default is 1st row
        }
    }
}

void LCD_home() {
    LCD_Code(0b0000000010);
    LCD_posX = LCD_posY = 1; // cursor is reset to (1,1)
}

void LCD_CursorOff() {
    if(LCD_isCursorOn) {
        LCD_Code(0b0000001000 + (LCD_isDisplayOn<<2) + LCD_isCursorBlinking);
        LCD_isCursorOn = FALSE;
    }
}

void LCD_CursorOn() {
    if(!LCD_isCursorOn) {
        LCD_Code(0b0000001010 + (LCD_isDisplayOn<<2) + LCD_isCursorBlinking);
        LCD_isCursorOn = TRUE;
    }
}

void LCD_CursorBlinkingOn() {
    if(LCD_isCursorBlinking) {
        LCD_Code(0b0000001000 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1));
        LCD_isCursorBlinking = FALSE;
    }
}

void LCD_CursorBlinkingOff() {
    if(!LCD_isCursorBlinking) {
        LCD_Code(0b0000001001 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1));
        LCD_isCursorBlinking = TRUE;
    }
}

void LCD_MoveCursorLeft(int howMuch) {
    if(LCD_posX -howMuch >= 1) {
        LCD_posX -= howMuch;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}

void LCD_MoveCursorRight(int howMuch) {
    if(LCD_posX +howMuch <= LCD_columns) {
        LCD_posX += howMuch;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}

void LCD_MoveCursorUp(int howMuch) {
    if(LCD_posY -howMuch >= 1) {
        LCD_posY -= howMuch;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}

void LCD_MoveCursorDown(int howMuch) {
    if(LCD_posY +howMuch <= LCD_rows) {
        LCD_posY += howMuch;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}
// Function to save a new custom character into the LCD CGRAM
void LCD_NewChar(uint8_t location, const uint8_t *pattern) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        LCD_Code(0b0001000000 + (location * 8) + i);
        LCD_Code((0b10 << 8) + pattern[i]);
    }
    LCD_SetCursorAt(0, 0);
    //LCD_home();
}

/*void LCD_backlightOnOff(){
    PORTGbits.RG5=!PORTGbits.RG5;
}*/