#define _crt_secure_no_warnings
#include <stdio.h>

void Eight_Hex() {
	int num;

	printf("[8] 16���� ��ȯ���Դϴ�.\n");
	printf("����(����)�� �Է��ϼ���\n");
	scanf_s("%d", &num);

	printf("16���� : %X\n", num);
}