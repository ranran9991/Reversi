################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tests/gtest-all.cc 

CPP_SRCS += \
../tests/AllTests.cpp \
../tests/boardTest.cpp \
../tests/gameTest.cpp 

CC_DEPS += \
./tests/gtest-all.d 

OBJS += \
./tests/AllTests.o \
./tests/boardTest.o \
./tests/gameTest.o \
./tests/gtest-all.o 

CPP_DEPS += \
./tests/AllTests.d \
./tests/boardTest.d \
./tests/gameTest.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

tests/%.o: ../tests/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


