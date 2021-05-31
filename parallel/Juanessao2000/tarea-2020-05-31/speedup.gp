set xlabel "Number of processes"
set ylabel "Speedup"
set term pdf
set out "speedup.pdf"
plot "datos_linea.txt" u 2:4 w lp title "Speedup - 8 cores"
