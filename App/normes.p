set term png

set xlabel "itérations"
set ylabel "ln ( norme )"

set xrange [0:80]
set yrange [-12:0]

set title "wb-cs-stanford"
set output "../Docs/texRapport/plot-wb-cs-stanford.png"
plot "graphes/puissances-wb-cs-stanford.txt" using 1:2 title "puissances" with lines
#si aitken implénter ajouter à la ligne dessus => ", "graphes/aitken-wb-cs-stanford.txt" using 1:2 title "puissances" with lines"

set title "Stanford"
set output "../Docs/texRapport/plot-Stanford.png"
plot "graphes/puissances-Stanford.txt" using 1:2 title "puissances" with lines
