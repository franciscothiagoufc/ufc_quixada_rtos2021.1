#include <System.h>
#include <stdio.h>
void taskScanner(void * keyPressed)
{
	struct systemData * data = (struct systemData *) keyPressed;
	
	struct keyPressed key;
	//fgetc(stdin);

	//key.key = fgetc(stdin);
	
	scanf("%u",&key.key);
	/*if(key.key > 0 && key.key <9)  
	{
		key.key = '1';

	}
	else
		key.key = '0';*/
	xQueueOverwrite(data->mb_key,&key);
	
}
