SHELL := /bin/bash

target: datos

a.out: integral_Riemann.cpp
	g++ -fopenmp integral_Riemann.cpp

datos: a.out data.sh
	source data.sh

.PHONY: clear_data

clear_data:
	rm *.txt
