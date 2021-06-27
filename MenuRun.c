#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int MenuSelect();

void Five_Log();
void Seven_Oct();
void Eight_Hex();
void Ten_Quadratic();
void Fifteen_e();
void Sixteen_Pie();

void MenuRun() {
	int input = 0;

	while ((input = MenuSelect()) != 0) {
		switch (input) {
		case 1:
			//1번 함수 자리
			break;

		case 2:
			//2번 함수 자리
			break;

		case 3:
			//3번 함수 자리
			break;

		case 4:
			//4번 함수 자리
			break;

		case 5:
			Five_Log();
			break;

		case 6:
			//6번 함수 자리
			break;

		case 7:
			Seven_Oct();
			break;

		case 8:
			Eight_Hex();
			break;

		case 9:
			//9번 함수 자리
			break;

		case 10:
			Ten_Quadratic();
			break;

		case 11:
			//11번 함수 자리
			break;

		case 12:
			//12번 함수 자리
			break;

		case 13:
			//13번 함수 자리
			break;

		case 14:
			//14번 함수 자리
			break;

		case 15:
			Fifteen_e();
			break;

		case 16:
			Sixteen_Pie();
			break;

		default :
			printf("프로그램을 종료합니다.\n");
			break;
		}
		printf("\nPress any key to continue\n");
		getch();
	}
}