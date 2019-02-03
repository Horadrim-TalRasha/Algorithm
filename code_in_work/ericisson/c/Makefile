include arch.mk
include common.mk

all:
ifdef SUBDIRS
	@for dir in $(SUBDIRS) ;\
	do\
		if [ -d $$dir ] ;\
		then \
			make -C $$dir ;\
		fi ;\
	done
endif


clean::
ifdef SUBDIRS
	@for dir in $(SUBDIRS) ;\
	do\
		if [ -d $$dir ] ;\
		then \
			make -C $$dir clean;\
		fi ;\
	done
endif


.PHONY: all clean
