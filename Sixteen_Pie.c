#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

void Sixteen_Pie() {
	double pi = 0;
	double temp = 1;
	double p = -1;
	int num, i;

	printf("[16] 파이 계산기입니다.\n");
	printf("얼마나 계산할까요? : ");
	scanf_s("%d", &num);

	for (i = 1; i <= num; i++) {
		p *= -1;
		pi += p * 1.0 / temp;
		temp += 2;
		num++;
	}

	printf("파이는 %lf 입니다. \n", 4*pi);
}