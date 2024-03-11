
#include "STM32F103x6_Keypad_Driver.h"
GPIO_PinConfig_TypeDef KeypadpinConfig ;
void Delay(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}
static uint16_t Keypad_Row_Pins[] = {KEYPAD_ROW0,KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3};
static uint16_t Keypad_Col_Pins[] = {KEYPAD_COL0,KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3};

/**================================================================
* @Fn            -HAL_Keypad_INIT
* @brief         -Initializes the keypad by configuring the row pins as inputs with pull-up resistors
*                 and the column pins as outputs set to a high state initially. This setup prepares
*                 the keypad for detecting key presses.
* @param         -None
* @retval        -None
* Note           -This function must be called before attempting to read key presses. It configures
*                 the necessary GPIO pins connected to the keypad matrix.
*/
void HAL_Keypad_INIT() {
    // Initialize column pins as output and set them to HIGH

	KeypadpinConfig.GPIO_PinNumber = KEYPAD_COL0;
	KeypadpinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeypadpinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);
	MCAL_GPIO_INIT(KEYPAD_DATA_PORT , &KeypadpinConfig);
	MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, KEYPAD_COL0, GPIO_PIN_HIGH);

	KeypadpinConfig.GPIO_PinNumber = KEYPAD_COL1;
	KeypadpinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeypadpinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);
	MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, KEYPAD_COL1, GPIO_PIN_HIGH);

	KeypadpinConfig.GPIO_PinNumber = KEYPAD_COL2;
	KeypadpinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeypadpinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);
	MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, KEYPAD_COL2, GPIO_PIN_HIGH);

	KeypadpinConfig.GPIO_PinNumber = KEYPAD_COL3;
	KeypadpinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeypadpinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);
	MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, KEYPAD_COL3, GPIO_PIN_HIGH);


    // Initialize row pins as input with pull-up
    KeypadpinConfig.GPIO_PinNumber = KEYPAD_ROW0;
    KeypadpinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
    MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);

    KeypadpinConfig.GPIO_PinNumber = KEYPAD_ROW1;
    KeypadpinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
    MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);

    KeypadpinConfig.GPIO_PinNumber = KEYPAD_ROW2;
    KeypadpinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
    MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);

    KeypadpinConfig.GPIO_PinNumber = KEYPAD_ROW3;
    KeypadpinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
    MCAL_GPIO_INIT(KEYPAD_DATA_PORT, &KeypadpinConfig);
}

/**================================================================
* @Fn            -HAL_Keypad_getCh
* @brief         -Scans the keypad for any pressed keys and returns the character corresponding to the key.
*                 It sets each column to low one by one and checks each row for a low state, indicating a button press.
*                 This function implements a simple debouncing mechanism by waiting for the key to be released.
* @param         -None
* @retval        -The character corresponding to the pressed key. Returns '$' if no key is pressed.
* Note           -This function relies on the keypad initialization done by HAL_Keypad_INIT(). It must be called
*                 in a loop to continuously check for key presses. The function maps each key press to a predefined
*                 character based on the keypad layout.
*/
uint8_t HAL_Keypad_getCh()
{
    for (uint8_t col = 0; col < 4; col++) {
        // Set current column to LOW
        MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, Keypad_Col_Pins[col], GPIO_PIN_LOW);
        for (uint8_t row = 0; row < 4; row++) {
            // Check if button is pressed
            if (MCAL_GPIO_ReadPin(KEYPAD_DATA_PORT, Keypad_Row_Pins[row]) == GPIO_PIN_LOW) {
                // Wait for button release (debouncing)
                while (MCAL_GPIO_ReadPin(KEYPAD_DATA_PORT, Keypad_Row_Pins[row]) == GPIO_PIN_LOW);

                // Return the pressed key
                return Keypad_Character[row][col];
            }
        }
        // Reset the current column to HIGH before moving to the next column
        MCAL_GPIO_WritePin(KEYPAD_DATA_PORT, Keypad_Col_Pins[col], GPIO_PIN_HIGH);
    }
    // Indicate no key pressed
    return '$';
}

