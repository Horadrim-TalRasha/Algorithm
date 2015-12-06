GREP = grep
SED = sed
TARGETDIR = ./dir
BACKDIR = ./dir_bak
MF = 

mult-file:
	$(SED) $(MF) 's/property/properties/' `$(GREP) -rl "propert" $(TARGETDIR)`

revert-file:
	cp -r $(BACKDIR)/* $(TARGETDIR)/

