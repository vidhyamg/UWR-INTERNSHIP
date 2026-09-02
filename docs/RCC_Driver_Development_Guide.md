# STM32F401RE RCC Driver Development Guide

## 1. Introduction

The RCC (Reset and Clock Control) driver provides functions for determining the clock frequencies supplied to the APB1 and APB2 peripheral buses and for obtaining the PLL output clock.

The current driver provides:

- APB1 peripheral clock calculation
- APB2 peripheral clock calculation
- PLL output clock interface

---

## 2. Clock Tree Concept

```text
Clock Source
     |
     v
System Clock
     |
     v
AHB Prescaler
     |
     +--------------------+
     |                    |
     v                    v
   HCLK                AHB peripherals
     |
     +--------------------+
     |
     v
APB1 Prescaler ----> PCLK1
     |
     +--> APB1 peripherals

System Clock
     |
     v
AHB Prescaler
     |
     v
APB2 Prescaler ----> PCLK2
     |
     +--> APB2 peripherals
```

---

## 3. Public APIs

```c
uint32_t RCC_GetPCLK1Value(void);

uint32_t RCC_GetPCLK2Value(void);

uint32_t RCC_GetPLLOutputClock(void);
```

---

## 4. AHB Prescaler

The driver uses the following AHB prescaler values:

```c
{2, 4, 8, 16, 64, 128, 256, 512}
```

When the AHB prescaler field indicates no division, the driver uses:

```c
ahbp = 1;
```

Therefore:

```text
HCLK = SystemClock / AHB_Prescaler
```

---

## 5. APB1 Clock

The driver reads the APB1 prescaler field from `RCC->CFGR`.

If the field indicates no division:

```c
apb1p = 1;
```

Otherwise, the corresponding value is selected from:

```c
{2, 4, 8, 16}
```

The PCLK1 calculation is:

```text
PCLK1 = SystemClock / AHB_Prescaler / APB1_Prescaler
```

---

## 6. APB2 Clock

The APB2 calculation follows the same principle:

```text
PCLK2 = SystemClock / AHB_Prescaler / APB2_Prescaler
```

The APB2 prescaler values are also selected from the prescaler table.

---

## 7. Clock Source

The current implementation checks the clock-source selection in `RCC->CFGR`.

The implementation currently handles:

- HSI: 16 MHz
- HSE: 8 MHz
- PLL: obtained through `RCC_GetPLLOutputClock()`

The current PLL function is a placeholder and returns zero until PLL calculation is implemented.

---

## 8. Example

If:

```text
SystemClock = 16 MHz
AHB Prescaler = 1
APB1 Prescaler = 1
```

then:

```text
PCLK1 = 16 MHz / 1 / 1
      = 16 MHz
```

---

## 9. Relationship with Other Drivers

The RCC driver is used by peripheral drivers that need an accurate peripheral clock.

For example, the I2C driver uses:

```c
RCC_GetPCLK1Value();
```

The USART driver uses APB1 or APB2 depending on the selected USART peripheral.

---

## 10. Summary

The RCC driver provides the clock-frequency information required by higher-level peripheral drivers. Correct clock calculation is essential for peripherals such as USART and I2C because their timing calculations depend on the peripheral clock.
