include ../common.mk
include depends.mk
include loc_config.mk

CFLAGS += -fPIC

all: mk_build_dir check_depends $(OBJS) $(BIN) $(SHARE) $(ARCHIVE)


clean:
	rm -rf $(BUILD_DIR_NAME) $(BIN) $(SHARE) $(ARCHIVE)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@  $(OBJS)

$(SHARE): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

$(ARCHIVE): $(OBJS)
	ar -crv $@ $(OBJS)


.PHONY: all clean