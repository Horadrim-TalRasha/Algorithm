LIB_PATH_NAME = libs
BUILD_DIR_NAME = build
CFLAGS = -g -Wall -Werror
LD_FLAGS =

SRC := $(wildcard ./*.c)
OBJS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.o)

all:

mk_build_dir:
	@mkdir -p $(BUILD_DIR_NAME)

check_depends:
	## Need implement

$(BUILD_DIR_NAME)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all mk_build_dir check_depends