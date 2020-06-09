#include "matrix.h"
#include <stdio.h>
#include<stdlib.h>
int Determinant(Matrix A) {
	int result = 0;
	int size = A.size;
	int mnojetel;
	if (size > 2) {
		for (int i = 0; i < size; i++) {
			mnojetel = A.x[0].y[i];
			Matrix B;
			B.size = size - 1;
			B.x = (line*)malloc(B.size * sizeof(line*));
			for (int j = 0; j < B.size; j++) {
				B.x[j].y = (int*)malloc(B.size * sizeof(int));
			}
			int y = 0;
			for (int j = 0; j < B.size; j++) {
				for (int k = 0; k < B.size; k++) {
					if (i == y)
						y++;
					B.x[j].y[k] = A.x[j + 1].y[y];
					y++;
				}
				y = 0;
			}
			if ((i + 2) % 2 != 0)
				mnojetel *= -1;
			result = Determinant(B) * mnojetel + result;
			for (int j = 0; j < B.size; j++) {
				free(B.x[j].y);
			}
			free(B.x);
		}
	}
	else {
		result = A.x[0].y[0] * A.x[1].y[1] - A.x[0].y[1] * A.x[1].y[0];
	}
	return result;
}
void IntputMatrix(Matrix* A) {
	scanf_s("%d", &A->size);
	A->x = (line*)malloc(A->size * sizeof(line*));
	for (int i = 0; i < A->size; i++) {
		A->x[i].y = (int*)malloc(A->size * sizeof(int));
	}
	for (int i = 0; i < A->size; i++) {
		for (int j = 0; j < A->size; j++) {
			scanf_s("%d", &A->x[i].y[j]);
		}
	}
	return;
}
void Clear(Matrix* A) {
	for (int i = 0; i < A->size; i++) {
		free(A->x[i].y);
	}
	free(A->x);
	return;
}
void OutputMatrix(Matrix A) {
	for (int i = 0; i < A.size; i++) {
		for (int j = 0; j < A.size; j++) {
			printf("%d ", A.x[i].y[j]);
		}
		printf("\n");
	}
	return;
}