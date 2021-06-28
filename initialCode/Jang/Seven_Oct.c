#define _crt_secure_no_warnings
#include <stdio.h>

void Seven_Oct() {
	int num;

	printf("[7] 8진수 변환기입니다.\n");
	printf("숫자(정수)를 입력하세요\n");
	scanf_s("%d", &num);

	printf("8진수 : %o\n", num);
}