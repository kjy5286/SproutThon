#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(double n);

void Fifteen_e(){
	int num, i;
	double j, k;
	k = 1;

	printf("[15] ���Ϸ��� e �����Դϴ�.\n");
	printf("�󸶳� ����ұ��? : ");
	scanf_s("%d", &num);

	for (i = 1; i <= num; i++) {
		j = 1 / factorial(i);
		k = k + j;
	}
	printf("���Ϸ��� ���� %lf �Դϴ�. \n", k);
}

double factorial(double n) {
	double i, j;
	j = 1;
	for (i = 1; i <= n; i++) {
		j = j * i;
	}
	return j;
}