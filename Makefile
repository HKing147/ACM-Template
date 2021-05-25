template.pdf: template.tex main clean
	./main
	xelatex template.tex
	xelatex template.tex

template.tex: main

main: main.cpp
	g++ main.cpp -o main

clean:
	rm -rf template.*
