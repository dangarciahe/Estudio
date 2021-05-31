
n_cores=$1 #esta variable leerá el primer valor de comando que le sea insertado en la línea de comando al correr el archivo
N=$2 #número de puntos aleatorios que se van a crear
i=1
let max=$n_cores+1 #es necesario el comando 'let' en bash para que te permita realizar operaciones aritméticas en bash

> datos_brutos.txt && >datos_linea.txt

while [ $i -lt $max ]
do
    mpirun -np $i ./pi.x $N >> datos_brutos.txt
    ((i=i+1))
done

grep -i '3.1' datos_brutos.txt >> datos_linea.txt
