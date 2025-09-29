################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Device_Startup/ \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/sam/ \
../src/ASF/sam/drivers/ \
../src/ASF/sam/drivers/can/ \
../src/ASF/sam/drivers/pmc/ \
../src/ASF/sam/utils/ \
../src/ASF/sam/utils/cmsis/ \
../src/ASF/sam/utils/cmsis/sam4e/ \
../src/ASF/sam/utils/cmsis/sam4e/include/ \
../src/ASF/sam/utils/cmsis/sam4e/include/component/ \
../src/ASF/sam/utils/cmsis/sam4e/include/instance/ \
../src/ASF/sam/utils/cmsis/sam4e/include/pio/ \
../src/ASF/sam/utils/cmsis/sam4e/source/ \
../src/ASF/sam/utils/cmsis/sam4e/source/templates/ \
../src/ASF/sam/utils/cmsis/sam4e/source/templates/gcc/ \
../src/ASF/sam/utils/fpu/ \
../src/ASF/sam/utils/header_files/ \
../src/ASF/sam/utils/make/ \
../src/ASF/sam/utils/preprocessor/ \
../src/ASF/sam/utils/syscalls/ \
../src/ASF/sam/utils/syscalls/gcc/ \
../src/ASF/thirdparty/ \
../src/ASF/thirdparty/CMSIS/ \
../src/ASF/thirdparty/CMSIS/Include/ \
../src/ASF/thirdparty/CMSIS/Lib/ \
../src/ASF/thirdparty/CMSIS/Lib/GCC/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Device_Startup/startup_sam4e.c \
../Device_Startup/system_sam4e.c \
../main.c \
../src/ASF/sam/utils/syscalls/gcc/syscalls.c \
../src/ASF/common/utils/interrupt/interrupt_sam_nvic.c \
../src/ASF/sam/drivers/can/can.c \
../src/ASF/sam/drivers/pmc/pmc.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Device_Startup/startup_sam4e.o \
Device_Startup/system_sam4e.o \
main.o \
src/ASF/sam/utils/syscalls/gcc/syscalls.o \
src/ASF/common/utils/interrupt/interrupt_sam_nvic.o \
src/ASF/sam/drivers/can/can.o \
src/ASF/sam/drivers/pmc/pmc.o

OBJS_AS_ARGS +=  \
Device_Startup/startup_sam4e.o \
Device_Startup/system_sam4e.o \
main.o \
src/ASF/sam/utils/syscalls/gcc/syscalls.o \
src/ASF/common/utils/interrupt/interrupt_sam_nvic.o \
src/ASF/sam/drivers/can/can.o \
src/ASF/sam/drivers/pmc/pmc.o

C_DEPS +=  \
Device_Startup/startup_sam4e.d \
Device_Startup/system_sam4e.d \
main.d \
src/ASF/sam/utils/syscalls/gcc/syscalls.d \
src/ASF/common/utils/interrupt/interrupt_sam_nvic.d \
src/ASF/sam/drivers/can/can.d \
src/ASF/sam/drivers/pmc/pmc.d

C_DEPS_AS_ARGS +=  \
Device_Startup/startup_sam4e.d \
Device_Startup/system_sam4e.d \
main.d \
src/ASF/sam/utils/syscalls/gcc/syscalls.d \
src/ASF/common/utils/interrupt/interrupt_sam_nvic.d \
src/ASF/sam/drivers/can/can.d \
src/ASF/sam/drivers/pmc/pmc.d

OUTPUT_FILE_PATH +=GccApplication1.elf

OUTPUT_FILE_PATH_AS_ARGS +=GccApplication1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+=  \
../Device_Startup/sam4e8c_flash.ld \
../Device_Startup/sam4e8c_sram.ld \
../Device_Startup/sam4e_flash.ld \
../Device_Startup/sam4e_sram.ld


# AVR32/GNU C Compiler
Device_Startup/startup_sam4e.o: ../Device_Startup/startup_sam4e.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Device_Startup/system_sam4e.o: ../Device_Startup/system_sam4e.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/sam/utils/syscalls/gcc/syscalls.o: ../src/ASF/sam/utils/syscalls/gcc/syscalls.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/utils/interrupt/interrupt_sam_nvic.o: ../src/ASF/common/utils/interrupt/interrupt_sam_nvic.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/sam/drivers/can/can.o \
src/ASF/sam/drivers/pmc/pmc.o: ../src/ASF/sam/drivers/can/can.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAM4E8C__ -DDEBUG -Dprintf=iprintf -Dscanf=iscanf -DARM_MATH_CM4=true  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAM4E_DFP\1.1.57\ic.sam4e\include" -I"../src/ASF/common/boards" -I"../src/ASF/sam/drivers/can" -I"../src/ASF/sam/drivers/pmc" -I"../src/ASF/common/utils" -I"../src/ASF/sam/utils" -I"../src/ASF/sam/utils/header_files" -I"../src/ASF/sam/utils/fpu" -I"../src/ASF/sam/utils/cmsis/sam4e/include" -I"../src/ASF/sam/utils/cmsis/sam4e/source/templates" -I"../src/ASF/sam/utils/preprocessor" -I"../src/ASF/thirdparty/CMSIS/Include" -I"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m4 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,-Map="GccApplication1.map" -Wl,--start-group -larm_cortexM4lf_math_softfp -lm  -Wl,--end-group -L"..\\Device_Startup" -L"../src/ASF/thirdparty/CMSIS/Lib/GCC"  -Wl,--gc-sections -mcpu=cortex-m4 -Tsam4e8c_flash.ld  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "GccApplication1.elf" "GccApplication1.bin"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "GccApplication1.elf" "GccApplication1.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O binary "GccApplication1.elf" "GccApplication1.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objdump.exe" -h -S "GccApplication1.elf" > "GccApplication1.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "GccApplication1.elf" "GccApplication1.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "GccApplication1.elf"
	
	






# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "GccApplication1.elf" "GccApplication1.a" "GccApplication1.hex" "GccApplication1.bin" "GccApplication1.lss" "GccApplication1.eep" "GccApplication1.map" "GccApplication1.srec"
	