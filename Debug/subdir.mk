################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AIPlayer.cpp \
../Board.cpp \
../Game.cpp \
../HumanPlayer.cpp \
../Player.cpp \
../RemotePlayer.cpp \
../main.cpp 

O_SRCS += \
../AIPlayer.o \
../Board.o \
../Game.o \
../HumanPlayer.o \
../Player.o \
../RemotePlayer.o \
../main.o 

OBJS += \
./AIPlayer.o \
./Board.o \
./Game.o \
./HumanPlayer.o \
./Player.o \
./RemotePlayer.o \
./main.o 

CPP_DEPS += \
./AIPlayer.d \
./Board.d \
./Game.d \
./HumanPlayer.d \
./Player.d \
./RemotePlayer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


