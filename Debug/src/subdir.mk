################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ballctrl.c \
../src/paddlectrl.c \
../src/paddlectrl2.c \
../src/pong.c \
../src/timeTracker.c 

OBJS += \
./src/ballctrl.o \
./src/paddlectrl.o \
./src/paddlectrl2.o \
./src/pong.o \
./src/timeTracker.o 

C_DEPS += \
./src/ballctrl.d \
./src/paddlectrl.d \
./src/paddlectrl2.d \
./src/pong.d \
./src/timeTracker.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


