CURRENT_PATH := $(shell pwd)/..
LIB_PATH_NAME = libs
BUILD_DIR_NAME = build
CFLAGS = -g -Wall -Werror
LD_FLAGS =
INCLUDE_PATH = -I ../

SRC := $(wildcard ./*.c)
OBJS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.o)
DEPS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.d)


all:

mk_build_dir:
	@mkdir -p $(BUILD_DIR_NAME)
	@echo "i shall be first"

check_depends:


$(BUILD_DIR_NAME)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@


$(BUILD_DIR_NAME)/%.d: %.c
	@echo "WTF"
	$(CC) -MM $(INCLUDE_PATH) $(CFLAGS) $< > $@

sinclude $(DEPS)


clean::
	rm -rf $(BUILD_DIR_NAME) $(BIN) $(SHARE) $(ARCHIVE)

.PHONY: all mk_build_dir check_depends