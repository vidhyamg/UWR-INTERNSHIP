################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Examples/usart_test.c 

OBJS += \
./Examples/usart_test.o 

C_DEPS += \
./Examples/usart_test.d 


# Each subdirectory must supply rules for building sources it contributes
Examples/%.o Examples/%.su Examples/%.cyclo: ../Examples/%.c Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/STM32DriverDev/Drivers" -I"C:/Users/deepu/OneDrive/Documents/STM32Driver/STM32DriverDev/Drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Examples

clean-Examples:
	-$(RM) ./Examples/usart_test.cyclo ./Examples/usart_test.d ./Examples/usart_test.o ./Examples/usart_test.su

.PHONY: clean-Examples

