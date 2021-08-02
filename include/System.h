#ifndef SYSTEM_H
#define SYSTEM_H

/* Sistemas de tempo Real  2020.1 - Trabalho 1
 *
 * @autor:Francisco Thiago dos Santos Gonçalves
 * @autor:
 * @autor:
 *
 * data:
 */

#include <FreeRTOS.h>
#include <stdbool.h>
#include <queue.h>
/*------------Definição dos Dados------------*/

//Cor do LED
enum color{verde,vermelho};
struct ledState
{
	bool state;
	enum color led_color;
};

//Sensor
struct sensorData
{
	float sensor1;
	float sensor2;
};

//Key
struct keyPressed
{
	bool readed;
	char key;
};

//Uso da CPU
typedef float cpuUse;

struct LCDData
{
	int n;
	char * data;
};

struct systemData
{
	QueueHandle_t mb_lcd;
	QueueHandle_t mb_cpu;
	QueueHandle_t mb_key;
	QueueHandle_t mb_sensor;
	QueueHandle_t mb_led;
};


/*------------Definição das tasks------------*/
/* @author Thiago
 * nome: controlTask
 * Função:
 * 	Requisitar os dados dos sensores por meio de uma mail box com um dead line de 10ms
 * 	Verificar comandos enviados pela userTask
 *	Atualizar o estado do LED
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	userComand
 * 	sensorData
 * 	ledState
 * 	cpuUse
 */
 void controlTask(void * controlData);

/* nome: ledToggle
 * Função:
 * 	Atualiza o estado (ligado e desligado) e a cor do LED  
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	ledState
 */
 void ledToggle(void * data);

/* @author Pedro
 * nome: userTask
 * Função:
 * 	Espera a entrada do teclado numérico, e atualiza os dados do LCD.
 *	Como não temos um led físico, ele deve mostrar o estado do led
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	ledState
 * 	keyPressed
 * 	LCDData
 */
 void userTask(void * data);

/* @author Pedro
 * nome: taskScanner
 * Função:
 * 	Espera a entrada do teclado numérico e informa
 * 	a userTask
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	keyPressed
 */
 void taskScanner(void * keyPressed);

/* @author Matheus
 * nome: userLCD
 * Função:
 * 	Atualiza o LCD
 * Pa	rametros: Ela deve ter acesso aos seguintes dados
 * 	LCDData
 */
 void taskLCD(void * data);

/* @author Matheus
 * nome: taskSensores
 * Função:
 * 	Atualiza os sensores
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	sensorData
 */
 void taskSensores(void * data);
 void PDA(void * controlData);

/* nome: taskSensores
 * Função:
 * 	Atualiza o uso da CPU
 * Parametros: Ela deve ter acesso aos seguintes dados
 * 	cpuUse
 */
/* @author: Thiago
 *
 * Atualiza o uso da cpu. 
 */
 void monitor(void * data);
#endif
