#pragma once
#ifndef H_MATRIX
#define H_MATRIX
typedef struct {
	int* y;
}line;
typedef struct {
	int size;
	line* x;
}Matrix;
int Determinant(Matrix A);
void IntputMatrix(Matrix* A);
void Clear(Matrix* A);
void OutputMatrix(Matrix A);
#endif