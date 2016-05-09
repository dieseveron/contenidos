EXPL     = $(CURDIR)/explicaciones
PRAC     = $(CURDIR)/practicas
DELIVER  = $(CURDIR)/entregables
SUBJECTS = iso so

all: install

# Install rules
install: install-explicaciones install-practicas install-entregables
	echo "Prácticas, explicaciones y entregables compiladas correctamente en el directorio pdf/"

install-explicaciones:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(EXPL)/$$s/ install ; done

install-practicas:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(PRAC)/$$s/ install ; done

install-entregables:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(DELIVER)/$$s/ install ; done

# Clean rules
clean: clean-explicaciones clean-practicas clean-entregables

clean-explicaciones:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(EXPL)/$$s/ clean ; done

clean-practicas:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(PRAC)/$$s/ clean ; done

clean-entregables:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(DELIVER)/$$s/ clean ; done

# Distclean rules
distclean: distclean-explicaciones distclean-practicas distclean-entregables

distclean-explicaciones:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(EXPL)/$$s/ distclean ; done

distclean-practicas:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $(PRAC)/$$s/ distclean ; done

distclean-entregables:
	@for s in $(DELIVER) ; do $(MAKE) -C $(DELIVER)/$$s/ distclean ; done
