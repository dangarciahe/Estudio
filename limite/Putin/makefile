all: data.pdf

CXX = g++

%.x: %.cpp
	$(CXX) $< -o $@

data.txt: lim.x
	./$< 1.0 > $@

%.pdf: %.txt
	gnuplot lim.gp
	xdg-open $@

clear:
	rm data.pdf data.txt lim.x a.out
