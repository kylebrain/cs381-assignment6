################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspects/AI.cpp \
../src/Aspects/Aspect.cpp \
../src/Aspects/Physics.cpp \
../src/Aspects/Physics3D.cpp \
../src/Aspects/Renderable.cpp 

OBJS += \
./src/Aspects/AI.o \
./src/Aspects/Aspect.o \
./src/Aspects/Physics.o \
./src/Aspects/Physics3D.o \
./src/Aspects/Renderable.o 

CPP_DEPS += \
./src/Aspects/AI.d \
./src/Aspects/Aspect.d \
./src/Aspects/Physics.d \
./src/Aspects/Physics3D.d \
./src/Aspects/Renderable.d 


# Each subdirectory must supply rules for building sources it contributes
src/Aspects/%.o: ../src/Aspects/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/kylebrain/eclipse-workspace/Assignment6/inc" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Mgrs" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Aspects" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Ships" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


