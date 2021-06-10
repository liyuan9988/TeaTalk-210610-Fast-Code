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
    int i1, i2, i3;
    int k1, k2, k3;
    int i,j,k;
    for (i = 0; i < MAT_SIZE; i+=4){
        i1 = i + 1; i2 = i + 2; i3 = i + 3;
        for (k = 0; k < MAT_SIZE; k+=4){
            k1 = k + 1; k2 = k + 2; k3 = k + 3;
            for (j = 0; j < MAT_SIZE; j++){
                c[i][j]+=a[i][k]*b[k][j];  c[i][j]+=a[i][k1]*b[k1][j];
                c[i][j]+=a[i][k2]*b[k2][j]; c[i][j]+=a[i][k3]*b[k3][j];
                
                c[i1][j]+=a[i1][k]*b[k][j];  c[i1][j]+=a[i1][k1]*b[k1][j];
                c[i1][j]+=a[i1][k2]*b[k2][j]; c[i1][j]+=a[i1][k3]*b[k3][j];
                
                c[i2][j]+=a[i2][k]*b[k][j];  c[i2][j]+=a[i2][k1]*b[k1][j];
                c[i2][j]+=a[i2][k2]*b[k2][j]; c[i2][j]+=a[i2][k3]*b[k3][j];
                
                c[i3][j]+=a[i3][k]*b[k][j];  c[i3][j]+=a[i3][k1]*b[k1][j];
                c[i3][j]+=a[i3][k2]*b[k2][j]; c[i3][j]+=a[i3][k3]*b[k3][j];
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
