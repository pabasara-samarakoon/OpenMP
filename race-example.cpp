#include <stdio.h>
#include <omp.h>

int main() {
    int shared_variable = 0;

    double start_time = omp_get_wtime(); // Start timing

    #pragma omp parallel num_threads(8)
    {
        for (int i = 0; i < 100000000; i++) {
            shared_variable++; 
        }
    }

    double end_time = omp_get_wtime(); // End timing

    printf("Final value of shared_variable is %d.\n", shared_variable);
    printf("Runtime: %f seconds\n", end_time - start_time); // Calculate and print runtime

    return 0;
}
