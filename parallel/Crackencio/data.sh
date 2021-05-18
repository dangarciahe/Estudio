> datos_brutos.txt
echo "# Threads  |  Runtime[s]  |  Speedup  |  Efficiency" > tabla.txt
for number in {1..4}
do
    echo $number    
    export OMP_NUM_THREADS=$number	
    /usr/bin/time ./a.out
    #/usr/bin/time ./a.out -o tabla.txt -a 
    echo
done



