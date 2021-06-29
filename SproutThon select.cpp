#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <string.h>
#include <windows.h>


#define pi 3.141592653589793

//적분 구조체 
typedef struct integElem {
	int count = 500000;
	double x[6] = { 0,0,0,0,0,0 };
	double sum = 0, a = 0, b = 0, dx = 0;
} integral;

void Title() {
	printf("	  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                      Calculator Program                                         ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                               새싹톤 - 권영욱. 김현수, 장혜원 조                                ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     1. 사칙연산            2. 삼각함수 계산기       3. 절댓값 계산기       4. 지수값 계산기     ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     5. 로그값 계산기       6. 팩토리얼 계산기       7. 8진수 변환기        8. 16진수 변환기     ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     9. 부동소수점 변환기   10. 방정식의 해 찾기     11. 다항함수 미분      12. 삼각함수 미분    ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     13. 다항함수 정적분    14. 삼각함수 정적분      15. 오일러수 e 계산    16. 파이 계산        ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                     0. 종료     17. help                                        ┃\n");
	printf(" 	  ┃                                                                                                 ┃\n");
	printf(" 	  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

//사칙연산 
int arithOper() {
	printf("\n [01] 사칙 연산기\n");
	double x, y;
	char op;
	while (1) {
		printf("\n 두 수를 입력해주세요 Ex) 2 4 : ");
		scanf("%lf %lf", &x, &y);
		rewind(stdin);
		printf("\n 연산자를 입력해주세요 Ex) + : ");
		scanf("%c", &op);
		switch (op) {
		case '+': printf(" %.2lf + %.2lf = %.6lf\n", x, y, x + y); return 0;
		case '-': printf(" %.2lf - %.2lf = %.6lf\n", x, y, x - y); return 0;
		case '*': printf(" %.2lf * %.2lf = %.6lf\n", x, y, x * y); return 0;
		case '/':
			if (y == 0) {
				printf(" \n [ERROR] :: 0으로는 나눌 수 없습니다 ::\n");
				break;
			}
			else {
				printf(" %.2lf / %.2lf = %.6lf\n", x, y, x / y);
				return 0;
			}
		default: printf("잘못된 연산자를 입력하셨습니다.\n");
		}
	}
}

//삼각함수 계산기
void trigfunc() {
	printf("\n [2] 삼각함수 계산기\n");
	double angle;
	char tirg[4];
	char sinC[4] = "sin", cosC[4] = "cos", tanC[4] = "tan", cscC[4] = "csc", secC[4] = "sec", cotC[4] = "cot";
	printf("\n 삼각 함수의 종류를 입력해주세요 Ex) sin : ");
	scanf("%s", tirg);
	rewind(stdin);
	printf("\n 각도(˚)를 입력해주세요 Ex) 60 : ");
	scanf("%lf", &angle);
	double angle1 = angle;
	angle = angle * (pi / 180);
	if (strcmp(tirg, sinC) == 0) printf(" sin(%.2lf) = %.6lf\n", angle1, sin(angle));
	if (strcmp(tirg, cosC) == 0) printf(" cos(%.2lf) = %.6lf\n", angle1, cos(angle));
	if (strcmp(tirg, tanC) == 0) printf(" tan(%.2lf) = %.6lf\n", angle1, tan(angle));
	if (strcmp(tirg, cscC) == 0) printf(" csc(%.2lf) = %.6lf\n", angle1, 1.f / sin(angle));
	if (strcmp(tirg, secC) == 0) printf(" sec(%.2lf) = %.6lf\n", angle1, 1.f / cos(angle));
	if (strcmp(tirg, cotC) == 0) printf(" cot(%.2lf) = %.6lf\n", angle1, 1.f / tan(angle));
}

//절댓값 
void abss() {
	printf("\n [3] 절댓값 계산기\n");
	double num;
	printf("\n 값을 입력해주세요 Ex) 1 : ");
	scanf("%lf", &num);
	if (num < 0) {
		printf(" |%.2lf| = %.6lf\n", num, 0 - num);
	}
	else {
		printf(" |%.2lf| = %.6lf\n", num, num);
	}
	rewind(stdin);
}

//지수값 계산기
void poww() {
	printf("\n [4] 지수값 계산기\n");
	double x, y;
	printf("\n 밑을 입력해주세요 Ex) 5 : ");
	scanf("%lf", &x);
	rewind(stdin);
	printf("\n 지수를 입력해주세요 : ");
	scanf("%lf", &y);
	printf(" %.2lf^%.2lf = %.6lf", x, y, pow(x, y));
}

//로그값 계산기 
void Loge();
void Log10();

void Five_Log() {
	int input = 0;

	printf("\n [5] 로그값 계산기\n");
	printf(" 1. 자연로그 (밑이 e인 로그)\t 2. 상용로그 (밑이 10인 로그)\n");
	scanf("%d", &input);

	switch (input) {
	case 1:
		Loge();
		break;

	case 2:
		Log10();
		break;

	default:
		printf(" 잘못입력하셨습니다\n");
		break;
	}
}

void Loge() {
	double num;
	printf(" 자연로그의 지수를 입력해주세요\n");
	scanf("%lf", &num);

	printf(" log(%lf)의 값은 %lf입니다.\n", num, log(num));
}

void Log10() {
	double num;
	printf(" 상용로그의 지수를 입력해주세요\n");
	scanf("%lf", &num);

	printf(" log10(%lf)의 값은 %lf입니다.\n", num, log10(num));
}

//팩토리얼 
unsigned long long factorial(int x) {
	if (x < 3) {
		return x;
	}
	else {
		return x * factorial(x - 1);
	}
}

void factorial2() {
	printf("\n [6] 팩토리얼 계산기\n");
	int x;
	printf(" 수를 입력해주세요 Ex) 3 : ");
	scanf("%d", &x);
	unsigned long long n = factorial(x);
	printf(" %d! = %lld", x, n);
}

//8진수 변환기
void Seven_Oct() {
	int num;
	printf("\n [7] 8진수 변환기\n");
	printf(" 숫자(정수)를 입력해주세요\n");
	scanf("%d", &num);
	printf(" %d의 8진수 = %o\n", num, num);
}

//16진수 변환기
void Eight_Hex() {
	int num;
	printf("\n [8] 16진수 변환기\n");
	printf(" 숫자(정수)를 입력해주세요\n");
	scanf("%d", &num);
	printf(" %d의 16진수 = %X\n", num, num);
}

//부동소수  
void floatPoint() {
	printf("\n [9] 부동소수 변환기\n");
	union {
		unsigned int y;
		float x;
	} input;
	printf(" 변환할 수를 입력해주세요 Ex) 1.5 : ");
	scanf("%f", &(input.x));
	printf("\n %f의 부동소수 -> ", input.x);
	for (unsigned int m = 0x80000000; m; m >>= 1) {
		printf("%d", (m & input.y) ? 1 : 0);
	}
}

//근의 공식
void QuadraticEquation();
void CubicEquation();

void Ten_Quadratic() {
	int input = 0;

	printf("\n [10] 방정식의 해 계산기\n");
	printf(" 1. 이차방정식 \t 2. 삼차방정식\n");
	scanf("%d", &input);

	switch (input) {
	case 1:
		QuadraticEquation();
		break;

	case 2:
		CubicEquation();
		break;

	default:
		printf(" \n [ERROR] :: 잘못된 수를 입력하셨습니다 ::\n");
		break;
	}
}

void QuadraticEquation() {
	double a, b, c;
	double D;
	double x, y, z;
	printf(" ax^2 + bx + c = 0의 해를 구하려고 합니다\n");
	printf(" 계수 a, b, c의 값을 입력해주세요\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	D = b * b - (4 * a * c);
	printf(" 판별식 D = %lf \n", D);

	if (D > 0) //근이 2개일 때 
	{
		x = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		y = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf(" 두개의 근은 %lf와 %lf입니다 \n", x, y);
	}

	else if (D == 0) //근이 1개일 때
	{
		x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf(" 중근은 %lf입니다 \n", x);
	}

	else if (D < 0) //D가 0보다 작으므로 근은 없다.
	{
		y = (-b / (2.0 * a));
		printf("%lf", abs(D));
		z = sqrt(abs((long)(D))) / (2.0 * a);
		if (y == 0)
		{
			printf(" 두 허근% lfi, %lfi 입니다\n", z, -z);
		}

		else
		{
			printf(" 두 허근 %lf% + lfi, %lf% + lfi 입니다\n", y, z, y, -z);
		}
	}

}

void CubicEquation() {
	double a, b, c;
	double p, q;
	double D;
	double x, y, z;

	printf(" x^3 + ax^2 + bx + c = 0의 해를 구하려고 합니다");
	printf(" 계수 a, b, c의 값을 입력해주세요\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	p = (-a * a / 3.0 + b) / 3.0;
	q = (2.0 * a * a * a / 27.0 - a * b / 3.0 + c) / 2.0;

	D = p * p * p + q * q;
	printf(" 판별식 D = %lf \n", D);

	if (D < 0) {
		x = -2.0 * sqrt(-p) * cos(1.0 / 3.0 * atan(sqrt(-D) / q)) - a / 3.0;
	}

	else if (D == 0)
	{
		x = -2.0 * pow(q, 1.0 / 3.0) - a / 3.0;
	}

	else {
		if (p < 0) {
			x = -pow(q + sqrt(D), 1.0 / 3.0) - pow(q - sqrt(D), 1.0 / 3.0) - a / 3.0;
		}

		else if (p == 0) {
			x = -pow(2.0 * q, 1.0 / 3.0) - a / 3.0;
		}

		else {
			x = pow(-q + sqrt(D), 1.0 / 3.0) - pow(q + sqrt(D), 1.0 / 3.0) - a / 3.0;
		}
	}

	c = (a + x) * x + b;
	b = a + x;
	a = 1.0;
	D = b * b - 4.0 * a * c;

	if (D > 0) {
		y = (-b - sqrt(D)) / (2.0 * a);
		z = (-b + sqrt(D)) / (2.0 * a);
		printf(" 세실근은 %lf, %lf, %lf 입니다\n", x, y, z);

	}

	else if (D == 0) {
		y = -b / (2.0 * a);
		printf(" 하나의 실근 %lf와 중근 %lf 입니다\n", x, y);
	}

	else {
		y = (-b / (2.0 * a));
		z = sqrt(abs((long)(D))) / (2.0 * a);
		if (y == 0)
		{
			printf(" 하나의 실근 %lf와 두 허근% lfi, %lfi 입니다\n", x, z, -z);
		}

		else
		{
			printf(" 하나의 실근 %lf와 두 허근 %lf% + lfi, %lf% + lfi 입니다\n", x, y, z, y, -z);
		}
	}
}

//다항식, 삼각함수 미분
void diff() {
	printf("\n [11] 다항함수 미분 계산기\n");
	double x[6] = { 0,0,0,0,0,0 };
	double a, b;
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" 상수항의 계수를 입력해주세요 : ");
		else printf(" %d차 항의 계수를 입력해주세요 : ", -i + 5);
		scanf("%lf", &x[i]);
	}
	printf("d/dx(");
	for (int i = 0; i < 6; i++) {
		if (x[i] != 0.f) {
			if (i == 0) printf("%lfx^5", x[0]);
			else if (i == 5) printf(" + %lf", x[5]);
			else printf(" + %lfx^%d", x[i], -i + 5);
		}
	}
	printf(") = ");
	for (int i = 0; i < 5; i++) {
		if (x[i] != 0.f) {
			if (i == 0) printf("%lfx^4", 5 * x[0]);
			else if (i == 4) printf(" + %lf", x[4]);
			else printf(" + %lfx^%d", (-i + 5) * x[i], -i + 4);
		}
	}
}

void diff2() {
	printf("\n [12] 삼각함수 미분 계산기\n");
	double x[6] = { 0,0,0,0,0,0 };
	int select;
	printf(" 1. 사인함수 미분\n2. 코사인함수 미분\n선택 :");
	scanf("%d", &select);
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" 상수항의 계수를 입력하세요: ");
		else printf(" %d차 항의 계수를 입력하세요: ", -i + 5);
		scanf("%lf", &x[i]);
	}
	if (select == 1) {
		printf("d/dx(sin(");
		for (int i = 0; i < 6; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^5", x[0]);
				else if (i == 5) printf(" + %lf", x[5]);
				else printf(" + %lfx^%d", x[i], -i + 5);
			}
		}
		printf(")) = ");
		printf(" cos(");
		for (int i = 0; i < 6; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^5", x[0]);
				else if (i == 5) printf(" + %lf", x[5]);
				else printf(" + %lfx^%d", x[i], -i + 5);
			}
		}
		printf(") * (");
		for (int i = 0; i < 5; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^4", 5 * x[0]);
				else if (i == 4) printf(" + %lf", x[4]);
				else printf(" + %lfx^%d", (-i + 5) * x[i], -i + 4);
			}
		}
		printf(")");
	}
	else if (select == 2) {
		printf("d/dx(cos(");
		for (int i = 0; i < 6; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^5", x[0]);
				else if (i == 5) printf(" + %lf", x[5]);
				else printf(" + %lfx^%d", x[i], -i + 5);
			}
		}
		printf(")) = ");
		printf(" -sin(");
		for (int i = 0; i < 6; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^5", x[0]);
				else if (i == 5) printf(" + %lf", x[5]);
				else printf(" + %lfx^%d", x[i], -i + 5);
			}
		}
		printf(") * (");
		for (int i = 0; i < 5; i++) {
			if (x[i] != 0.f) {
				if (i == 0) printf("%lfx^4", 5 * x[0]);
				else if (i == 4) printf(" + %lf", x[4]);
				else printf(" + %lfx^%d", (-i + 5) * x[i], -i + 4);
			}
		}
		printf(")");
	}
}

