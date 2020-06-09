#include<stdio.h>                              
#include<windows.h>
#include <time.h>
#include "matrix.h"
int main() {
	Matrix A;
	int vibor;
	printf("Select matrix input option\n");
	printf("1-Command line\n");
	printf("2-File\n");
	printf("3-Random\n");
	scanf_s("%d", &vibor);
	if (vibor == 1)
		IntputMatrix(&A);
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
	if (A.size>1)
		printf("Det=%d\n", Determinant(A));
	else
		printf("Det=%d\n", A.x[0].y[0]);
	Clear(&A);
	system("pause");
	return 0;
}