#Project name.
PROJ_NAME = main
#Compiler
CC = sdcc
#Include directory
INC = inc/
#Source directory.
SRC = src/
#Out directory
OUT = out/
#MCU type.
MCU = stm8

#Compiler flags.
CFLAG = -m$(MCU)	\
-I $(INC)					\
-MMD							\
--Werror					\
#--debug
#--i-code-in-asm
#-V
#--no-c-code-in-asm
#--verbose
#--opt-code-speed	\
#--opt-code-size		\

#Your device for stm8flash.
DEVICE = stm8s103f3		# Your device for stm8flash.

#All object.
OBJECT = $(patsubst $(SRC)%.c, $(OUT)%.rel,$(wildcard $(SRC)*.c))	# All object.

#Non file target.
.PHONY: load clean

$(OUT)$(PROJ_NAME).ihx: $(OBJECT)
	$(CC) $(CFLAG) -o $(OUT)$(PROJ_NAME).ihx $(OBJECT)
	@#$(CC) --out-fmt-elf $(CFLAG) -o $(OUT)$(PROJ_NAME).elf $(OBJECT)

$(OUT)%.rel: $(SRC)%.c
	$(CC) $(CFLAG) -c  $< -o $@

-include $(OUT)*.d

load:	$(OUT)$(PROJ_NAME).ihx
	stm8flash -c stlinkv2 -s flash -p $(DEVICE) -w $(OUT)$(PROJ_NAME).ihx

clean:
	-rm -f $(OUT)*.asm $(OUT)*.adb $(OUT)*.cdb $(OUT)*.ihx $(OUT)*.lk $(OUT)*.map $(OUT)*.lst $(OUT)*.rel $(OUT)*.sym $(OUT)*.rst $(OUT)*.d
