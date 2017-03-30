#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Mude para o número de threads da sua máquina
// Garanta que exista um máximo
#define NUM_THREADS	4

int max = 0;
int array[NUM_THREADS] = {2, 4, 1, 3};

void *find_max(void *threadid){
    long tid;
    tid = (long)threadid;

    if(array[tid] > max){
        max = tid;
    };

    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];

    int error_code;
    long t;

    for(t = 0; t < NUM_THREADS; t++){
        error_code = pthread_create(&threads[t], NULL, find_max, (void *)t);
        if(error_code){
            printf("ERROR; return code from pthread_create() is %d\n", error_code);
            exit(-1);
        };
    };

    printf("MAX = %d\n", max);

    pthread_exit(NULL);
};
