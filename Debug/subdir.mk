################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Board.cpp \
../Board_test.cpp \
../Game.cpp \
../Game_test.cpp \
../Player.cpp \
../Player_test.cpp \
../main.cpp 

OBJS += \
./Board.o \
./Board_test.o \
./Game.o \
./Game_test.o \
./Player.o \
./Player_test.o \
./main.o 

CPP_DEPS += \
./Board.d \
./Board_test.d \
./Game.d \
./Game_test.d \
./Player.d \
./Player_test.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


