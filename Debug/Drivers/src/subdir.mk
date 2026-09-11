################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/stm32f401_GpioDriver.c \
../Drivers/src/stm32f401_RccDriver.c \
../Drivers/src/stm32f401_UsartDriver.c 

OBJS += \
./Drivers/src/stm32f401_GpioDriver.o \
./Drivers/src/stm32f401_RccDriver.o \
./Drivers/src/stm32f401_UsartDriver.o 

C_DEPS += \
./Drivers/src/stm32f401_GpioDriver.d \
./Drivers/src/stm32f401_RccDriver.d \
./Drivers/src/stm32f401_UsartDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o Drivers/src/%.su Drivers/src/%.cyclo: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/inc" -I../Drivers/inc -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/src/stm32f401_RccDriver.o: ../Drivers/src/stm32f401_RccDriver.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/inc" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/src" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/src/stm32f401_UsartDriver.o: ../Drivers/src/stm32f401_UsartDriver.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/inc" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/src" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/stm32f401_GpioDriver.cyclo ./Drivers/src/stm32f401_GpioDriver.d ./Drivers/src/stm32f401_GpioDriver.o ./Drivers/src/stm32f401_GpioDriver.su ./Drivers/src/stm32f401_RccDriver.cyclo ./Drivers/src/stm32f401_RccDriver.d ./Drivers/src/stm32f401_RccDriver.o ./Drivers/src/stm32f401_RccDriver.su ./Drivers/src/stm32f401_UsartDriver.cyclo ./Drivers/src/stm32f401_UsartDriver.d ./Drivers/src/stm32f401_UsartDriver.o ./Drivers/src/stm32f401_UsartDriver.su

.PHONY: clean-Drivers-2f-src

