################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := SVC_Handler_Arithmetic
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SVC_Handler_Arithmetic.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SVC_Handler_Arithmetic.list \

OBJCOPY_BIN += \
SVC_Handler_Arithmetic.bin \


# All Target
all: main-build

# Main-build Target
main-build: SVC_Handler_Arithmetic.elf secondary-outputs

# Tool invocations
SVC_Handler_Arithmetic.elf: $(OBJS) $(USER_OBJS) F:\Develop_Embedded_Systems\Arm_cortex_m4\SVC_Handler_Arithmetic\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "SVC_Handler_Arithmetic.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\Develop_Embedded_Systems\Arm_cortex_m4\SVC_Handler_Arithmetic\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SVC_Handler_Arithmetic.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SVC_Handler_Arithmetic.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SVC_Handler_Arithmetic.list"
	@echo 'Finished building: $@'
	@echo ' '

SVC_Handler_Arithmetic.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "SVC_Handler_Arithmetic.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
