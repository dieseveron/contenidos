
OUTPUTDIR=pdf

all:
	pdflatex -output-directory $(OUTPUTDIR) practica01.tex
	pdflatex -output-directory $(OUTPUTDIR) practica02.tex
	pdflatex -output-directory $(OUTPUTDIR) practica03.tex
	pdflatex -output-directory $(OUTPUTDIR) practica04.tex
	pdflatex -output-directory $(OUTPUTDIR) practica05.tex
	pdflatex -output-directory $(OUTPUTDIR) practica06.tex

01:
	pdflatex -output-directory $(OUTPUTDIR) practica01.tex

02:
	pdflatex -output-directory $(OUTPUTDIR) practica02.tex

03:
	pdflatex -output-directory $(OUTPUTDIR) practica03.tex

04:	
	pdflatex -output-directory $(OUTPUTDIR) practica04.tex

05:
	pdflatex -output-directory $(OUTPUTDIR) practica05.tex

06:	
	pdflatex -output-directory $(OUTPUTDIR) practica06.tex

clean:
	cd $(OUTPUTDIR)
	rm *aux *log

clean-all:
	cd $(OUTPUTDIR)
	rm *aux *log *pdf