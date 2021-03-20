all: Show

Exp_error.x : Exp_error.cpp
	g++ Exp_error.cpp -o Exp_error.x

datos.txt : Exp_error.x
	./Exp_error.x > datos.txt

Show: datos.txt
	less datos.txt

clear:
	rm -f datos.txt Exp_error.x
