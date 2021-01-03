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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Divide_by_zero.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Divide_by_zero.list \


# All Target
all: Divide_by_zero.elf secondary-outputs

# Tool invocations
Divide_by_zero.elf: $(OBJS) $(USER_OBJS) F:\Develop_Embedded_Systems\Arm_cortex_m4\Inline_assembly\Divide_by_zero\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "Divide_by_zero.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\Develop_Embedded_Systems\Arm_cortex_m4\Inline_assembly\Divide_by_zero\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Divide_by_zero.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Divide_by_zero.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Divide_by_zero.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
