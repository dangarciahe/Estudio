pavg.o: pavg.cpp pavg.h
	g++ -c $<

adsanit: pavg.o man_paral_avg.cpp #compiles with address sanitizers
	g++ -o pavg.x -g -Wall -fsanitize=address -fsanitize=undefined  $^
	/usr/bin/time ./pavg.x 10 2

thsanit: pavg.o man_paral_avg.cpp #compiles with threads sanitizers
	g++ -o pavg.x -g -Wall -fsanitize=thread -fsanitize=undefined  $^
	/usr/bin/time ./pavg.x 10 2

valgrind: pavg.o man_paral_avg.cpp #compiles and excecutes the executable so that it is analized by valgrind
	g++ -o pavg.x -g -Wall -fsanitize=thread -fsanitize=undefined  $^
	/usr/bin/time ./pavg.x 10 2 valgrind


#NOTE:-fsanitize=address and -fsanitize=thread are incompatible. Therefore, they cannot be used simultanously.

clean:
	rm -f *.o *.x
