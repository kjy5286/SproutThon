#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

void Sixteen_Pie() {
	double pi = 0;
	double temp = 1;
	double p = -1;
	int num, i;

	printf("[16] ���� �����Դϴ�.\n");
	printf("�󸶳� ����ұ��? : ");
	scanf_s("%d", &num);

	for (i = 1; i <= num; i++) {
		p *= -1;
		pi += p * 1.0 / temp;
		temp += 2;
		num++;
	}

	printf("���̴� %lf �Դϴ�. \n", 4*pi);
}