################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ships/Alien.cpp \
../src/Ships/Banshee.cpp \
../src/Ships/Carrier.cpp \
../src/Ships/Destroyer.cpp \
../src/Ships/Frigate.cpp \
../src/Ships/Speedboat.cpp 

OBJS += \
./src/Ships/Alien.o \
./src/Ships/Banshee.o \
./src/Ships/Carrier.o \
./src/Ships/Destroyer.o \
./src/Ships/Frigate.o \
./src/Ships/Speedboat.o 

CPP_DEPS += \
./src/Ships/Alien.d \
./src/Ships/Banshee.d \
./src/Ships/Carrier.d \
./src/Ships/Destroyer.d \
./src/Ships/Frigate.d \
./src/Ships/Speedboat.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ships/%.o: ../src/Ships/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I"/home/garrettmoore/Documents/Assignment6/cs381-assignment6/inc" -I"/home/garrettmoore/Documents/Assignment6/cs381-assignment6/inc/Aspects" -I"/home/garrettmoore/Documents/Assignment6/cs381-assignment6/inc/Mgrs" -I"/home/garrettmoore/Documents/Assignment6/cs381-assignment6/inc/Ships" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


