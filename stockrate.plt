set term gif animate delay 20 size 1920,1080
set style data histogram
set style fill solid
set title 'Stock X'
set output "Stockrate.gif"
set xlabel 'day'
set ylabel 'rate'
set xrange[0:9999]
set yrange[-1:1]
unset key
do for[i=0:100]{
plot "data.dat" using 2 every ::0::100*i
}
