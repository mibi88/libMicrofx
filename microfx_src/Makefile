CC = sh-elf-gcc
AR = sh-elf-ar

OUT = libMicrofx.a
OUT_DIR = lib

SRC = src/start.c src/syscall.S src/microfx.c src/img.c
OBJ = $(SRC:src/%=build/%.o)

CFLAGS = -Os -Wall -Wextra -Wpedantic -Werror -std=c89

BUILD = build

all: $(OBJ) | $(OUT_DIR)/
	$(AR) rsv $(OUT_DIR)/$(OUT) $(OBJ)
	cp --recursive include $(OUT_DIR)/
	cp src/fx98xx.ld $(OUT_DIR)/

$(BUILD)/%.o: src/% | $(BUILD)/
	$(CC) -c $< -o $@ $(CFLAGS)

.PRECIOUS: %/

%/:
	@ mkdir -p $@

clean: $(BUILD)/ | $(OUT_DIR)/
	rm $(OUT_DIR) --recursive
	rm $(BUILD) --recursive
