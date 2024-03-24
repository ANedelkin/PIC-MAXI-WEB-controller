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
            LCD_dataTRIS = 0xFF;
            LCD_rs       = 0;
            LCD_rw       = 1;

            LCD_en = 1; __delay(2);
            while(LCD_busy) {
                LCD_en=0; __delay(2);
                LCD_en=1; __delay(2);
            }
            LCD_en = 0; __delay(2);

            LCD_dataTRIS = 0x00;
        }
        else if(LCD_dataLength == 4) {
            LCD_dataTRIS |= 0b11110000;
            LCD_rs       = 0;
            LCD_rw       = 1;

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
            
            LCD_dataTRIS &= 0b00001111;
          
        }
    }
    else _delay_us(LCD_CommandDelay);
}

void LCD_8bitCodeNoWait(int code) {
    LCD_rs   = (code & 0b1000000000) >> 9;
    LCD_rw   = (code & 0b0100000000) >> 8;
    LCD_data =  code & 0b0011111111;
    LCD_en   = 1;
    LCD_en   = 0;
}
void LCD_8bitCode(int code) {
    LCD_8bitCodeNoWait(code);
    LCD_Wait();
}

void LCD_4bitCodeNoWait(int code) {
    LCD_rs   = (code & 0b100000) >> 5;
    LCD_rw   = (code & 0b010000) >> 4;
    LCD_data &= 0b00001111;
    LCD_data |= (code & 0b001111) << 4;
    LCD_en   = 1;
    LCD_en   = 0;
}
void LCD_4bitCode(int code) {
    LCD_4bitCodeNoWait(code);
    LCD_Wait();
}

void LCD_Code(int code) {
    if(LCD_dataLength == 8) LCD_8bitCode(code);
    if(LCD_dataLength == 4) {
        LCD_4bitCode(code >> 4);
        LCD_4bitCode(((code & 0b1100000000)>>4) + (code & 0b1111));
    }
}

void LCD_Init() {
    LCD_dataTRIS = LCD_isBacklightOnTRIS = LCD_rs_dir = LCD_rw_dir = LCD_en_dir = 0;
    LCD_en       = LCD_rs     = LCD_rw     = LCD_data   = 0;

    int LCD_dl, LCD_n, LCD_f;
    if(LCD_dataLength ==  8) LCD_dl = 1; else if(LCD_dataLength == 4) LCD_dl = 0;
    if(LCD_rows        ==  2) LCD_n  = 1; else if(LCD_rows        == 1) LCD_n  = 0;
    if(LCD_CharHeight        == 10) LCD_f  = 1; else if(LCD_CharHeight        == 8) LCD_f  = 0;

    if(LCD_dataLength == 8) {

        _delay_ms(50);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2));
        _delay_ms(10);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2));
        _delay_us(200);
        LCD_8bitCodeNoWait(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2));

        _delay_us(200);

        LCD_8bitCode(0b0000100000 + (LCD_dl<<4) + (LCD_n<<3) + (LCD_f<<2));
        LCD_8bitCode(0b0000001000);
        LCD_8bitCode(0b0000000001);
        LCD_8bitCode(0b0000000100 + (LCD_isIncrement<<1) + LCD_isShift);

        LCD_8bitCode(0b0000001000 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1) + LCD_isCursorBlinking);
    }
    else if(LCD_dataLength == 4) {
        _delay_ms(50);
        LCD_4bitCodeNoWait(0b000011);
        _delay_ms(10);
        LCD_4bitCodeNoWait(0b000011);
        _delay_us(200);
        LCD_4bitCodeNoWait(0b000011);

        _delay_us(200);

        LCD_4bitCode(0b000010);
        LCD_4bitCode(0b000010); LCD_4bitCode(0b000000 + (LCD_n<<3) + (LCD_f<<2));
        LCD_4bitCode(0b000000); LCD_4bitCode(0b001000);
        LCD_4bitCode(0b000000); LCD_4bitCode(0b000001);
        LCD_4bitCode(0b000000); LCD_4bitCode(0b000100 + (LCD_isIncrement<<1) + LCD_isShift);

        LCD_4bitCode(0b000000); LCD_4bitCode(0b001000 + (LCD_isDisplayOn<<2) + (LCD_isCursorOn<<1) + LCD_isCursorBlinking); // display on/off control
    }
    LCD_SetCursorAt(LCD_posX, LCD_posY);
}
void LCD_PrintChar(char inputChar) {
    LCD_Code(0b1000000000 + inputChar);
    if(LCD_isIncrement) LCD_posX++; else LCD_posX--;
    if(!LCD_isCursorMoving) {
        if(LCD_isIncrement) LCD_MoveCursorLeft(1);
        else LCD_MoveCursorRight(1);
    }
}
void LCD_PrintStr(const char *str, int delay) {
    int initialX = LCD_posX;
    int initialY = LCD_posY;
    for(int i = 0; i < strlen(str); i++) {
        if (i == 16) LCD_SetCursorAt(1, 2);
        LCD_PrintChar(str[i]);
        if(!LCD_isCursorMoving) {
            if(LCD_isIncrement) LCD_MoveCursorRight(1);
            else LCD_MoveCursorLeft(1);
        }
        _delay_ms(delay);
    }
    if(!LCD_isCursorMoving) LCD_SetCursorAt(initialX, initialY);
}
void LCD_PrintNum(long int number, int delay) {
    char strNumber[20];
    sprintf(strNumber, "%d", number);
    LCD_PrintStr(strNumber, delay);
}
void LCD_Clear() {
    LCD_Code(0b0000000001);
    LCD_posX = LCD_posY = 1;
    _delay_ms(200);
}
void LCD_TurnOff() {
    if(LCD_isDisplayOn) {
        LCD_Code(0b0000001000);
        LCD_isDisplayOn = FALSE;
    }
}
void LCD_TurnOn() {
    if(!LCD_isDisplayOn) {
       LCD_Code(0b0000001100 + (LCD_isCursorOn<<1) + LCD_isCursorBlinking);
       LCD_isDisplayOn = TRUE;
    }
}
void LCD_SetCursorAt(int x, int y) {
    if(x >= 1 && x <= LCD_columns && y >= 1 && y <= LCD_rows){
        LCD_posX = x;
        LCD_posY = y;
        switch(y) {
            case 1:  LCD_Code(0b0010000000 + 0x00 + (x-1)); break;
            case 2:  LCD_Code(0b0010000000 + 0x40 + (x-1)); break;
            default: LCD_Code(0b0010000000 + 0x00 + (x-1)); break;
        }
    }
}
void LCD_home() {
    LCD_Code(0b0000000010);
    LCD_posX = LCD_posY = 1;
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
void LCD_MoveCursorLeft(int amound) {
    if(LCD_posX -amound >= 1) {
        LCD_posX -= amound;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}
void LCD_MoveCursorRight(int amount) {
    if(LCD_posX +amount <= LCD_columns) {
        LCD_posX += amount;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}
void LCD_MoveCursorUp(int amount) {
    if(LCD_posY -amount >= 1) {
        LCD_posY -= amount;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}
void LCD_MoveCursorDown(int amount) {
    if(LCD_posY +amount <= LCD_rows) {
        LCD_posY += amount;
        LCD_SetCursorAt(LCD_posX, LCD_posY);
    }
}
void LCD_NewChar(uint8_t location, const uint8_t *pattern) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        LCD_Code(0b0001000000 + (location * 8) + i);
        LCD_Code((0b10 << 8) + pattern[i]);
    }
    LCD_SetCursorAt(0, 0);
}