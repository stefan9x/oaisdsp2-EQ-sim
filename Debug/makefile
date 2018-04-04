################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c5500_4.4.1

ORDERED_OBJS += \
"./EZDSP5535_SAR_sim.obj" \
"./aic3204.obj" \
"./aic3204_init.obj" \
"./ezdsp5535_aic3204_dma.obj" \
"./iir.obj" \
"./main.obj" \
"./print_number.obj" \
"./processing.obj" \
"../lnkx.cmd" \
"../lib/ezdsp5535bsl.lib" \
"../c55xx_csl/lib/cslVC5505.lib" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"rts55h.lib" \
-l"cslVC5505.lib" \
-l"rts55x.lib" \
-l"ezdsp5535bsl.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include lib/subdir_vars.mk
-include c55xx_csl/lib/subdir_vars.mk
-include subdir_rules.mk
-include lib/subdir_rules.mk
-include c55xx_csl/lib/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
EQ\ sim.out \

EXE_OUTPUTS__QUOTED += \
"EQ sim.out" \

BIN_OUTPUTS += \
EQ\ sim.hex \

BIN_OUTPUTS__QUOTED += \
"EQ sim.hex" \


# All Target
all: EQ\ sim.out

# Tool invocations
EQ\ sim.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 -z -m"EQ sim.map" --stack_size=0x200 --heap_size=0x400 -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"C:/Users/Stefan/Desktop/dsp_projekat/Projektni zadatak/EQ sim/c55xx_csl/lib" -i"C:/Users/Stefan/Desktop/dsp_projekat/Projektni zadatak/EQ sim/lib" -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --reread_libs --display_error_number --warn_sections --xml_link_info="EQ sim_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "EQ sim.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

EQ\ sim.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "EQ sim.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "EZDSP5535_SAR_sim.pp" "aic3204.pp" "aic3204_init.pp" "ezdsp5535_aic3204_dma.pp" "iir.pp" "main.pp" "print_number.pp" "processing.pp" 
	-$(RM) "EZDSP5535_SAR_sim.obj" "aic3204.obj" "aic3204_init.obj" "ezdsp5535_aic3204_dma.obj" "iir.obj" "main.obj" "print_number.obj" "processing.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