//다항식 계수 입력
void inputCoef(integral* integral) {
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" 상수항의 계수를 입력해주세요 : ");
		else printf(" %d차항의 계수를 입력해주세요 : ", -i + 5);
		scanf("%lf", &integral->x[i]);
	}
}

//적분 계산 
void calSum(double* x, integral* integral, int type = 0) {
	for (int i = 0; i < integral->count; i++) {
		double resultA = (*x) * (pow(integral->a, 5)) + (*(x + 1)) * (pow(integral->a, 4)) + (*(x + 2)) * (pow(integral->a, 3)) + (*(x + 3)) * (pow(integral->a, 2)) + (*(x + 4)) * (integral->a) + *(x + 5);
		double resultB = (*x) * (pow(integral->a + integral->dx, 5)) + (*(x + 1)) * (pow(integral->a + integral->dx, 4)) + (*(x + 2)) * (pow(integral->a + integral->dx, 3)) + (*(x + 3)) * (pow(integral->a + integral->dx, 2)) + (*(x + 4)) * ((integral->a + integral->dx)) + *(x + 5);
		if (type == 1) {
			resultA = sin(resultA);
			resultB = sin(resultB);
		}
		else if (type == 2) {
			resultA = cos(resultA);
			resultB = cos(resultB);
		}
		integral->sum += (resultA + resultB) / 2 * integral->dx;
		integral->a += integral->dx;
	}
}

