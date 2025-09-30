reset
set grid
set autoscale
#------------- Graf 1 ----------------
set style data lines
set title "Función original"
#unset label
set xlabel   "t"
set ylabel   "A"
plot  "ft.dat"
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
set title "Espectro de magnitud"
#unset label
set xlabel   "nw"
set ylabel   "A"
plot  "ckGra.dat" with impulses   
pause -1 "Grafica 3: Cerrar para ver siguiente\n"

#------------- Graf 4 ----------------
set style data lines
set title "Espectro de fase"
#unset label
set xlabel   "nw"
set ylabel   "phi(nw)"
plot  "ckGraFase.dat"
pause -1 "Grafica 4: Cerrar para terminar el programa\n"
