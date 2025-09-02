//Serial way----------------------------------------------------------------------
#include <omp.h>
#include <stdio.h>

const int n = 10;

//const int nt = 4;

int main() {
	int a[n] = { 2, 5, 3, 6, 1, 9, 4, 7, 3, 5 };
	int b[n] = { 4, 2, 0, 6, 9, 3, 1, 4, 2, 8 };
	int c = 0;   // = 168

	//#pragma omp parallel num_threads(nt)
	//int myId = omp_get_thread_num();

	for (int i = 0; i < n; i++) {
		c += a[i] * b[i];
	}


	printf("\n Dot product is %d", c);

	return 0;
}
//parallel way---------------------------------------------------------------------
#include <omp.h>
#include <stdio.h>

const int n = 10;

const int nt = 4;

int main() {
	int a[n] = { 2, 5, 3, 6, 1, 9, 4, 7, 3, 5 };
	int b[n] = { 4, 2, 0, 6, 9, 3, 1, 4, 2, 8 };
	int c = 0;   // = 168

#pragma omp parallel num_threads(nt)
{
	int myId = omp_get_thread_num();

	for (int i = myId; i < n; i += nt) {
		c += a[i] * b[i];
	}
}
	printf("\n Dot product is %d", c);

	return 0;
}

-----------------------------------or-------------------------------------
  #include <omp.h>
#include <stdio.h>

const int n = 10;

const int nt = 4;

int main() {
	int a[n] = { 2, 5, 3, 6, 1, 9, 4, 7, 3, 5 };
	int b[n] = { 4, 2, 0, 6, 9, 3, 1, 4, 2, 8 };
	int c = 0;   // = 168
	int r[nt] = { 0 };

#pragma omp parallel num_threads(nt)
{
	int myId = omp_get_thread_num();

	for (int i = myId; i < n; i += nt) {
		r[myId] += a[i] * b[i];
	}
}
	for (int j = 0; j < nt; j++)
		c += r[j];

	printf("\n Dot product is %d", c);

	return 0;
}


