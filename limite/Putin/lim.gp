set logscale y
set xlabel 'n'
set ylabel 'Relative error'
set term pdf
set out 'data.pdf'
plot 'data.txt' u 1:2 w lp t 'serie', 'data.txt' u 1:3  w lp t 'f(x)', 'data.txt' u 1:4  w lp t 'g(x)'
