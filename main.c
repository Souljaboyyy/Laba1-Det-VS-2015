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
		A.size = rand() % 10;
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
	if (difftime(end, start) > 5)
		printf("The determinant was counted for more than a minute\n");
	system("pause");
	return 0;
}