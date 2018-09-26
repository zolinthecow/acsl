################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/fortunate\ numbers.cpp 

OBJS += \
./src/fortunate\ numbers.o 

CPP_DEPS += \
./src/fortunate\ numbers.d 


# Each subdirectory must supply rules for building sources it contributes
src/fortunate\ numbers.o: ../src/fortunate\ numbers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/fortunate numbers.d" -MT"src/fortunate\ numbers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


