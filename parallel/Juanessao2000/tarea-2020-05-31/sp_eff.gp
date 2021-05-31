set xlabel "Number of processes"
set title "Speedup and efficiency - machine with 8 cores"
set term pdf
set out "sp_eff.pdf"
plot "datos_linea.txt" u 2:4 w lp title "Speedup", replot "datos_linea.txt" u 2:5 w lp title "Efficiency" 
