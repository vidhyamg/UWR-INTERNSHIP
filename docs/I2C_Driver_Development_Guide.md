# STM32F401RE I2C Driver Development Guide

## 1. Introduction

The I2C driver provides the software interface for configuring the STM32F401RE I2C peripheral.

The current implementation includes:

- I2C peripheral clock control
- I2C initialization
- I2C de-initialization
- SCL speed configuration
- Device own-address configuration
- ACK control
- Fast-mode duty-cycle configuration
- Clock calculation using RCC PCLK1

---

## 2. I2C Configuration Structure

The driver uses `I2C_Config_t`.

| Parameter | Description |
|---|---|
| `I2C_SCLSpeed` | I2C SCL clock speed |
| `I2C_DeviceAddress` | Device own address |
| `I2C_AckControl` | ACK enable/disable |
| `I2C_FMDutyCycle` | Fast-mode duty cycle |

---

## 3. I2C Handle

```c
typedef struct
{
    I2C_RegDef_t *pI2Cx;
    I2C_Config_t I2C_Config;
} I2C_Handle_t;
```

The handle stores:

- I2C peripheral address
- I2C configuration

---

## 4. I2C SCL Speeds

The driver defines:

```c
I2C_SCL_SPEED_SM   100000
I2C_SCL_SPEED_FM4K 400000
I2C_SCL_SPEED_FM2K 200000
```

### Standard Mode

```text
100 kHz
```

### Fast Mode

```text
200 kHz
400 kHz
```

---

## 5. ACK Control

```c
I2C_ACK_ENABLE
I2C_ACK_DISABLE
```

ACK determines whether the I2C peripheral acknowledges received data.

---

## 6. Fast-Mode Duty Cycle

```c
I2C_FM_DUTY_2
I2C_FM_DUTY_16_9
```

These settings control the relationship between the high and low periods of the SCL signal in fast mode.

---

## 7. Peripheral Clock Control

```c
void I2C_PeriClockControl(
    I2C_RegDef_t *pI2Cx,
    uint8_t EnorDi
);
```

The implementation supports:

```text
I2C1
I2C2
I2C3
```

The clock is enabled or disabled using the corresponding RCC peripheral-clock macros.

---

## 8. I2C Initialization

```c
void I2C_Init(I2C_Handle_t *pI2CHandle);
```

The initialization sequence currently performs:

```text
Enable I2C peripheral clock
        |
        v
Configure ACK
        |
        v
Configure CR2 FREQ field
        |
        v
Configure own device address
        |
        v
Calculate CCR
        |
        v
Configure TRISE
```

---

## 9. PCLK1 Dependency

The I2C peripheral uses APB1.

The driver obtains the APB1 clock through:

```c
RCC_GetPCLK1Value();
```

The returned value is used to calculate the I2C timing registers.

---

## 10. Standard Mode CCR Calculation

For standard mode, the current implementation calculates:

```text
CCR = PCLK1 / (2 × SCL_Speed)
```

The calculated value is written to the I2C CCR register.

---

## 11. Fast Mode CCR Calculation

For fast mode, the driver sets the fast-mode bit and selects the duty cycle.

For duty cycle 2:

```text
CCR = PCLK1 / (3 × SCL_Speed)
```

For duty cycle 16/9:

```text
CCR = PCLK1 / (25 × SCL_Speed)
```

---

## 12. I2C De-Initialization

```c
void I2C_DeInit(I2C_RegDef_t *pI2Cx);
```

This API is intended to reset the selected I2C peripheral.

---

## 13. Example Configuration

```c
I2C_Handle_t I2C1Handle;

I2C1Handle.pI2Cx = I2C1;

I2C1Handle.I2C_Config.I2C_SCLSpeed =
    I2C_SCL_SPEED_SM;

I2C1Handle.I2C_Config.I2C_DeviceAddress = 0x61;

I2C1Handle.I2C_Config.I2C_AckControl =
    I2C_ACK_ENABLE;

I2C1Handle.I2C_Config.I2C_FMDutyCycle =
    I2C_FM_DUTY_2;

I2C_Init(&I2C1Handle);
```

---

## 14. Driver Status

The current header contains the master transmit/receive APIs as commented declarations. These can be documented and implemented when the data-transfer portion of the driver is added.

---

## 15. Summary

The I2C driver provides the configuration and timing foundation for STM32F401RE I2C communication. It depends on the RCC driver for the APB1 peripheral-clock frequency.
