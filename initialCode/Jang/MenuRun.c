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
			//1�� �Լ� �ڸ�
			break;

		case 2:
			//2�� �Լ� �ڸ�
			break;

		case 3:
			//3�� �Լ� �ڸ�
			break;

		case 4:
			//4�� �Լ� �ڸ�
			break;

		case 5:
			Five_Log();
			break;

		case 6:
			//6�� �Լ� �ڸ�
			break;

		case 7:
			Seven_Oct();
			break;

		case 8:
			Eight_Hex();
			break;

		case 9:
			//9�� �Լ� �ڸ�
			break;

		case 10:
			Ten_Quadratic();
			break;

		case 11:
			//11�� �Լ� �ڸ�
			break;

		case 12:
			//12�� �Լ� �ڸ�
			break;

		case 13:
			//13�� �Լ� �ڸ�
			break;

		case 14:
			//14�� �Լ� �ڸ�
			break;

		case 15:
			Fifteen_e();
			break;

		case 16:
			Sixteen_Pie();
			break;

		default :
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		printf("\nPress any key to continue\n");
		getch();
	}
}