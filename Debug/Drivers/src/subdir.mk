################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/stm32f401xe_gpio.c \
../Drivers/src/stm32f401xe_rcc.c \
../Drivers/src/stm32f401xe_usart.c 

OBJS += \
./Drivers/src/stm32f401xe_gpio.o \
./Drivers/src/stm32f401xe_rcc.o \
./Drivers/src/stm32f401xe_usart.o 

C_DEPS += \
./Drivers/src/stm32f401xe_gpio.d \
./Drivers/src/stm32f401xe_rcc.d \
./Drivers/src/stm32f401xe_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o Drivers/src/%.su Drivers/src/%.cyclo: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/STM32DriverDev/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/STM32DriverDev/Drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/stm32f401xe_gpio.cyclo ./Drivers/src/stm32f401xe_gpio.d ./Drivers/src/stm32f401xe_gpio.o ./Drivers/src/stm32f401xe_gpio.su ./Drivers/src/stm32f401xe_rcc.cyclo ./Drivers/src/stm32f401xe_rcc.d ./Drivers/src/stm32f401xe_rcc.o ./Drivers/src/stm32f401xe_rcc.su ./Drivers/src/stm32f401xe_usart.cyclo ./Drivers/src/stm32f401xe_usart.d ./Drivers/src/stm32f401xe_usart.o ./Drivers/src/stm32f401xe_usart.su

.PHONY: clean-Drivers-2f-src

