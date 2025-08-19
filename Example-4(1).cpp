#include <omp.h>
#include <stdio.h>

int main() {
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(a) / sizeof(a[0]);

    omp_set_num_threads(4);

    #pragma omp parallel
    {
        //You may use "omp_get_num_threads()" and "omp_get_thread_num()" to find 
        // - the number of threads and thread's id 
        // Initialise the array values with a[i] += 10 in a round robin manner
            
			printf("\n Thread %d >>>>> a[%d] = %d", myid, i, a[i]);
        }
    }

    return 0;
}
