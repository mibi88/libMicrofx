NAME = Template

ELF = $(NAME).elf
BIN = $(NAME).bin

CC = sh-elf-gcc

SRC = src/main.c
OBJ = $(SRC:src/%=build/%.o)

ICON = icon.png

LIB = lib

BUILD = build

VERSION = v.1.0

all: $(BIN)
	fxgxa --g1a -n $(NAME) -i $(ICON) --version="$(VERSION)" -o $(NAME).g1a build/$(BIN)
	sh-elf-objdump -h $(BUILD)/$(ELF)
	rm -fr $(BUILD)

$(BIN): $(ELF)
	sh-elf-objcopy -O binary build/$(ELF) build/$(BIN) -R .bss

$(ELF): $(OBJ) | $(LIB)/
	$(CC) $(OBJ) $(LIB)/libMicrofx.a -o $(BUILD)/$@ -nostdlib -T lib/fx98xx.ld -ffreestanding -mb -m3 -Os -Wa,--dsp -lgcc

$(BUILD)/%.o: src/% | $(BUILD)/
	$(CC) -c $< -o $@ -Os -Ilib/include/ -std=c89

.PRECIOUS: %/

%/:
	@ mkdir -p $@

clean: $(BUILD)
	rm $(BUILD) --recursive
	rm $(NAME).g1a

