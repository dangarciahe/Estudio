set xlabel "Number of processes"
set ylabel "Efficiency"
set term pdf
set out "efficiency.pdf"
plot "datos_linea.txt" u 1:2 w lp title "Efficiency"
