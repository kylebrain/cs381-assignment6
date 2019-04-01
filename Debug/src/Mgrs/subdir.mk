################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mgrs/EntityMgr.cpp \
../src/Mgrs/GameMgr.cpp \
../src/Mgrs/GfxMgr.cpp \
../src/Mgrs/InputMgr.cpp \
../src/Mgrs/Mgr.cpp 

OBJS += \
./src/Mgrs/EntityMgr.o \
./src/Mgrs/GameMgr.o \
./src/Mgrs/GfxMgr.o \
./src/Mgrs/InputMgr.o \
./src/Mgrs/Mgr.o 

CPP_DEPS += \
./src/Mgrs/EntityMgr.d \
./src/Mgrs/GameMgr.d \
./src/Mgrs/GfxMgr.d \
./src/Mgrs/InputMgr.d \
./src/Mgrs/Mgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/Mgrs/%.o: ../src/Mgrs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/kylebrain/eclipse-workspace/Assignment6/inc" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Mgrs" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Aspects" -I"/home/kylebrain/eclipse-workspace/Assignment6/inc/Ships" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


