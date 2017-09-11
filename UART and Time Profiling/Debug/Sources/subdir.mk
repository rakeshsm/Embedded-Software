################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/cbuffer.c \
../Sources/data.c \
../Sources/led.c \
../Sources/logger.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/nvic.c \
../Sources/profiler.c \
../Sources/uart.c 

OBJS += \
./Sources/cbuffer.o \
./Sources/data.o \
./Sources/led.o \
./Sources/logger.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/nvic.o \
./Sources/profiler.o \
./Sources/uart.o 

C_DEPS += \
./Sources/cbuffer.d \
./Sources/data.d \
./Sources/led.d \
./Sources/logger.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/nvic.d \
./Sources/profiler.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


