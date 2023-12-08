################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/003button_interrupt.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/003button_interrupt.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/003button_interrupt.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F070RBTx -DSTM32 -DSTM32F0 -DNUCLEO_F070RB -c -I../Inc -I"C:/Users/iamna/STM32CubeIDE/workspace_1.14.0/stm32f070xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/003button_interrupt.cyclo ./Src/003button_interrupt.d ./Src/003button_interrupt.o ./Src/003button_interrupt.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

