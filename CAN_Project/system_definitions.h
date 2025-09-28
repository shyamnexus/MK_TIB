#ifndef SYSTEM_DEFINITIONS_H
#define SYSTEM_DEFINITIONS_H

#include "system_config.h"
#include "system/common/sys_module.h"
#include "driver/can/drv_can.h"
#include "driver/gpio/drv_gpio.h"
#include "driver/tmr/drv_tmr.h"
#include "system/tmr/sys_tmr.h"
#include "system/task/sys_tasks.h"

// System state definitions
typedef enum {
    SYSTEM_STATE_INIT,
    SYSTEM_STATE_RUNNING,
    SYSTEM_STATE_ERROR
} SYSTEM_STATE;

// CAN message structure
typedef struct {
    uint32_t id;
    uint8_t data[8];
    uint8_t length;
    bool extended;
} CAN_MESSAGE;

// System data structure
typedef struct {
    SYSTEM_STATE state;
    DRV_HANDLE canHandle;
    CAN_MESSAGE rxMessage;
    CAN_MESSAGE txMessage;
    bool canRxFlag;
    bool canTxFlag;
} SYSTEM_DATA;

extern SYSTEM_DATA sysData;

#endif // SYSTEM_DEFINITIONS_H