#define _crt_secure_no_warnings
#include <stdio.h>

void Eight_Hex() {
	int num;

	printf("[8] 16진수 변환기입니다.\n");
	printf("숫자(정수)를 입력하세요\n");
	scanf_s("%d", &num);

	printf("16진수 : %X\n", num);
}