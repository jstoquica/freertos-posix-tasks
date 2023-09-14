#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"

// Task handles for task management
TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t Task3_Handle;

// Function that represents the first task
void Task1(void *pvParameters) {
    for (;;)
    {
        printf("Task 1 is running...\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}

void Task3(void *pvParameters) {
    for (;;)
    {
        printf("Rodando 1 e 2, pagando amabas...\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}

// Function that represents the second task
void StopTask(void *pvParameters) {
    for (;;)
    {
        printf("Ending RTOS kernel...\n");
        // vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 0.5 seconds
        vTaskDelete(Task2_Handle);
        vTaskEndScheduler();
    }
}

// Function that represents the second task
void Task2(void *pvParameters) {
    for (;;)
    {
        printf("Task 2 is running...\n");
        vTaskDelete(Task1_Handle);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 2 seconds
        xTaskCreate(StopTask, "StopTask", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    }
}

int main(void) {
    // Initialize the FreeRTOS kernel
    xTaskCreate(Task1, "Task1", configMINIMAL_STACK_SIZE, NULL, 1, &Task1_Handle);
    xTaskCreate(Task2, "Task2", configMINIMAL_STACK_SIZE, NULL, 1, &Task2_Handle);
    xTaskCreate(Task3, "Task3", configMINIMAL_STACK_SIZE, NULL, 1, &Task3_Handle);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    return 0;
}

