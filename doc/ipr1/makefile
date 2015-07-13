PROJ = ipr1
TEX = pdflatex -output-directory=out -include-directory=src
BIB = bibtex -include-directory=out -include-directory=src
all:
ifneq ("$(wildcard src/*.bib)","")
	$(TEX) src/main.tex
	$(BIB) out/main
else
endif
	$(TEX) src/main.tex
	$(TEX) src/main.tex
	mv out/main.pdf $(PROJ).pdf
clean:
	@rm -rf out/*
echo view:
	open $(PROJ).pdf
