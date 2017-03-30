#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// Mude para o número de threads da sua máquina
// Garanta que exista um máximo
#define NUM_THREADS	4

int max = 0;
int array[NUM_THREADS] = {2, 4, 1, 3};

int main (int argc, char *argv[]){
    int nthreads, tid;

    #pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        if(array[tid] > max){
            max = tid;
        };
    };

    printf("MAX = %d\n", max);
};
