set xlabel "Number of processes"
set title "Speedup and efficiency - machine with 8 cores"
set term png
set out "sp_eff.png"
plot "datos_linea.txt" u 2:4 w lp title "Speedup"
set yrange [0.5:1]
plot "datos_linea.txt" u 2:5 w lp title "Efficiency" 
