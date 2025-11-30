#include "securec.h"
#include "soc_osal.h"
#include "app_init.h"
#include "common_def.h"
#include "hal_gpio.h"
#include "debug_print.h"
#include "pinctrl.h"
#include "gpio.h"

#define J3_A GPIO_03
#define J3_B GPIO_06
#define J10_A GPIO_07
#define J10_B GPIO_09
#define movetime 1000
#define silenttime 1000


static void initialization(void)
{
    //initialization
    uapi_pin_set_mode(J3_A, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(J3_A, GPIO_DIRECTION_OUTPUT);
    uapi_pin_set_mode(J3_B, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(J3_B, GPIO_DIRECTION_OUTPUT);
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_LOW);
    uapi_pin_set_mode(J10_A, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(J10_A, GPIO_DIRECTION_OUTPUT);
    uapi_pin_set_mode(J10_B, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(J10_B, GPIO_DIRECTION_OUTPUT);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_LOW);
}
static void stop(void)
{
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_LOW);
}

static void move_forward(void)
{
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_LOW);
    osal_msleep(movetime);
    stop();
}

static void move_backward(void)
{
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_LOW);
    osal_msleep(movetime);
    stop();
}
static void turn_left(void)
{
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_LOW);
    osal_msleep(movetime);
    stop();
}
static void turn_right(void)
{
    uapi_gpio_set_val(J3_A, GPIO_LEVEL_HIGH);
    uapi_gpio_set_val(J3_B, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_B, GPIO_LEVEL_LOW);
    uapi_gpio_set_val(J10_A, GPIO_LEVEL_LOW);
    osal_msleep(movetime);
    stop();
}
static int motor_task(const char *arg)
{
    unused(arg);
    initialization();

        while(1)
    {
        move_forward();
        osal_msleep(silenttime);
        move_backward();
        osal_msleep(silenttime);
        stop();
        osal_msleep(silenttime);
        turn_left();
        osal_msleep(silenttime);
        turn_right();
        osal_msleep(silenttime);
    }
    return 0;
}

#define MOTOR_TASK_PRIO 24
#define MOTOR_CLI_STACK_SIZE 0x2000

static void motor_entry(void)
{
    osal_task *task_handle = NULL;

    osal_kthread_lock();
    task_handle = osal_kthread_create((osal_kthread_handler)motor_task, 0, "MOTORClientTask",
                                      MOTOR_CLI_STACK_SIZE);
    if (task_handle != NULL) {
        osal_kthread_set_priority(task_handle, MOTOR_TASK_PRIO);
        osal_kfree(task_handle);
    }
    osal_kthread_unlock();
}

/* Run the example_motor_client_entry. */
app_run(motor_entry);