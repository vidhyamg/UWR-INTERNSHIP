################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Examples/Usart_tx_test.c 

OBJS += \
./Examples/Usart_tx_test.o 

C_DEPS += \
./Examples/Usart_tx_test.d 


# Each subdirectory must supply rules for building sources it contributes
Examples/Usart_tx_test.o: ../Examples/Usart_tx_test.c Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/src" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/stm32UartDriver/Drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Examples

clean-Examples:
	-$(RM) ./Examples/Usart_tx_test.cyclo ./Examples/Usart_tx_test.d ./Examples/Usart_tx_test.o ./Examples/Usart_tx_test.su

.PHONY: clean-Examples

