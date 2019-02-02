include ../common.mk
include depends.mk
include loc_config.mk

LD_FLAGS += -L../$(LIB_PATH_NAME) $(addprefix -l, $(DEPEND_PROS))

all: mk_build_dir check_depends $(OBJS) $(BIN) $(SHARE) $(ARCHIVE)


clean:
	rm -rf $(BUILD_DIR_NAME) $(BIN) $(SHARE) $(ARCHIVE)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LD_FLAGS) -o $@  $(OBJS) -lpthread

$(SHARE): $(OBJS)
	gcc -shared -o $@ $(OBJS) -lpthread

$(ARCHIVE): $(OBJS)
	ar -crv $@ $(OBJS)


.PHONY: all clean