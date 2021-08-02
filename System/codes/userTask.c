#include <System.h>

char * lcdMsg_pressed = "Botão pressionado\n";
char * lcdMsg_npressed = "";

void userTask(void * data){
    struct systemData * userData = (struct systemData *) data;

    // Pegando o estado do led:
	struct ledState led;
	xQueuePeek(userData->mb_led,&led,0);

    // Pegando o valor do teclado:
    struct keyPressed key;
    xQueuePeek(userData->mb_key,&key,0);

    // Escrevendo no LCD:
    struct LCDData LCD;
    xQueuePeek(userData->mb_lcd,&LCD,0);
    
    //xSchedulerSporadicJobCreate(taskLCD,"taskLcd",data,pdMS_TO_TICKS(10),pdMS_TO_TICKS(5));

    if(key.key > 0 && key.key <= 9 ){
        TaskHandle_t handler;
	//key.key='0';
        LCD.data = lcdMsg_pressed;
        xQueueOverwrite(userData->mb_key, &key);
        xQueueOverwrite(userData->mb_lcd, &LCD); 
    }
    else
    {
	//LCD.data = lcdMsg_npressed;
        xQueueOverwrite(userData->mb_key, &key);
        xQueueOverwrite(userData->mb_lcd, &LCD); 

    }

   


	

}
