################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Command.cpp \
../CommandManager.cpp \
../GameServer.cpp \
../JoinCommand.cpp \
../ListGamesCommand.cpp \
../RoomCommand.cpp \
../StartCommand.cpp \
../main.cpp 

OBJS += \
./Command.o \
./CommandManager.o \
./GameServer.o \
./JoinCommand.o \
./ListGamesCommand.o \
./RoomCommand.o \
./StartCommand.o \
./main.o 

CPP_DEPS += \
./Command.d \
./CommandManager.d \
./GameServer.d \
./JoinCommand.d \
./ListGamesCommand.d \
./RoomCommand.d \
./StartCommand.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


