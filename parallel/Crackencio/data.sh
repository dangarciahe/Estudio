#> datos_brutos.txt
#echo "# Threads  |  Runtime[s]  |  Speedup  |  Efficiency" > tabla.txt
for number in {1..4}
do
    echo $number
    OMP_NUM_THREADS=$number
    	echo $OMP_NUM_THREADS
	/usr/bin/time ./a.out
    #/usr/bin/time ./a.out -o tabla.txt -a 
    echo
done



