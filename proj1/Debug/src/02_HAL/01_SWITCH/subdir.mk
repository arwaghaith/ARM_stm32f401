################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/02_HAL/01_SWITCH/SWITCH.c \
../src/02_HAL/01_SWITCH/SWITCH_Cfg.c 

OBJS += \
./src/02_HAL/01_SWITCH/SWITCH.o \
./src/02_HAL/01_SWITCH/SWITCH_Cfg.o 

C_DEPS += \
./src/02_HAL/01_SWITCH/SWITCH.d \
./src/02_HAL/01_SWITCH/SWITCH_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/02_HAL/01_SWITCH/%.o: ../src/02_HAL/01_SWITCH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F407xx -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


