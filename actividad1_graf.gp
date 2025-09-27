reset
set grid
set autoscale
#------------- Graf 1 ----------------
set style data lines
set title "Función original"
#unset label
set xlabel   "t"
set ylabel   "A"
plot  "ftSFT.dat"
pause -1 "Grafica 1: Cerrar para ver siguiente\n"

#------------- Graf 2 ----------------
set style data lines
set title "Reconstrucción mediante serie de fourier"
#unset label
set xlabel   "t"
set ylabel   "A"
plot  "ftSFT.dat"
pause -1 "Grafica 2: Cerrar para ver siguiente\n"

#------------- Graf 3 ----------------
set title "Representación espectral"
#unset label
set xlabel   "nw"
set ylabel   "phi(nw)"
plot  "ckGra.dat" with impulses   
pause -1 "Grafica 2: Cerrar para terminar el programa\n"

