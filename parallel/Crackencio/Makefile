#Si el data.sh termina en .sh, el cambio a OMP_NUM_THREADS se pierde una vez se termina de ejecutar make. 
#Para hacer eset cambio persistente, cambiar el archivo de data.sh a data

SHELL := /bin/bash

target: datos


a.out: $(f) #f de file
	g++ $< -fopenmp -o $@


datos: data.sh a.out
	source data.sh


.PHONY: clear_data


clear:
	rm *.x a.out

