set xlabel "Number of processes"
set ylabel "Efficiency"
set yrange [0.5:1]
set term pdf
set out "efficiency.pdf"
plot "datos_linea.txt" u 2:5 w lp title "Efficiency - 8 cores"
