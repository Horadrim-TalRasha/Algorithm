mod_filter.la: mod_filter.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_filter.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_filter.la
