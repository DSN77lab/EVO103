#include "main.h"

typedef struct
{
	unsigned char nEntryModeSet;
	unsigned char nDisplayControl;
	unsigned char nCursorDisplayShift;
	unsigned char nFunctionSet;
} LCD_InitTypeDef;
#define LCD_CLEAR_DISPALY_CMD           0b00000001	//x01

#define LCD_CURSOR_HOME_CMD             0b00000010	//x02

#define LCD_ENTRY_MODE_INCREASE         0b00000110	//x02
#define LCD_ENTRY_MODE_DECREASE         0b00000100	//x00
#define LCD_ENTRY_MODE_DISPLAY          0b00000101	//x01
#define LCD_ENTRY_MODE_CURSOR           0b00000100	//x00

#define LCD_DISPLAY_CTRL_DISPLAY_ON     0b00001100	//x04
#define LCD_DISPLAY_CTRL_DISPLAY_OFF    0b00001000	//x00
#define LCD_DISPLAY_CTRL_CURSOR_ON      0b00001010	//x02
#define LCD_DISPLAY_CTRL_CURSOR_OFF     0b00001000	//x00
#define LCD_DISPLAY_CTRL_BLINK_ON       0b00001001	//x01
#define LCD_DISPLAY_CTRL_BLINK_OFF      0b00001000	//x00

#define LCD_CUR_DISPLAY_SHIFT_DISPLAY   0b00011000	//x08
#define LCD_CUR_DISPLAY_SHIFT_CURSOR    0b00010000	//x00
#define LCD_CUR_DISPLAY_SHIFT_RIGHT     0b00010100	//x04
#define LCD_CUR_DISPLAY_SHIFT_LEFT      0b00010000	//x00

#define LCD_FUNCTION_SET_8_BITS         0b00110000	//x10
#define LCD_FUNCTION_SET_4_BITS         0b00100000	//x00
#define LCD_FUNCTION_SET_2_LINES        0b00101000	//x08
#define LCD_FUNCTION_SET_1_LINE         0b00100000	//x00
#define LCD_FUNCTION_SET_LRG_FONT       0b00100100	//x04
#define LCD_FUNCTION_SET_SML_FONT       0b00100000	//x00
#define LCD_FUNCTION_SET_EU_JAP			0b00100000	//x00
#define LCD_FUNCTION_SET_EU1			0b00100001	//x01
#define LCD_FUNCTION_SET_EU_CYR			0b00100010	//x02
#define LCD_FUNCTION_SET_EU2			0b00100001	//x03

#define LCD_CGRAM_ADDR_CMD              0b01000000	//x40

#define LCD_DDRAM_ADDR_CMD              0b10000000	//x80

void LCDinit4(void);					//	LCD initialisation in 4-bit mode
void LCDinit(void);					//	LCD initialisation in 8-bit mode
void LCDstring4 (int nString, char *sString);	//	Write text string in to LCD in 4-bit mode
void LCDstring (int nString, char *sString);	//	Write text string in to LCD in 8-bit mode
void LCDcmd4(unsigned char nChar);	//	Set command in 4-bit mode
void LCDcmd(unsigned char nChar);	//	Set command in 8-bit mode.
void LCDchar4(unsigned char nChar);	//	Set character in 4-bit mode.
void LCDchar(unsigned char nChar);	//	Set character to LCD in 8-bit mode
