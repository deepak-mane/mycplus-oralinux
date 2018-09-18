################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HelloWorldNthTime.cpp \
../src/Logger.cpp \
../src/main.cpp 

OBJS += \
./src/HelloWorldNthTime.o \
./src/Logger.o \
./src/main.o 

CPP_DEPS += \
./src/HelloWorldNthTime.d \
./src/Logger.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


