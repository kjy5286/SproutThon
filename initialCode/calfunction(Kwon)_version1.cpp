#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#define pi 3.141592

double abss(double num) {
	if (num < 0) {
		return 0 - num;
	}
	else {
		return num;
	}
}

double trigfunc(char tirg, char angletype, double angle) {
	if (angletype == 'rad') {
		switch (tirg) {
			case 'sin': return sin(angle);
			case 'cos': return cos(angle);
			case 'tan': return tan(angle);
			case 'csc': return 1.f / sin(angle);
			case 'sec': return 1.f / cos(angle);
			case 'cot': return 1.f / tan(angle);
		}
	}
	else if (angletype == 'six') {
		angle = angle * (pi / 180);
		switch (tirg) {
			case 'sin': return sin(angle);
			case 'cos': return cos(angle);
			case 'tan': return tan(angle);
			case 'csc': return 1.f / sin(angle);
			case 'sec': return 1.f / cos(angle);
			case 'cot': return 1.f / tan(angle);
		}
	}
}

double poww(double x, double y) {
	return pow(x, y);
}

void diff() {
	double x[6] = { 0,0,0,0,0,0 };
	double a, b;
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf("상수항의 계수를 입력하세요: ");
		else printf("%d차 항의 계수를 입력하세요: ", -i + 5);
		scanf("%lf", &x[i]);
	}
	printf("%lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf", x[0], x[1], x[2], x[3], x[4]);
}

void diff2() {
	double x[6] = { 0,0,0,0,0,0 };
	int select;
	printf("1. 사인함수 미분\n2. 코사인함수 미분\n선택 :");
	scanf("%d", &select);
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf("상수항의 계수를 입력하세요: ");
		else printf("%d차 항의 계수를 입력하세요: ", -i + 5);
		scanf("%lf", &x[i]);
	}
	if (select == 1) {
		printf("cos(%lfx^5 + %lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf)*(%lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf)", x[0], x[1], x[2], x[3], x[4], x[5], x[0], x[1], x[2], x[3], x[4]);
	}
	else if(select == 2) {
		printf("-sin(%lfx^5 + %lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf)*(%lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf)", x[0], x[1], x[2], x[3], x[4], x[5], x[0], x[1], x[2], x[3], x[4]);
	}
}

int main() {

}