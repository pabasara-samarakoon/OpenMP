//pragma - pragmatic information-> provides compiler with special instructions on how to handle certian parts of the code

#include <stdio.h>
#include <omp.h>
int main() {
	int x = 0;
	printf("\n Initially , x = %d ,x");

	//parallel region
	omp_set_num_threads(4);
	int nt = omp_get_num_threads();
	//printf("Number of threads are : %d\n", nt);
	//int myid =omp_get_thread_num();
	omp_get_max_threads();
	#pragma omp parallel
	{
		//printf("Hello World! from thread are: %d\n" , omp_get_num_threads());
		//printf("I am thread %d Total number of threads are %d\n",myid,nt);
		int myid = omp_get_thread_num();
		x = x + myid;
		printf("\n Thread %d >>>>> x + myid = %d", myid, x);


	}
	return 0;
 }
//prints 21 Hello world many times , no of times depends on no of threads currently executed
// in c++ we cannot { within functions it should goes to next line
//without pragma omp parallel ---> this will give you one hello world as output