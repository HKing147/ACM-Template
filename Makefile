template.pdf: template.tex clean
	python3 main.py
	xelatex template.tex
	xelatex template.tex

template.tex: main.py
	python3 main.py

clean:
	rm -rf template.*
