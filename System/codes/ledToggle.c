#include <System.h>
#include <FreeRTOS.h>
#include <queue.h>

void ledToggle(void * data)
{
	struct systemData * lData = (struct systemData *) data;
	struct ledState led;
	xQueuePeek(lData->mb_led,&led,0);
	led.state ^= 1;
	xQueueOverwrite(lData->mb_led,&led);
	vTaskDelay(pdMS_TO_TICKS(50));
}
