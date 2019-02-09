CURRENT_PATH := $(shell pwd)
LIB_PATH_NAME = libs
BUILD_DIR_NAME = build
CFLAGS = -g -Wall -Werror
LD_FLAGS =
INCLUDE_PATH = -I ../

SRC := $(wildcard ./*.c)
OBJS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.o)
DEPS := $(SRC:./%.c=./$(BUILD_DIR_NAME)/%.d)


all::

mk_build_dir:
	@mkdir -p $(BUILD_DIR_NAME)

check_depends:

.PHONY: mk_build_dir check_depends


$(BUILD_DIR_NAME)/%.d: %.c
	@set -e; \
	rm -f $@; \
	mkdir -p $(BUILD_DIR_NAME); \
	$(CC) -MM $(INCLUDE_PATH) $(CFLAGS) $< > $@.tmp;\
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@


-include $(DEPS)


$(BUILD_DIR_NAME)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

clean::
	rm -rf $(BUILD_DIR_NAME) $(BIN) $(SHARE) $(ARCHIVE)

.PHONY: clean