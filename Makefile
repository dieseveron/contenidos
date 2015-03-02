SRC      = src
SUBJECTS = $(SRC)/iso $(SRC)/so

all:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $$s/ ; done

install:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $$s/ install ; done

clean:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $$s/ clean ; done

distclean:
	@for s in $(SUBJECTS) ; do $(MAKE) -C $$s/ distclean ; done
