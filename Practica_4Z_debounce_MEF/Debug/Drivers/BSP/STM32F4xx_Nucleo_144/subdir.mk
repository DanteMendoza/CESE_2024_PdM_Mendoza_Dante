################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.c 

OBJS += \
./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o 

C_DEPS += \
./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F4xx_Nucleo_144/%.o Drivers/BSP/STM32F4xx_Nucleo_144/%.su Drivers/BSP/STM32F4xx_Nucleo_144/%.cyclo: ../Drivers/BSP/STM32F4xx_Nucleo_144/%.c Drivers/BSP/STM32F4xx_Nucleo_144/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/CMSIS/Include" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/Core/Inc" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/API/Inc" -I"C:/Proyectos/STM32CubeIDE/CESE_2024_PdM_Mendoza_Dante/Practica_4Z_debounce_MEF/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F4xx_Nucleo_144

clean-Drivers-2f-BSP-2f-STM32F4xx_Nucleo_144:
	-$(RM) ./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.cyclo ./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.d ./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o ./Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32F4xx_Nucleo_144
