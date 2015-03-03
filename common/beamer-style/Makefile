DOCUMENTS=$(patsubst %.svg,%.pdf,$(wildcard *.svg))

all: $(DOCUMENTS)

%.pdf: %.svg
	inkscape -z -f $< --export-pdf=$@


clean:
	rm -f $(DOCUMENTS)
	rm -f *.log

.PHONY: clean