//다항식 정적분 
void polyIntegral() {
	printf("\n [13] 다항식 정적분 계산기\n");
	integral poly;
	inputCoef(&poly);
	printf(" 적분 구간을 입력해주세요 Ex) [2,4] -> 2 4 : ");
	scanf("%lf %lf", &poly.a, &poly.b);
	poly.dx = (poly.b - poly.a) / poly.count;
	calSum(poly.x, &poly);
	printf("%.5lf", poly.sum);
}

//삼각함수 정적분
void triIntegral() {
	printf("\n [14] 삼각함수 정적분 계산기\n");
	int select;
	integral tri;
	printf(" 1. 사인함수 2. 코사인 함수 : ");
	scanf("%d", &select);
	inputCoef(&tri);
	printf(" 적분 구간을 입력해주세요 Ex) [0,3.141591] -> 0 3.141592 : ");
	scanf("%lf %lf", &tri.a, &tri.b);
	tri.dx = (tri.b - tri.a) / tri.count;
	if (select == 1) calSum(tri.x, &tri, 1);
	else calSum(tri.x, &tri, 2);
	printf("%.5lf", tri.sum);
}

//오일러수 계산
void Fifteen_e() {
	int num, i;
	double j, k;
	k = 1;

	printf("\n [15] 오일러수 e 계산기입니다\n");
	printf(" 얼마나 계산할까요? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		j = 1 / double(factorial(i));
		k = k + j;
	}
	printf(" 오일러의 수는 %lf 입니다 \n", k);
}

