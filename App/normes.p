set term png

set xlabel "itérations"
set ylabel "ln ( norme )"

set xrange [0:80]
set yrange [-12:0]

set title "wb-cs-stanford"
set output "plot-wb-cs-stanford.png"
plot "graphes/puissances-wb-cs-stanford.txt" using 1:2 title "puissances" with lines, \
		 "graphes/aitken-wb-cs-stanford.txt" using 1:2 title "puissances" with lines

set title "Stanford"
set output "plot-Stanford.png"
plot "graphes/puissances-Stanford.txt" using 1:2 title "puissances" with lines, \
		"graphes/aitken-Stanford.txt" using 1:2 title "puissances" with lines

set title "Stanford-Berkeley"
set output "plot-Stanford-Berkeley.png"
plot "graphes/puissances-Stanford_BerkeleyV2.txt" using 1:2 title "puissances" with lines, \
		"graphes/aitken-Stanford_BerkeleyV2.txt" using 1:2 title "puissances" with lines

set title "in-2004"
set output "plot-in-2004.png"
plot "graphes/puissances-in-2004v2.txt" using 1:2 title "puissances" with lines, \
		"graphes/aitken-in-2004v2.txt" using 1:2 title "puissances" with lines

set title "wikipedia"
set output "plot-wikipedia.png"
plot "graphes/puissances-wikipedia-20051105V2.txt" using 1:2 title "puissances" with lines, \
		"graphes/aitken-wikipedia-20051105V2.txt" using 1:2 title "puissances" with lines

set title "wb-edu"
set output "plot-wb-edu.png"
plot "graphes/puissances-wb-edu.txt" using 1:2 title "puissances" with lines, \
		"graphes/aitken-wb-edu.txt" using 1:2 title "puissances" with lines
