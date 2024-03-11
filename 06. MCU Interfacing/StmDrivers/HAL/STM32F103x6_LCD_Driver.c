#include "STM32F103x6_LCD_Driver.h"

/* ============= Global Variable ================= */
GPIO_PinConfig_TypeDef Lcd_PinConfig ;
/* ========================================== */
/* ========== Private Functions ============= */
/* ========================================== */
static void HAL_LCD_KICK(void);

// Function to make delay_ms 1ms
static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}
static void LCD_GPIO_INIT(void)
{
	// ======================= Set CTRL Switches to Output ===================

	// RS_SWITCH is Output with Speed 10 MHz (push-pull) mode
	Lcd_PinConfig.GPIO_PinNumber = RS_SWITCH;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	//RW_SWITCH is Output with Speed 10 MHz (push-pull) mode
	Lcd_PinConfig.GPIO_PinNumber = RW_SWITCH;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	//Enable_SWITCH is Output with Speed 10 MHz (push-pull) mode
	Lcd_PinConfig.GPIO_PinNumber = EN_SWITCH;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	// =================== Set LCD Port to Output with Speed 10 MHz (push-pull) mode ==============
	// SET THE NEXT 8 PINS AS INPUT
	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Lcd_PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	// Reset EN_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_LOW);
	// Reset RS_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	// Reset RW_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);

}

/* ========================================== */
/* ========== Functions Definitions ========= */
/* ========================================== */

// Function to clear screen of LCD
void HAL_LCD_CLEAR_SCREEN(void)
{
	HAL_LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

// Kick Start
static void HAL_LCD_KICK(void)
{
	// Set Enable bit
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_HIGH);

	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	delay_ms(50);

	// Reset Enable bit
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_LOW);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void HAL_LCD_INIT(void)
{

	delay_ms(20);
	LCD_GPIO_INIT();
	delay_ms(15);

	HAL_LCD_CLEAR_SCREEN();

#ifdef EIGHT_BIT_MODE
	HAL_LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02); // As data sheet
	LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
#endif

	HAL_LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
}

// Check if LCD is Busy
void HAL_LCD_ISBUSY(void)
{
	//============== Set Port to Receive Data (input) ===============

    // DataDir_LCD_PORT &= ~(0xFF << DATA_shift);

	// Set next 8 pins as input
	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	Lcd_PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	Lcd_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &Lcd_PinConfig);

	// === Put LCD on read mode ===
	// LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_HIGH);
	// LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	HAL_LCD_KICK();
	// DataDir_LCD_PORT |= (0xFF << DATA_shift);
	// LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
}

// Function to write commands for LCD
void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#ifdef EIGHT_BIT_MODE
/* ====== LCD is in 8 bit Mode ====== */

	// Set LCD Port using command variable
	MCAL_GPIO_WritePort(LCD_CTRL, command);

	// Port Direction is set to Output in LCD_init()

	// Turn RS off for command mode
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);

	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);

	delay_ms(1);
	HAL_LCD_KICK();
#endif

#ifdef FOUR_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */

	delay_ms(15);

	// Send last four bits of command
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	uint8_t temp_cmd;
	temp_cmd = (command & 0xF0);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();

	// Send first four bits of command
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	temp_cmd = (command << 4);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_CHAR(uint8_t character)
{
#ifdef EIGHT_BIT_MODE
	/* ====== LCD is in 8 bit Mode ====== */
	// Turn RS on for data mode
	//MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_HIGH);
	// Set LCD Port using character variable
	MCAL_GPIO_WritePort(LCD_CTRL, character);
	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
	// Turn RS on for data mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_HIGH);
	delay_ms(1);
	HAL_LCD_KICK();
#endif

#ifdef FOUR_BIT_MODE
	/* ====== LCD is in 4 bit Mode ====== */

	delay_ms(15);

	// Send last four bits of command
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	uint8_t temp_cmd;
	temp_cmd = (character & 0xF0);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();

	// Send first four bits of command
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_LOW);
	temp_cmd = (character << 4);
	MCAL_GPIO_WritePort(LCD_CTRL, temp_cmd);
	HAL_LCD_KICK();
#endif

}

void HAL_LCD_WRITE_STRING(char* string)
{
	// Counter to avoid writing bigger word size than LCD screen
	int count = 0;
	while (*string > 0)
	{
		count++;
		HAL_LCD_WRITE_CHAR(*string++);
		if (count == 16) // Counter reached the end of the first row
		{
			HAL_LCD_GOTO_XY(2, 0); // Line : row num 2 , starts from position 0
		} else if (count == 32)
		{
			HAL_LCD_CLEAR_SCREEN();
			HAL_LCD_GOTO_XY(1, 0); // go to line 1 , position 0
			count = 0;
		}
	}
}

/*
void HAL_LCD_custom_characters(void)
{
	HAL_LCD_WRITE_COMMAND(64);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(14);
	HAL_LCD_WRITE_CHAR(17);
	HAL_LCD_WRITE_CHAR(2);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_CHAR(0);
	HAL_LCD_WRITE_CHAR(4);
	HAL_LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_CHAR(0);
	delay_ms(10);
}
*/
