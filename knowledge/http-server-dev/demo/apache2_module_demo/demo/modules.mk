mod_demo.la: mod_demo.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_demo.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_demo.la
