#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAT_SIZE 2000

int 
main(void)
{
    srand(42);
    float** a = new float*[MAT_SIZE];
    float** b = new float*[MAT_SIZE];
    float** c = new float*[MAT_SIZE];
    timeval start_time, end_time;
    for(int i=0; i<MAT_SIZE; i++){
        a[i] = new float[MAT_SIZE];
        b[i] = new float[MAT_SIZE];
        c[i] = new float[MAT_SIZE];
        for(int j=0; j<MAT_SIZE; j++){
            a[i][j] = rand() / ((float)RAND_MAX);
            b[i][j] = rand() / ((float)RAND_MAX);
            c[i][j] = 0.0;
        }
    }
    gettimeofday(&start_time, NULL);
    int i,j,k;
    for (i = 0; i < MAT_SIZE; i++){
        for (k = 0; k < MAT_SIZE; k++){
            for (j = 0; j < MAT_SIZE; j++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    gettimeofday(&end_time, NULL);
    long time = (end_time.tv_sec - start_time.tv_sec) * 1000000;
    time += (end_time.tv_usec - start_time.tv_usec);
    printf("time %ld[ms]\n", time);    
    for(int i=0; i<MAT_SIZE; i++){
       delete[] a[i];
       delete[] b[i];
       delete[] c[i];
    }
    delete[]  a;
    delete[]  b;
    delete[]  c;
    return 0;

}
