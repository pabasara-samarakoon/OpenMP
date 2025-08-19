#include <omp.h>
#include <stdio.h>

int main() {
    int a[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    omp_set_num_threads(8);  // Match the number of threads to the array size

	#pragma omp parallel
    {
        //You may use "omp_get_thread_num()" to find thread's ids
        //Complete this to set a[myid] = myid * myid, by each thread
        
        printf("\n Thread %d >>>>> a[%d] = %d", myid, myid, a[myid]);
    }

    return 0;
}
