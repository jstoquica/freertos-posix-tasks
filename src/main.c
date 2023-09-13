/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t Task3_Handle;
TaskHandle_t TaskStopKernel_Handle;

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);
void vTaskStopKernel(void *pvParameters);

int main(void)
{
	xTaskCreate(&vTask1,						/** tarefa ou função a ser executada */
				"Task jonatas testando kernel", /** nome da tarefa ou função */
				configMINIMAL_STACK_SIZE,		/** tamanho da pilha  */
				NULL,							/** parametro de entrada */
				1,								/** prioridade da tarefa */
				&Task1_Handle					/** identificador da tarefa */
	);
	xTaskCreate(&vTask2, "kernel foi", configMINIMAL_STACK_SIZE, NULL, 1, &Task2_Handle);
	xTaskCreate(&vTask3, "tudo ok", configMINIMAL_STACK_SIZE, NULL, 1, &Task3_Handle);

	vTaskStartScheduler(); /** inicia o agendador de tarefas */

	return 0;
}

void vTask1(void *pvParameters)
{
	for (;;)
	{
		printf("Task jonatas testando kernel\r\n");
		vTaskDelay(pdMS_TO_TICKS(2000));
	}
}

void vTask2(void *pvParameters)
{
	int i = 0;
	for (;;)
	{
		printf("Task kernel esta funcionando\r\n");
		vTaskDelay(pdMS_TO_TICKS(2000));
		if (i == 2)
		{
			vTaskResume(Task3_Handle);
		}
		if (i == 6)
		{
			xTaskCreate(&vTaskStopKernel, "finalizado", configMINIMAL_STACK_SIZE, NULL, 1, &TaskStopKernel_Handle);
		}
		i++;
	}
}

void vTask3(void *pvParameters)
{
	for (;;)
	{
		printf("tudo ok\r\n");
		vTaskDelay(pdMS_TO_TICKS(2000));
		vTaskSuspend(Task3_Handle);
	}
}

void vTaskStopKernel(void *pvParameters)
{
	printf("finalizado\r\n");
	vTaskDelete(Task1_Handle);
	vTaskDelete(Task2_Handle);
	vTaskDelete(Task3_Handle);
	vTaskEndScheduler(); /** Encerra o agendador de tarefas */
}