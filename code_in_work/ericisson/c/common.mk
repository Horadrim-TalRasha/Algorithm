CURRENT_PATH := $(shell pwd)/..
LIB_PATH_NAME = libs
BUILD_DIR_NAME = build
CFLAGS = -g -Wall -Werror
LD_FLAGS =
INCLUDE_PATH = -I ../

SRC := $(wildcard ./*.c)
OBJS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.o)




all:

mk_build_dir:
	@mkdir -p $(BUILD_DIR_NAME)

check_depends:


$(BUILD_DIR_NAME)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

.PHONY: all mk_build_dir check_depends