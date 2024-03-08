################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/%.o Drivers/CMSIS/%.su Drivers/CMSIS/%.cyclo: ../Drivers/CMSIS/%.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_1B_invertir_secuencia_de_leds/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_1B_invertir_secuencia_de_leds/Drivers/CMSIS/Include" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_1B_invertir_secuencia_de_leds/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_1B_invertir_secuencia_de_leds/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_1B_invertir_secuencia_de_leds/Drivers/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32f4xx.cyclo ./Drivers/CMSIS/system_stm32f4xx.d ./Drivers/CMSIS/system_stm32f4xx.o ./Drivers/CMSIS/system_stm32f4xx.su

.PHONY: clean-Drivers-2f-CMSIS

