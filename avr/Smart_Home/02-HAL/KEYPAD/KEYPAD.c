#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "KEYPAD.h"

static const u8 ROWS[ROWS_NUMBER]={
		KEYPAD_ROW0,
		KEYPAD_ROW1,
		KEYPAD_ROW2,
		KEYPAD_ROW3
};

static const u8 COLUMS[COLUMS_NUMBER]={
		KEYPAD_COLUM0,
		KEYPAD_COLUM1,
		KEYPAD_COLUM2,
		KEYPAD_COLUM3
};



static const u8 KEYS[ROWS_NUMBER][COLUMS_NUMBER]={
		{'7','8','9', '/'},
		{'4','5','6', '*'},
		{'1','2','3', '-'},
		{'N','0','=', '+'}
};



void KEYPAD_voidini (void){
	SET_BIT(KEYPAD_DDR,KEYPAD_ROW0);
	SET_BIT(KEYPAD_DDR,KEYPAD_ROW1);
	SET_BIT(KEYPAD_DDR,KEYPAD_ROW2);
	SET_BIT(KEYPAD_DDR,KEYPAD_ROW3);

	CLR_BIT(KEYPAD_DDR,KEYPAD_COLUM0);
	CLR_BIT(KEYPAD_DDR,KEYPAD_COLUM1);
	CLR_BIT(KEYPAD_DDR,KEYPAD_COLUM2);
	CLR_BIT(KEYPAD_DDR,KEYPAD_COLUM3);

	KEYPAD_PORT=0xFF;
}

u8 KEYPAD_u8Scan (void){
	u8 Local_u8RowsCounter=0;
	u8 Local_u8ColumnCounter=0;
	u8 Local_u8PressedKey='\0';
	for(Local_u8RowsCounter=0;Local_u8RowsCounter<ROWS_NUMBER;Local_u8RowsCounter++){
			CLR_BIT(KEYPAD_PORT,ROWS[Local_u8RowsCounter]); //active ROW
			for(Local_u8ColumnCounter=0;Local_u8ColumnCounter<COLUMS_NUMBER;Local_u8ColumnCounter++){
				if(GET_BIT(KEYPAD_PIN,COLUMS[Local_u8ColumnCounter])==0){
					Local_u8PressedKey=KEYS[Local_u8RowsCounter][Local_u8ColumnCounter];
					_delay_ms(10);//debouncing
					//while(GET_BIT(KEYPAD_PIN,COLUMS[Local_u8ColumnCounter])==0);
				}
				else{
				}
			}

			SET_BIT(KEYPAD_PORT,ROWS[Local_u8RowsCounter]); //deactive ROW

	}

	return Local_u8PressedKey;

}



u8 KEYPAD_u8ScanWithStop (void){
	u8 Local_u8RowsCounter=0;
	u8 Local_u8ColumnCounter=0;
	u8 Local_u8PressedKey='\0';
	for(Local_u8RowsCounter=0;Local_u8RowsCounter<ROWS_NUMBER;Local_u8RowsCounter++){
		CLR_BIT(KEYPAD_PORT,ROWS[Local_u8RowsCounter]); //active ROW
		for(Local_u8ColumnCounter=0;Local_u8ColumnCounter<COLUMS_NUMBER;Local_u8ColumnCounter++){
			if(GET_BIT(KEYPAD_PIN,COLUMS[Local_u8ColumnCounter])==0){
				Local_u8PressedKey=KEYS[Local_u8RowsCounter][Local_u8ColumnCounter];
				_delay_ms(10);//debouncing
				while(GET_BIT(KEYPAD_PIN,COLUMS[Local_u8ColumnCounter])==0);
			}
			else{
			}
		}
		SET_BIT(KEYPAD_PORT,ROWS[Local_u8RowsCounter]); //deactive ROW
	}
	return Local_u8PressedKey;
}
