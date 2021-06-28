#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(double n);

void Fifteen_e(){
	int num, i;
	double j, k;
	k = 1;

	printf("[15] 오일러수 e 계산기입니다.\n");
	printf("얼마나 계산할까요? : ");
	scanf_s("%d", &num);

	for (i = 1; i <= num; i++) {
		j = 1 / factorial(i);
		k = k + j;
	}
	printf("오일러의 수는 %lf 입니다. \n", k);
}

double factorial(double n) {
	double i, j;
	j = 1;
	for (i = 1; i <= n; i++) {
		j = j * i;
	}
	return j;
}