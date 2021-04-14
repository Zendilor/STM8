#Project name.
PROJ_NAME = PowerBlock
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
#EEPROM
eeprom = eeprom.ihx
#FLASH
flash = flash.ihx

#Compiler flags.
CFLAG = -m$(MCU)	\
-I $(INC)					\
-MMD							\
#--Werror					\
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
OBJECT = $(patsubst $(SRC)%.c, $(OUT)%.rel,$(wildcard $(SRC)*.c))

#Non file target.
.PHONY: help flash_load eeprom_load clean

$(OUT)$(PROJ_NAME).ihx: $(OBJECT)
	$(CC) $(CFLAG) -o $(OUT)$(PROJ_NAME).ihx $(OBJECT)

$(OUT)%.rel: $(SRC)%.c
	$(CC) $(CFLAG) -c  $< -o $@

-include $(OUT)*.d

flash_load:	$(OUT)$(PROJ_NAME).ihx
	stm8flash -c stlinkv2 -s flash -p $(DEVICE) -w $(OUT)$(PROJ_NAME).ihx

flash_read:
	stm8flash -c stlinkv2 -s flash -p $(DEVICE) -r $(OUT)$(flash)

eeprom_load:
	stm8flash -c stlinkv2 -s eeprom -p $(DEVICE) -w $(eeprom)

eeprom_read:
		stm8flash -c stlinkv2 -s eeprom -p $(DEVICE) -r $(OUT)$(eeprom)

clean:
	-rm -f $(OUT)*.asm $(OUT)*.adb $(OUT)*.cdb $(OUT)*.ihx $(OUT)*.lk $(OUT)*.map $(OUT)*.lst $(OUT)*.rel $(OUT)*.sym $(OUT)*.rst $(OUT)*.d

help:
	@echo "//////////////////////////////////////////////////////////////////////////////////"
	@echo "Hi, I am Zendilor and this is my project"
	@echo "Below I have listed all the actions in the project"
	@echo
	@echo "flash_load  -  write the flash to the microcontroller"
	@echo "flash_read  -  read the flash from the microcontroller and save to a folder" - $(OUT)
	@echo "eeprom_load -  write the eeprom to the microcontroller"
	@echo "eeprom_read -  read the flash from the microcontroller and save to a folder" - $(OUT)
	@echo "clean       -  clean all object"
	@echo
	@echo "Best regards Zendilor"
	@echo "My email - Zendilor@gmail.com"
	@echo "//////////////////////////////////////////////////////////////////////////////////"
