################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ReversiServer/Command.cpp \
../ReversiServer/CommandManager.cpp \
../ReversiServer/JoinCommand.cpp \
../ReversiServer/ListGamesCommand.cpp \
../ReversiServer/Room.cpp \
../ReversiServer/RoomCommand.cpp \
../ReversiServer/StartCommand.cpp 

OBJS += \
./ReversiServer/Command.o \
./ReversiServer/CommandManager.o \
./ReversiServer/JoinCommand.o \
./ReversiServer/ListGamesCommand.o \
./ReversiServer/Room.o \
./ReversiServer/RoomCommand.o \
./ReversiServer/StartCommand.o 

CPP_DEPS += \
./ReversiServer/Command.d \
./ReversiServer/CommandManager.d \
./ReversiServer/JoinCommand.d \
./ReversiServer/ListGamesCommand.d \
./ReversiServer/Room.d \
./ReversiServer/RoomCommand.d \
./ReversiServer/StartCommand.d 


# Each subdirectory must supply rules for building sources it contributes
ReversiServer/%.o: ../ReversiServer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


