set yrange [0:*]
set term png
set output "guest_time.png"
set boxwidth 0.5
set style fill solid
plot "guest_time.dat" using 1:3:xtic(2) with boxes