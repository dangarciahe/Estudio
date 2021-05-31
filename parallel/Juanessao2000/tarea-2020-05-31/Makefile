all:

N_processes = 8 #número total de procesos simultáneos
np = 4  #you can give the value of any of this variable just writing, for example, "make v2 np=7", and even knowing than in the makefile the value assigned to np is 4, the command line will be priorized and np will be reasigned with the value 7
a = 5
b = 7
N = 20000000

.PHONY: clear v1 v2

example:
	mpic++ -o ex.x -g mpi_integral_v4.cpp
	mpirun -np $(np) ./ex.x $(a) $(b) $(N)

v1:
	mpic++ -o pi.x -g pi_montecarlo_v1.cpp
	mpirun -np $(np) ./pi.x $(N)  

v2:
	mpic++ -o pi.x -g pi_montecarlo_v2.cpp  
	sh run.sh $(N_processes) $(N)

clear:
	rm *.x *.out *~ *.txt
