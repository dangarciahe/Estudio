all: grafica.pdf

%.x : %.cpp
	g++ $< -o $@

datosexp.txt : 5-10exp.x
	./$< > $@

grafica.pdf : exp.gp datosexp.txt 
	gnuplot $<
	okular $@ &

clean :
	rm *.pdf *.txt *.x
