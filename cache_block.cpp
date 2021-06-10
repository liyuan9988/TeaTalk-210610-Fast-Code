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
    
    int BLOCK = 16;
    int i,j,k;
    int ii, kk, jj;
    int ii1, ii2, ii3;
    int kk1, kk2, kk3;
    for (i = 0; i <MAT_SIZE; i+=BLOCK){
        for(k = 0; k < MAT_SIZE; k+=BLOCK){
            for(j = 0; j < MAT_SIZE; j+=BLOCK){
                for(ii = i; ii < (i + BLOCK); ii+=4){
                    ii1 = ii + 1; ii2 = ii + 2; ii3 = ii + 3;
                    for (kk = k; kk < (k + BLOCK); kk+=4){
                        kk1 = kk + 1; kk2 = kk + 2; kk3 = kk + 3;
                        for (jj = j; jj < (j + BLOCK); jj++){
                            c[ii][jj]+=a[ii][kk]*b[kk][jj];  c[ii][jj]+=a[ii][kk1]*b[kk1][jj];
                            c[ii][jj]+=a[ii][kk2]*b[kk2][jj]; c[ii][jj]+=a[ii][kk3]*b[kk3][jj];
                            
                            c[ii1][jj]+=a[ii1][kk]*b[kk][jj];  c[ii1][jj]+=a[ii1][kk1]*b[kk1][jj];
                            c[ii1][jj]+=a[ii1][kk2]*b[kk2][jj]; c[ii1][jj]+=a[ii1][kk3]*b[kk3][jj];
                            
                            c[ii2][jj]+=a[ii2][kk]*b[kk][jj];  c[ii2][jj]+=a[ii2][kk1]*b[kk1][jj];
                            c[ii2][jj]+=a[ii2][kk2]*b[kk2][jj]; c[ii2][jj]+=a[ii2][kk3]*b[kk3][jj];
                            
                            c[ii3][jj]+=a[ii3][kk]*b[kk][jj];  c[ii3][jj]+=a[ii3][kk1]*b[kk1][jj];
                            c[ii3][jj]+=a[ii3][kk2]*b[kk2][jj]; c[ii3][jj]+=a[ii3][kk3]*b[kk3][jj];
                        }
                    }
                }
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