//파이 계산
void Sixteen_Pie() {
	double PI = 0;
	double temp = 1;
	double p = -1;
	int num, i;

	printf("\n [16] 파이 계산기입니다\n");
	printf(" 얼마나 계산할까요? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		p *= -1;
		PI += p * 1.0 / temp;
		temp += 2;
	}

	printf(" 파이는 %lf 입니다 \n", 4 * PI);
}

//help 메뉴
void setColor(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void helpMenu() {
	printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("        ┃                                                                                                     ┃\n");
	printf("        ┃                      ■      ■      ■■■■■      ■              ■■■■                       ┃\n");
	printf("        ┃                      ■      ■      ■              ■              ■     ■                      ┃\n");
	printf("        ┃                      ■      ■      ■              ■              ■     ■                      ┃\n");
	printf("        ┃                      ■■■■■      ■■■■■      ■              ■■■■                       ┃\n");
	printf("        ┃                      ■      ■      ■              ■              ■                             ┃\n");
	printf("        ┃                      ■      ■      ■              ■              ■                             ┃\n");
	printf("        ┃                      ■      ■      ■■■■■      ■■■■■      ■                             ┃\n");
	printf("        ┃                                                                                                     ┃\n");
	printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void menu() {
	printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("        ┃                                                                                                     ┃\n");
	printf("        ┃                    ■        ■      ■■■■■      ■        ■      ■      ■                   ┃\n");
	printf("        ┃                    ■■    ■■      ■              ■■      ■      ■      ■                   ┃\n");
	printf("        ┃                    ■  ■■  ■      ■              ■  ■    ■      ■      ■                   ┃\n");
	printf("        ┃                    ■   ■   ■      ■■■■■      ■   ■   ■      ■      ■                   ┃\n");
	printf("        ┃                    ■        ■      ■              ■    ■  ■      ■      ■                   ┃\n");
	printf("        ┃                    ■        ■      ■              ■      ■■      ■      ■                   ┃\n");
	printf("        ┃                    ■        ■      ■■■■■      ■        ■        ■■■                     ┃\n");
	printf("        ┃                                                                                                     ┃\n");
	printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

int MenuSelect();

void helpRun() {
	int input = 0;

	while ((input = MenuSelect()) != 0) {
		switch (input) {
		case 1:
			printf(" 이것은 사칙연산을 합니다. 먼저, 사칙연산할 두 수를 입력합니다. 그 후, 연산자를 입력받아 결과값이 출력됩니다. 연산자가   나누기일 경우, 먼저 입력한 값을 나중에 입력한 값으로 나눕니다.\n");
			break;
		case 2:
			printf(" 이것은 삼각함수를 계산합니다. 먼저, 삼각함수의 종류를 선택합니다. 그 후, 안에 들어갈 각도(˚)를 입력받아 결과값이 출력  됩니다.\n");
			break;
		case 3:
			printf(" 이것은 절댓값을 계산합니다. 절댓값을 구할 값을 입력하면 그 수의 절댓값이 출력됩니다.\n");
			break;
		case 4:
			printf(" 이것은 지수값을 계산합니다. 먼저, 밑을 입력합니다. 그 후, 지수를 입력받아 결과값이 출력됩니다.");
			break;
		case 5:
			printf(" 이것은 로그값을 계산합니다. 먼저, 상용로그인지 자연로그인지 선택합니다. 그 후, 진수를 입력받아 결과값이 출력됩니다.\n");
			break;
		case 6:
			printf(" 이것은 팩토리얼을 계산합니다. 팩토리얼을 구할 값을 입력하면 그 수의 팩토리얼값이 출력됩니다.\n");
			break;
		case 7:
			printf(" 이것은 10진수(정수)를 8진수로 변환합니다. 8진수로 변환할 10진수(정수)값을 입력하면 그 수의 8진수값이 출력됩니다.\n");
			break;
		case 8:
			printf(" 이것은 10진수(정수)를 16진수로 변환합니다. 16진수로 변환할 10진수(정수)값을 입력하면 그 수의 16진수값이 출력됩니다.\n");
			break;
		case 9:
			printf(" 이것은 10진수를 부동소수점방식으로 변환합니다. 부동소수점 방식으로 변환할 10진수값을 입력하면 그 수의 부동소수점 방식이 출력됩니다.\n");
			break;
		case 10:
			printf(" 이것은 방정식의 해를 찾습니다. 먼저, 이차방정식인지 삼차방정식인지 선택합니다.(삼차방정식일 경우, 3차항의 계수는 1이다. ) 그 후, 각 항의 계수를 입력하면 그 방정식의 판별식의 결과와 해가  출력됩니다.\n");
			break;
		case 11:
			printf(" 이것은 다항함수를 미분합니다. 각항의 계수를 차례로 입력합니다.(5차항부터 상수항 순으로) 그러면, 이 함수의 미분된 식이  출력됩니다.\n");
			break;
		case 12:
			printf(" 이것은 삼각함수를 미분합니다. 먼저, sin함수인지 cos함수인지 선택합니다. 그 후, 삼각함수 안의 식의 각항의 계수를 차례로  입력합니다.(5차항부터 상수항 순으로) 그러면, 이 함수의 미분된 식이 출력됩니다.\n");
			break;
		case 13:
			printf(" 이것은 다항함수의 정적분 값을 계산합니다. 최대 5차항까지의 계수와 적분 구간을 입력받고, 사다리꼴 수치 적분을 활용해 값  을 출력합니다.\n");
			break;
		case 14:
			printf(" 이것은 삼각함수의 정적분 값을 계산합니다. 최대 5차항까지의 계수와 적분 구간을 입력받고[sin(f(x)) 꼴], 사다리꼴 수치 적  분을 활용해 값을 출력합니다.\n");
			break;
		case 15:
			printf(" 이것은 오일러수를 계산합니다. 반복문의 반복 횟수를 입력받은 뒤, 팩토리얼을 활용한 테일러 급수의 형태로 오일러수를 계산  해 출력합니다.\n");
			break;
		case 16:
			printf(" 이것은 파이값을 계산합니다. 반복문의 반복 횟수를 입력받은 뒤, 라이프니츠가 정리한 계산식을 이용해 원주율을 출력합니다.\n");
			break;
		default:
			printf(" \n [ERROR] :: 잘못된 수를 입력하셨습니다 ::\n");
			break;
		}
		printf("\n ※Press any key to continue※\n");
		getch();
	}
	setColor(7);
	menu();
	Title();
}

void HelpTitle() {
	printf("	  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                             Help Menu                                           ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                 새싹톤 - 권영욱. 김현수, 장혜원 조                              ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     1. 사칙연산            2. 삼각함수 계산기       3. 절댓값 계산기       4. 지수값 계산기     ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     5. 로그값 계산기       6. 팩토리얼 계산기       7. 8진수 변환기        8. 16진수 변환기     ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     9. 부동소수점 변환기   10. 방정식의 해 찾기     11. 다항함수 미분      12. 삼각함수 미분    ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃     13. 다항함수 정적분    14. 삼각함수 정적분      15. 오일러수 e 계산    16. 파이 계산        ┃\n");
	printf("	  ┃                                                                                                 ┃\n");
	printf("	  ┃                                           0. 돌아가기                                           ┃\n");
	printf(" 	  ┃                                                                                                 ┃\n");
	printf(" 	  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

//메뉴 선택 
int MenuSelect() {
	int input = 0;
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃    메뉴를 선택해주세요    ┃\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf(" => ");
	scanf("%d", &input);
	rewind(stdin);
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
		else if (input == 17) return 17;
		else {
			return 99;
		}
		return 0;
	}
}

//메뉴 실행 
void MenuRun() {
	int input = 0;

	while ((input = MenuSelect()) != 0) {
		switch (input) {
		case 1:
			arithOper();
			break;

		case 2:
			trigfunc();
			break;

		case 3:
			abss();
			break;

		case 4:
			poww();
			break;

		case 5:
			Five_Log();
			break;

		case 6:
			factorial2();
			break;

		case 7:
			Seven_Oct();
			break;

		case 8:
			Eight_Hex();
			break;

		case 9:
			floatPoint();
			break;

		case 10:
			Ten_Quadratic();
			break;

		case 11:
			diff();
			break;

		case 12:
			diff2();
			break;

		case 13:
			polyIntegral();
			break;

		case 14:
			triIntegral();
			break;

		case 15:
			Fifteen_e();
			break;

		case 16:
			Sixteen_Pie();
			break;
		case 17:
			setColor(3);
			helpMenu();
			HelpTitle();
			helpRun();
			break;
		default:
			printf(" \n [ERROR] :: 잘못된 수를 입력하셨습니다 ::\n");
			break;
		}
		printf("\n ※Press any key to continue※\n");
		getch();

		// 이걸 넣으면 화면이 지워집니당 
		system("cls");
		menu();
		Title();
	}
}

//메인 함수  
int main() {
	menu();
	Title();
	MenuRun();
	return 0;
}
