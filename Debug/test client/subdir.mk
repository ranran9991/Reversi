################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test\ client/clientmain.cpp 

OBJS += \
./test\ client/clientmain.o 

CPP_DEPS += \
./test\ client/clientmain.d 


# Each subdirectory must supply rules for building sources it contributes
test\ client/clientmain.o: ../test\ client/clientmain.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"test client/clientmain.d" -MT"test\ client/clientmain.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


