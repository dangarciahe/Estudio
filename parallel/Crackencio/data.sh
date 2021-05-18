for number in {1..4}
do
	echo $number
	export OMP_NUM_THREADS=$number
	echo "El numero de threads es":  $number
	/usr/bin/time ./a.out
	echo
done
