#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define fo  10
#define A   12.5
#define Ar  1.25
#define M   1000
#define pi 3.14159

void quantize_int(float f_array[], int L_bits,char file_name[]);

void main(){
FILE *signal_file;
    float sin_x[M];
    float pow_sin = 0.f;
    float noise[M];
    float pow_noise = 0.f;
    float sin_x_noise[M];
    float SNR = 1.f;
    float pow_sin_x_noise = 0.0f;

    srand((unsigned int)time(NULL));

    // Potencia de señal sinusoidal y numeros aleatorios
    for(int n = 0; n < M; ++n){
        sin_x[n] = A*sin(2*pi*fo*n/M);
        pow_sin += sin_x[n] * sin_x[n];
        noise[n] = Ar *((float)rand()/(float)RAND_MAX);
        pow_noise += noise[n] * noise[n];
    }

    pow_sin = (1/(float)M)*pow_sin;
    pow_noise = (1/(float)M)*pow_noise;

    signal_file = fopen("sinusoid.dat", "w");
    // 
    for(int i =0; i<M; i++){
        sin_x_noise[i] = sin_x[i] + (noise[i] * sqrtf((pow_sin/SNR)/(pow_noise)));
        fprintf(signal_file,"%f\n", sin_x_noise[i]);
        pow_sin_x_noise += sin_x_noise[i] * sin_x_noise[i];
    }
    fclose(signal_file);
    pow_sin_x_noise = (1/(float)M)*pow_sin_x_noise;


    printf("Potencia de senal sinusoidal: %f\n", pow_sin);
    printf("Potencia de senal sinusoidal con ruido: %f\n", pow_sin_x_noise);

    quantize_int(sin_x_noise, 5, "q5_signal.dat");
    quantize_int(sin_x_noise, 9, "q9_signal.dat");
    quantize_int(sin_x_noise, 11, "q11_signal.dat");

    system("gnuplot -p actividad2_graf.gp");

}

void quantize_int(float f_array[], int L_bits, char file_name[]){
    if(strlen(file_name) <= 0) {printf("Longitud de nombre insuficiente"); return;}
    if(strlen(file_name) > 40) {printf("Longitud de nombre muy grande"); return;}
    int q_array[M] = {};
    int q_max_val = (int)pow(2,L_bits-1)-1;
    float ECM = 0.f;
    FILE *file;
    file = fopen(file_name, "w");

    for(int n = 0; n < M; ++n){
        if(f_array[n] > (float)q_max_val){
            q_array[n] = q_max_val;
        }
        else if(f_array[n] < -(float)q_max_val){
            q_array[n] = -q_max_val;
        }
        else{
            q_array[n] = (int)(f_array[n]+0.5);
        }
        ECM += (f_array[n] - (float)q_array[n])*(f_array[n] - (float)q_array[n]);
        fprintf(file, "%d \n", q_array[n]);
    }
    fclose(file);
    ECM = (1/(float)M)*ECM;
    printf("El error cuadratico medio a %d bits es: %f\n", L_bits, ECM);
}
