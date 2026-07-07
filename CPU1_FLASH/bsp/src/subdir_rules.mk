################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
bsp/src/%.obj: ../bsp/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -O2 --fp_mode=relaxed --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/app/inc" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/app/src" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/bsp/inc" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/bsp/src" --include_path="C:/TI/C2000Ware/C2000Ware_5_02_00_00" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/device" --include_path="C:/TI/C2000Ware/C2000Ware_5_02_00_00/driverlib/f28003x/driverlib" --include_path="C:/TI/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --advice:performance=all --define=DEBUG --define=_FLASH --c99 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="bsp/src/$(basename $(<F)).d_raw" --include_path="C:/TI/workspace/workspace_f280039c/project00_assemble/CPU1_FLASH/syscfg" --obj_directory="bsp/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


