set log y
set xlabel "Número de iteraciones"
set ylabel "Error porcentual"
set term pdf
set out "datos.pdf"
plot "datos.txt" u 1:2 w lp title "taylor recursion", "datos.txt" u 1:3 w lp title "taylor factorial"
