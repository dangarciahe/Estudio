set log y
set xlabel "N"
set ylabel "% de error"
set term pdf
set out "grafica.pdf"
plot "datosexp.txt" u 1:2 w lp title "Series de potencia", "datosexp.txt" u 1:3 w lp title "Relacion de recursividad"
