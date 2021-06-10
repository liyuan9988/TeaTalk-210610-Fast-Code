#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SERIES_LEN 1000

int 
main(void)
{
    srand(42);
    
    
    timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    int i;
    double res = 0.0;
    double a = pow(2, SERIES_LEN);
    for (i = 0; i < SERIES_LEN; i++){
    	res += 1.0 / a;
        a /= 2.0;
    }
    gettimeofday(&end_time, NULL);
    long time = (end_time.tv_sec - start_time.tv_sec) * 1000000;
    time += (end_time.tv_usec - start_time.tv_usec);
    printf("time %ld[ms]\n", time);    
    printf("res %lf\n", res);
    return 0;

}
