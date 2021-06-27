#define _crt_secure_no_warnings
#include <stdio.h>
#include <math.h>

void Loge();
void Log10();

void Five_Log() {
	int input = 0;

	printf("[5] 로그 계산기입니다.\n");
	printf(" 1. 자연로그 (밑이 e인 로그)\t 2. 상용로그 (밑이 10인 로그)\n");
	scanf_s("%d", &input);

	switch (input) {
		case 1 :
			Loge();
			break;

		case 2 :
			Log10();
			break;

		default : 
			printf("잘못입력하셨습니다.\n");
			break;
	}
}

void Loge() {
	double num;
	printf("자연로그의 지수를 입력하세요\n");
	scanf_s("%lf", &num);

	printf("log(%lf)의 값은 %lf입니다.\n", num, log(num));
}

void Log10() {
	double num;
	printf("상용로그의 지수를 입력하세요\n");
	scanf_s("%lf", &num);

	printf("log10(%lf)의 값은 %lf입니다.\n", num, log10(num));
}