#include "main.h"
#include "LCD2x20.h"
void LCDinit4(void)					//	LCD initialisation in 4-bit mode
{
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, 0);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, 0);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, 1);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, 0);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	LCDcmd4(LCD_FUNCTION_SET_4_BITS | LCD_FUNCTION_SET_2_LINES | LCD_FUNCTION_SET_LRG_FONT | LCD_FUNCTION_SET_EU_CYR);	//0b00111010);				// Function set: 8-bit mode, 2-line mode, Display off.
	LCDcmd4(LCD_DISPLAY_CTRL_DISPLAY_ON | LCD_DISPLAY_CTRL_CURSOR_OFF | LCD_DISPLAY_CTRL_BLINK_OFF);	//0b00001100);				// Display on/off:	Display on, Cursor off, Blink off.
	LCDcmd4(LCD_CLEAR_DISPALY_CMD);	//0b00000001);				// Clear display.
	LCDcmd4(LCD_ENTRY_MODE_INCREASE | LCD_ENTRY_MODE_CURSOR); //0b00000110);				// Entry mode:	Increment mode, Shift off.
}
void LCDinit(void)					//	LCD initialisation in 8-bit mode
{
	LCDcmd(LCD_FUNCTION_SET_8_BITS | LCD_FUNCTION_SET_2_LINES | LCD_FUNCTION_SET_LRG_FONT | LCD_FUNCTION_SET_EU_CYR);	//0b00111000);				// Function set: 8-bit mode, 2-line mode, Display off.
	LCDcmd(LCD_DISPLAY_CTRL_DISPLAY_ON | LCD_DISPLAY_CTRL_CURSOR_OFF | LCD_DISPLAY_CTRL_BLINK_OFF);	//0b00001100);				// Display on/off:	Display on, Cursor off, Blink off.
	LCDcmd(LCD_CLEAR_DISPALY_CMD);	//0b00000001);				// Clear display.
	LCDcmd(LCD_ENTRY_MODE_INCREASE | LCD_ENTRY_MODE_CURSOR); //0b00000110);				// Entry mode:	Increment mode, Shift off.
}
void LCDstring4 (int nString, char *sString)	//	Write text string in to LCD in 4-bit mode
{
//	switch (nString)
//	{
//		case 1:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x00);	break;
//		case 2:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x40);	break;
//		default:	return;
//	}
	for(int i = 0; sString[i]; i++)
	{
		switch (nString)
		{
			case 1:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x00 | i);	break;
			case 2:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x40 | i);	break;
			default:	return;
		}
		LCDchar4(sString[i]);
	}
}
void LCDstring (int nString, char *sString)	//	Write text string in to LCD in 8-bit mode
{
//	switch (nString)
//	{
//		case 1:	  LCDcmd(LCD_DDRAM_ADDR_CMD | 0x00);	break;
//		case 2:	  LCDcmd(LCD_DDRAM_ADDR_CMD | 0x40);	break;
//		default:	return;
//	}
	for(int i = 0; sString[i]; i++)
	{
		switch (nString)
		{
			case 1:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x00);	break;
			case 2:	  LCDcmd4(LCD_DDRAM_ADDR_CMD | 0x40);	break;
			default:	return;
		}
		LCDchar(sString[i]);
	}
}
void LCDcmd4(unsigned char nChar)	//	Set command in 4-bit mode
{
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b10000000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b01000000);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00100000);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00010000);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);

	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b00001000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b00000100);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00000010);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00000001);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}
/*void LCDcmd(unsigned char nChar)	//	Set command in 8-bit mode.
{
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b10000000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b01000000);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00100000);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00010000);
	HAL_GPIO_WritePin(LCD3_GPIO_Port, LCD3_Pin, nChar & 0b00001000);
	HAL_GPIO_WritePin(LCD2_GPIO_Port, LCD2_Pin, nChar & 0b00000100);
	HAL_GPIO_WritePin(LCD1_GPIO_Port, LCD1_Pin, nChar & 0b00000010);
	HAL_GPIO_WritePin(LCD0_GPIO_Port, LCD0_Pin, nChar & 0b00000001);

	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
//	HAL_Delay(1);
}
*/void LCDchar4(unsigned char nChar)	//	Set character in 4-bit mode.
{
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b10000000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b01000000);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00100000);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00010000);

	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
//	HAL_Delay(1);

	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b00001000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b00000100);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00000010);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00000001);

	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
//	HAL_Delay(1);
}
/*void LCDchar(unsigned char nChar)	//	Set character to LCD in 8-bit mode
{
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, 1);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, 0);
	HAL_GPIO_WritePin(LCD7_GPIO_Port, LCD7_Pin, nChar & 0b10000000);
	HAL_GPIO_WritePin(LCD6_GPIO_Port, LCD6_Pin, nChar & 0b10000000);
	HAL_GPIO_WritePin(LCD5_GPIO_Port, LCD5_Pin, nChar & 0b00100000);
	HAL_GPIO_WritePin(LCD4_GPIO_Port, LCD4_Pin, nChar & 0b00010000);
	HAL_GPIO_WritePin(LCD3_GPIO_Port, LCD3_Pin, nChar & 0b00001000);
	HAL_GPIO_WritePin(LCD2_GPIO_Port, LCD2_Pin, nChar & 0b00000100);
	HAL_GPIO_WritePin(LCD1_GPIO_Port, LCD1_Pin, nChar & 0b00000010);
	HAL_GPIO_WritePin(LCD0_GPIO_Port, LCD0_Pin, nChar & 0b00000001);

	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_SET);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDEN_GPIO_Port, LCDEN_Pin, GPIO_PIN_RESET);
//	HAL_Delay(1);
}*/
