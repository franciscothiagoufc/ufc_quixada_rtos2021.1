#include <System.h>
#include <stdlib.h>
#include <time.h>

void taskSensores(void *data)
{
	struct systemData *mb = (struct systemData *)data;
	struct sensorData sensors;

	xQueuePeek(mb->mb_sensor, &sensors, pdMS_TO_TICKS(1));

	srand(time(0));
	sensors.sensor1 = rand() % 100;
	sensors.sensor2 = rand() % 100;

	xQueueOverwrite(mb->mb_sensor, &sensors);
}
