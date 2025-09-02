//serial way
#include <stdio.h>
#include <omp.h>

long N = 100000000;
double width;

int main()
{
	int i;
	double x, pi = 0.0;
	double start_time, run_time;

	width = 1.0 / (double)N;

	start_time = omp_get_wtime();

	for (i = 0; i < N; i++) {
		x = (i + 0.5) * width;
		pi += 4.0 / (1.0 + x * x) * width;
	}

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}

//[parallel way--------------------------------------------------------------
#include <stdio.h>
#include <omp.h>

long N = 100000000;
double width;
const int nt = 4;

int main()
{
	//int i;
	double x, pi = 0.0;
	double start_time, run_time;
	double sum[nt] = { 0 };

	width = 1.0 / (double)N;

	start_time = omp_get_wtime();
	omp_set_num_threads(nt);

	#pragma omp parallel
	{
		int myId = omp_get_thread_num();

		double X;
		int i;

		for (i = myId; i < N; i += nt) {
			x = (i + 0.5) * width;
			sum[myId] += 4.0 / (1.0 + x * x);
		}
	}
	for (int j = 0; j < nt; j++)
		pi += sum[j]*width;
	

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}

--------------------------------------------------------------------------------

  #include <stdio.h>
#include <omp.h>

long N = 100000000;
double width;
const int nt = 4;

int main()
{
	//int i;
	double x, pi = 0.0;
	double start_time, run_time;
	double sum[nt][0] = { {0} };

	width = 1.0 / (double)N;

	start_time = omp_get_wtime();
	omp_set_num_threads(nt);

	#pragma omp parallel
	{
		int myId = omp_get_thread_num();

		double X;
		int i;

		for (i = myId; i < N; i += nt) {
			x = (i + 0.5) * width;
			sum[myId][0] += 4.0 / (1.0 + x * x);
		}
	}
	for (int j = 0; j < nt; j++)
		pi += sum[j]*width;
	

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}
