all: datos.pdf

datos.txt: experror.cpp
	g++ experror.cpp -o exper.x
	./exper.x -> datos.txt

datos.pdf: experror.gp datos.txt
	gnuplot $<
	gimp $@ &

clean:
	rm *.x *.txt *.pdf
