#Project name.
PROJ_NAME = main
#Compiler
CC = @sdcc
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
--Werror					\
-MMD
#Your device for stm8flash.
DEVICE = stm8s103f3		# Your device for stm8flash.
#All object.
OBJECT = $(patsubst $(SRC)%.c, $(OUT)%.rel,$(wildcard $(SRC)*.c))	# All object.

#Non file target.
.PHONY: load clean

$(OUT)$(PROJ_NAME).ihx: $(OBJECT)
	$(CC) $(CFLAG) -o $(OUT)$(PROJ_NAME).ihx $(OBJECT)

$(OUT)%.rel: $(SRC)%.c
	$(CC) $(CFLAG) -c  $< -o $@

-include $(OUT)*.d

load:	$(OUT)$(PROJ_NAME).ihx
	stm8flash -c stlinkv2 -p $(DEVICE) -w $(OUT)$(PROJ_NAME).ihx

clean:
	@-rm -f $(OUT)*.asm $(OUT)*.cdb $(OUT)*.ihx $(OUT)*.lk $(OUT)*.map $(OUT)*.lst $(OUT)*.rel $(OUT)*.sym $(OUT)*.rst $(OUT)*.d

start_server:
	@./diagslave /dev/ttyUSB0 -m rtu -b 9600 -a 10 -f 3
