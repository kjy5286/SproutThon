#define _crt_secure_no_warnings
#include <stdio.h>
#include <math.h>

void Loge();
void Log10();

void Five_Log() {
	int input = 0;

	printf("[5] �α� �����Դϴ�.\n");
	printf(" 1. �ڿ��α� (���� e�� �α�)\t 2. ���α� (���� 10�� �α�)\n");
	scanf_s("%d", &input);

	switch (input) {
		case 1 :
			Loge();
			break;

		case 2 :
			Log10();
			break;

		default : 
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			break;
	}
}

void Loge() {
	double num;
	printf("�ڿ��α��� ������ �Է��ϼ���\n");
	scanf_s("%lf", &num);

	printf("log(%lf)�� ���� %lf�Դϴ�.\n", num, log(num));
}

void Log10() {
	double num;
	printf("���α��� ������ �Է��ϼ���\n");
	scanf_s("%lf", &num);

	printf("log10(%lf)�� ���� %lf�Դϴ�.\n", num, log10(num));
}