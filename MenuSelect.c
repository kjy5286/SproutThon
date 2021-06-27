#define _crt_secure_no_warnings
#include <stdio.h>

int MenuSelect() {
	int input = 0;
	scanf_s("%d", &input);
	while (input != 0) {
		if (input == 1) return 1;
		else if (input == 2) return 2;
		else if (input == 3) return 3;
		else if (input == 4) return 4;
		else if (input == 5) return 5;
		else if (input == 6) return 6;
		else if (input == 7) return 7;
		else if (input == 8) return 8;
		else if (input == 9) return 9;
		else if (input == 10) return 10;
		else if (input == 11) return 11;
		else if (input == 12) return 12;
		else if (input == 13) return 13;
		else if (input == 14) return 14;
		else if (input == 15) return 15;
		else if (input == 16) return 16;
		else {
			printf("잘못 입력하셨습니다. \n");
			return 99;
		}
		return 0;
	}
}