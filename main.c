#include<stdio.h>                              
#include<windows.h>
#include <time.h>
#include "matrix.h"
int main() {
	time_t start, end;
	Matrix A;
	int vibor;
	printf("Select matrix input option\n");
	printf("1-Command line\n");
	printf("2-File\n");
	printf("3-Random\n");
//	printf("for matrices of order =>12 the determinant will be considered more than a minute\n");
	scanf_s("%d", &vibor);
	if (vibor == 1)
		IntputMatrix(&A);
	if (vibor == 2) {
		FILE* fp;
		fopen_s(&fp, "matrix.txt", "r");
		fscanf_s(fp,"%d", &A.size);
		A.x = (int*)malloc(sizeof(int)*A.size);
		for (int o = 0; o < A.size; o++)
			A.x[o].y= (int*)malloc(sizeof(int)*A.size);
		for (int i = 0; i < A.size; i++)
			for (int j = 0; j < A.size; j++)
				fscanf_s(fp,"%d", &A.x[i].y[j]);
		OutputMatrix(A);
		

	}
	if (vibor == 3) {
		srand(time(0));
		A.size = 2+rand() % 10;
		A.x = (line*)malloc(A.size * sizeof(line*));
		for (int i = 0; i < A.size; i++) {
			A.x[i].y = (int*)malloc(A.size * sizeof(int));
		}
		for (int i = 0; i < A.size; i++) {
			for (int j = 0; j < A.size; j++) {
				A.x[i].y[j] = rand() % 100 - 50;
			}
		}
		OutputMatrix(A);
	}
	if (A.size > 1) {
		volatile long unsigned t;

		start = time(NULL);
		printf("Det=%d\n", Determinant(A));

	}
	else
		printf("Det=%d\n", A.x[0].y[0]);
	Clear(&A);
	end = time(NULL);
	printf("Programm worked %f sec.\n", difftime(end, start));
	int p = 2;
	while (1) {
		A.size = p;
		A.x = (line*)malloc(A.size * sizeof(line*));
		for (int i = 0; i < A.size; i++) {
			A.x[i].y = (int*)malloc(A.size * sizeof(int));
		}
		for (int t = 0; t < p; t++) 
			//A.size = p;
			for (int u = 0; u < p; u++) {
				A.x[t].y[u] = rand() % 10;
			}
		start = time(NULL);
		Determinant(A);
		end = time(NULL);
		Clear(&A);
		if (difftime(end, start) < 60) {
			p++;
			printf("%lf\n",difftime(end, start));
		}
				else {
					printf("time is %lf for matrices of order =>%d the determinant will be considered more than a minute\n", difftime(end, start), p);
					break;
				
		}
	}
	system("pause");
	return 0;
}