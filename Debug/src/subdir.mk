################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Engine.cpp \
../src/Entity381.cpp \
../src/Entity3D.cpp \
../src/main.cpp 

OBJS += \
./src/Engine.o \
./src/Entity381.o \
./src/Entity3D.o \
./src/main.o 

CPP_DEPS += \
./src/Engine.d \
./src/Entity381.d \
./src/Entity3D.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/kylebrain/eclipse-workspace/Assignment6/inc" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Mgrs" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Aspects" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Ships" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


