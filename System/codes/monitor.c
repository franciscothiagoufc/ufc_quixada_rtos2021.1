#include <FreeRTOS.h>
#include <queue.h>
#include <System.h>

TickType_t in_idle = 0;
float percent = 0;

void monitor(void * data)
{
	struct systemData * sData = (struct systemData *) data;
	cpuUse use = 1-(((float)in_idle)/((float)xTaskGetTickCount()));
	xQueueOverwrite(sData->mb_cpu,&use);
}

void vApplicationIdleHook( void )
{
	//printf("%d",(int)in_idle);
	TickType_t current = xTaskGetTickCount();
	in_idle += xTaskGetTickCount() - current;
	
}
