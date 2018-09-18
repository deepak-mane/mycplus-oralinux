################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common.cpp \
../diskfree.cpp \
../issue.cpp \
../main.cpp \
../module.cpp \
../server.cpp \
../time.cpp 

OBJS += \
./common.o \
./diskfree.o \
./issue.o \
./main.o \
./module.o \
./server.o \
./time.o 

CPP_DEPS += \
./common.d \
./diskfree.d \
./issue.d \
./main.d \
./module.d \
./server.d \
./time.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


