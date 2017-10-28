################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MKW41Z4.c 

OBJS += \
./CMSIS/system_MKW41Z4.o 

C_DEPS += \
./CMSIS/system_MKW41Z4.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -DCPU_MKW41Z512CAT4_cm0plus -DCPU_MKW41Z512CAT4 -D__REDLIB__ -I"D:\RealTimeComp\Lab1_2\source" -I"D:\RealTimeComp\Lab1_2" -I"D:\RealTimeComp\Lab1_2\utilities" -I"D:\RealTimeComp\Lab1_2\startup" -I"D:\RealTimeComp\Lab1_2\drivers" -I"D:\RealTimeComp\Lab1_2\freertos" -I"D:\RealTimeComp\Lab1_2\CMSIS" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


