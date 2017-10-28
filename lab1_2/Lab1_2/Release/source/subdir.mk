################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Flash.c \
../source/LED_FRDM-KW40Z.c \
../source/Lab1_2.c \
../source/board.c \
../source/clock_config.c \
../source/mtb.c \
../source/pin_mux.c 

OBJS += \
./source/Flash.o \
./source/LED_FRDM-KW40Z.o \
./source/Lab1_2.o \
./source/board.o \
./source/clock_config.o \
./source/mtb.o \
./source/pin_mux.o 

C_DEPS += \
./source/Flash.d \
./source/LED_FRDM-KW40Z.d \
./source/Lab1_2.d \
./source/board.d \
./source/clock_config.d \
./source/mtb.d \
./source/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -DCPU_MKW41Z512CAT4_cm0plus -DCPU_MKW41Z512CAT4 -D__REDLIB__ -I"D:\RealTimeComp\Lab1_2\source" -I"D:\RealTimeComp\Lab1_2" -I"D:\RealTimeComp\Lab1_2\utilities" -I"D:\RealTimeComp\Lab1_2\startup" -I"D:\RealTimeComp\Lab1_2\drivers" -I"D:\RealTimeComp\Lab1_2\freertos" -I"D:\RealTimeComp\Lab1_2\CMSIS" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


