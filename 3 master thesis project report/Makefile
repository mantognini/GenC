
all:
	# Build it enough times
	pdflatex -shell-escape -halt-on-error -interaction=nonstopmode report
	bibtex report
	pdflatex -shell-escape -halt-on-error -interaction=nonstopmode report
	pdflatex -shell-escape -halt-on-error -interaction=nonstopmode report

clean:
	rm -fr _markdown_report report.bbl report.bcf report.blg report.lol report.aux* report.fdb_latexmk report.fls report.log report.markdown.* report.out report.toc report.pdf

