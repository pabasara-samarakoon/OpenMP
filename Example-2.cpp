#include <omp.h>
#include <stdio.h>

int main() {
    int x = 0;
    printf("\n Initially, x = %d", x);

    omp_set_num_threads(4);

#pragma omp parallel
    {
        int myid = omp_get_thread_num();
        x = x + myid; 
        printf("\n Thread %d >>>>> x + myid = %d", myid, x);
    }

    return 0;
}