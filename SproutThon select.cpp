#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <string.h>
#include <windows.h>


#define pi 3.141592653589793

//���� ����ü 
typedef struct integElem {
	int count = 500000;
	double x[6] = { 0,0,0,0,0,0 };
	double sum = 0, a = 0, b = 0, dx = 0;
} integral;

void Title() {
	printf("	  ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                      Calculator Program                                         ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                               ������ - �ǿ���. ������, ������ ��                                ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     1. ��Ģ����            2. �ﰢ�Լ� ����       3. ���� ����       4. ������ ����     ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     5. �αװ� ����       6. ���丮�� ����       7. 8���� ��ȯ��        8. 16���� ��ȯ��     ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     9. �ε��Ҽ��� ��ȯ��   10. �������� �� ã��     11. �����Լ� �̺�      12. �ﰢ�Լ� �̺�    ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     13. �����Լ� ������    14. �ﰢ�Լ� ������      15. ���Ϸ��� e ���    16. ���� ���        ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                     0. ����     17. help                                        ��\n");
	printf(" 	  ��                                                                                                 ��\n");
	printf(" 	  ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}

//��Ģ���� 
int arithOper() {
	printf("\n [01] ��Ģ �����\n");
	double x, y;
	char op;
	while (1) {
		printf("\n �� ���� �Է����ּ��� Ex) 2 4 : ");
		scanf("%lf %lf", &x, &y);
		rewind(stdin);
		printf("\n �����ڸ� �Է����ּ��� Ex) + : ");
		scanf("%c", &op);
		switch (op) {
		case '+': printf(" %.2lf + %.2lf = %.6lf\n", x, y, x + y); return 0;
		case '-': printf(" %.2lf - %.2lf = %.6lf\n", x, y, x - y); return 0;
		case '*': printf(" %.2lf * %.2lf = %.6lf\n", x, y, x * y); return 0;
		case '/':
			if (y == 0) {
				printf(" \n [ERROR] :: 0���δ� ���� �� �����ϴ� ::\n");
				break;
			}
			else {
				printf(" %.2lf / %.2lf = %.6lf\n", x, y, x / y);
				return 0;
			}
		default: printf("�߸��� �����ڸ� �Է��ϼ̽��ϴ�.\n");
		}
	}
}

//�ﰢ�Լ� ����
void trigfunc() {
	printf("\n [2] �ﰢ�Լ� ����\n");
	double angle;
	char tirg[4];
	char sinC[4] = "sin", cosC[4] = "cos", tanC[4] = "tan", cscC[4] = "csc", secC[4] = "sec", cotC[4] = "cot";
	printf("\n �ﰢ �Լ��� ������ �Է����ּ��� Ex) sin : ");
	scanf("%s", tirg);
	rewind(stdin);
	printf("\n ����(��)�� �Է����ּ��� Ex) 60 : ");
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

//���� 
void abss() {
	printf("\n [3] ���� ����\n");
	double num;
	printf("\n ���� �Է����ּ��� Ex) 1 : ");
	scanf("%lf", &num);
	if (num < 0) {
		printf(" |%.2lf| = %.6lf\n", num, 0 - num);
	}
	else {
		printf(" |%.2lf| = %.6lf\n", num, num);
	}
	rewind(stdin);
}

//������ ����
void poww() {
	printf("\n [4] ������ ����\n");
	double x, y;
	printf("\n ���� �Է����ּ��� Ex) 5 : ");
	scanf("%lf", &x);
	rewind(stdin);
	printf("\n ������ �Է����ּ��� : ");
	scanf("%lf", &y);
	printf(" %.2lf^%.2lf = %.6lf", x, y, pow(x, y));
}

//�αװ� ���� 
void Loge();
void Log10();

void Five_Log() {
	int input = 0;

	printf("\n [5] �αװ� ����\n");
	printf(" 1. �ڿ��α� (���� e�� �α�)\t 2. ���α� (���� 10�� �α�)\n");
	scanf("%d", &input);

	switch (input) {
	case 1:
		Loge();
		break;

	case 2:
		Log10();
		break;

	default:
		printf(" �߸��Է��ϼ̽��ϴ�\n");
		break;
	}
}

void Loge() {
	double num;
	printf(" �ڿ��α��� ������ �Է����ּ���\n");
	scanf("%lf", &num);

	printf(" log(%lf)�� ���� %lf�Դϴ�.\n", num, log(num));
}

void Log10() {
	double num;
	printf(" ���α��� ������ �Է����ּ���\n");
	scanf("%lf", &num);

	printf(" log10(%lf)�� ���� %lf�Դϴ�.\n", num, log10(num));
}

//���丮�� 
unsigned long long factorial(int x) {
	if (x < 3) {
		return x;
	}
	else {
		return x * factorial(x - 1);
	}
}

void factorial2() {
	printf("\n [6] ���丮�� ����\n");
	int x;
	printf(" ���� �Է����ּ��� Ex) 3 : ");
	scanf("%d", &x);
	unsigned long long n = factorial(x);
	printf(" %d! = %lld", x, n);
}

//8���� ��ȯ��
void Seven_Oct() {
	int num;
	printf("\n [7] 8���� ��ȯ��\n");
	printf(" ����(����)�� �Է����ּ���\n");
	scanf("%d", &num);
	printf(" %d�� 8���� = %o\n", num, num);
}

//16���� ��ȯ��
void Eight_Hex() {
	int num;
	printf("\n [8] 16���� ��ȯ��\n");
	printf(" ����(����)�� �Է����ּ���\n");
	scanf("%d", &num);
	printf(" %d�� 16���� = %X\n", num, num);
}

//�ε��Ҽ�  
void floatPoint() {
	printf("\n [9] �ε��Ҽ� ��ȯ��\n");
	union {
		unsigned int y;
		float x;
	} input;
	printf(" ��ȯ�� ���� �Է����ּ��� Ex) 1.5 : ");
	scanf("%f", &(input.x));
	printf("\n %f�� �ε��Ҽ� -> ", input.x);
	for (unsigned int m = 0x80000000; m; m >>= 1) {
		printf("%d", (m & input.y) ? 1 : 0);
	}
}

//���� ����
void QuadraticEquation();
void CubicEquation();

void Ten_Quadratic() {
	int input = 0;

	printf("\n [10] �������� �� ����\n");
	printf(" 1. ���������� \t 2. ����������\n");
	scanf("%d", &input);

	switch (input) {
	case 1:
		QuadraticEquation();
		break;

	case 2:
		CubicEquation();
		break;

	default:
		printf(" \n [ERROR] :: �߸��� ���� �Է��ϼ̽��ϴ� ::\n");
		break;
	}
}

void QuadraticEquation() {
	double a, b, c;
	double D;
	double x, y, z;
	printf(" ax^2 + bx + c = 0�� �ظ� ���Ϸ��� �մϴ�\n");
	printf(" ��� a, b, c�� ���� �Է����ּ���\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	D = b * b - (4 * a * c);
	printf(" �Ǻ��� D = %lf \n", D);

	if (D > 0) //���� 2���� �� 
	{
		x = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		y = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf(" �ΰ��� ���� %lf�� %lf�Դϴ� \n", x, y);
	}

	else if (D == 0) //���� 1���� ��
	{
		x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf(" �߱��� %lf�Դϴ� \n", x);
	}

	else if (D < 0) //D�� 0���� �����Ƿ� ���� ����.
	{
		y = (-b / (2.0 * a));
		printf("%lf", abs(D));
		z = sqrt(abs((long)(D))) / (2.0 * a);
		if (y == 0)
		{
			printf(" �� ���% lfi, %lfi �Դϴ�\n", z, -z);
		}

		else
		{
			printf(" �� ��� %lf% + lfi, %lf% + lfi �Դϴ�\n", y, z, y, -z);
		}
	}

}

void CubicEquation() {
	double a, b, c;
	double p, q;
	double D;
	double x, y, z;

	printf(" x^3 + ax^2 + bx + c = 0�� �ظ� ���Ϸ��� �մϴ�");
	printf(" ��� a, b, c�� ���� �Է����ּ���\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	p = (-a * a / 3.0 + b) / 3.0;
	q = (2.0 * a * a * a / 27.0 - a * b / 3.0 + c) / 2.0;

	D = p * p * p + q * q;
	printf(" �Ǻ��� D = %lf \n", D);

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
		printf(" ���Ǳ��� %lf, %lf, %lf �Դϴ�\n", x, y, z);

	}

	else if (D == 0) {
		y = -b / (2.0 * a);
		printf(" �ϳ��� �Ǳ� %lf�� �߱� %lf �Դϴ�\n", x, y);
	}

	else {
		y = (-b / (2.0 * a));
		z = sqrt(abs((long)(D))) / (2.0 * a);
		if (y == 0)
		{
			printf(" �ϳ��� �Ǳ� %lf�� �� ���% lfi, %lfi �Դϴ�\n", x, z, -z);
		}

		else
		{
			printf(" �ϳ��� �Ǳ� %lf�� �� ��� %lf% + lfi, %lf% + lfi �Դϴ�\n", x, y, z, y, -z);
		}
	}
}

//���׽�, �ﰢ�Լ� �̺�
void diff() {
	printf("\n [11] �����Լ� �̺� ����\n");
	double x[6] = { 0,0,0,0,0,0 };
	double a, b;
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" ������� ����� �Է����ּ��� : ");
		else printf(" %d�� ���� ����� �Է����ּ��� : ", -i + 5);
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
	printf("\n [12] �ﰢ�Լ� �̺� ����\n");
	double x[6] = { 0,0,0,0,0,0 };
	int select;
	printf(" 1. �����Լ� �̺�\n2. �ڻ����Լ� �̺�\n���� :");
	scanf("%d", &select);
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" ������� ����� �Է��ϼ���: ");
		else printf(" %d�� ���� ����� �Է��ϼ���: ", -i + 5);
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

//���׽� ��� �Է�
void inputCoef(integral* integral) {
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" ������� ����� �Է����ּ��� : ");
		else printf(" %d������ ����� �Է����ּ��� : ", -i + 5);
		scanf("%lf", &integral->x[i]);
	}
}

//���� ��� 
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

//���׽� ������ 
void polyIntegral() {
	printf("\n [13] ���׽� ������ ����\n");
	integral poly;
	inputCoef(&poly);
	printf(" ���� ������ �Է����ּ��� Ex) [2,4] -> 2 4 : ");
	scanf("%lf %lf", &poly.a, &poly.b);
	poly.dx = (poly.b - poly.a) / poly.count;
	calSum(poly.x, &poly);
	printf("%.5lf", poly.sum);
}

//�ﰢ�Լ� ������
void triIntegral() {
	printf("\n [14] �ﰢ�Լ� ������ ����\n");
	int select;
	integral tri;
	printf(" 1. �����Լ� 2. �ڻ��� �Լ� : ");
	scanf("%d", &select);
	inputCoef(&tri);
	printf(" ���� ������ �Է����ּ��� Ex) [0,3.141591] -> 0 3.141592 : ");
	scanf("%lf %lf", &tri.a, &tri.b);
	tri.dx = (tri.b - tri.a) / tri.count;
	if (select == 1) calSum(tri.x, &tri, 1);
	else calSum(tri.x, &tri, 2);
	printf("%.5lf", tri.sum);
}

//���Ϸ��� ���
void Fifteen_e() {
	int num, i;
	double j, k;
	k = 1;

	printf("\n [15] ���Ϸ��� e �����Դϴ�\n");
	printf(" �󸶳� ����ұ��? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		j = 1 / double(factorial(i));
		k = k + j;
	}
	printf(" ���Ϸ��� ���� %lf �Դϴ� \n", k);
}

//���� ���
void Sixteen_Pie() {
	double PI = 0;
	double temp = 1;
	double p = -1;
	int num, i;

	printf("\n [16] ���� �����Դϴ�\n");
	printf(" �󸶳� ����ұ��? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		p *= -1;
		PI += p * 1.0 / temp;
		temp += 2;
	}

	printf(" ���̴� %lf �Դϴ� \n", 4 * PI);
}

//help �޴�
void setColor(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void helpMenu() {
	printf("        ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("        ��                                                                                                     ��\n");
	printf("        ��                      ��      ��      ������      ��              �����                       ��\n");
	printf("        ��                      ��      ��      ��              ��              ��     ��                      ��\n");
	printf("        ��                      ��      ��      ��              ��              ��     ��                      ��\n");
	printf("        ��                      ������      ������      ��              �����                       ��\n");
	printf("        ��                      ��      ��      ��              ��              ��                             ��\n");
	printf("        ��                      ��      ��      ��              ��              ��                             ��\n");
	printf("        ��                      ��      ��      ������      ������      ��                             ��\n");
	printf("        ��                                                                                                     ��\n");
	printf("        ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}

void menu() {
	printf("        ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("        ��                                                                                                     ��\n");
	printf("        ��                    ��        ��      ������      ��        ��      ��      ��                   ��\n");
	printf("        ��                    ���    ���      ��              ���      ��      ��      ��                   ��\n");
	printf("        ��                    ��  ���  ��      ��              ��  ��    ��      ��      ��                   ��\n");
	printf("        ��                    ��   ��   ��      ������      ��   ��   ��      ��      ��                   ��\n");
	printf("        ��                    ��        ��      ��              ��    ��  ��      ��      ��                   ��\n");
	printf("        ��                    ��        ��      ��              ��      ���      ��      ��                   ��\n");
	printf("        ��                    ��        ��      ������      ��        ��        ����                     ��\n");
	printf("        ��                                                                                                     ��\n");
	printf("        ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}

int MenuSelect();

void helpRun() {
	int input = 0;

	while ((input = MenuSelect()) != 0) {
		switch (input) {
		case 1:
			printf(" �̰��� ��Ģ������ �մϴ�. ����, ��Ģ������ �� ���� �Է��մϴ�. �� ��, �����ڸ� �Է¹޾� ������� ��µ˴ϴ�. �����ڰ�   �������� ���, ���� �Է��� ���� ���߿� �Է��� ������ �����ϴ�.\n");
			break;
		case 2:
			printf(" �̰��� �ﰢ�Լ��� ����մϴ�. ����, �ﰢ�Լ��� ������ �����մϴ�. �� ��, �ȿ� �� ����(��)�� �Է¹޾� ������� ���  �˴ϴ�.\n");
			break;
		case 3:
			printf(" �̰��� ������ ����մϴ�. ������ ���� ���� �Է��ϸ� �� ���� ������ ��µ˴ϴ�.\n");
			break;
		case 4:
			printf(" �̰��� �������� ����մϴ�. ����, ���� �Է��մϴ�. �� ��, ������ �Է¹޾� ������� ��µ˴ϴ�.");
			break;
		case 5:
			printf(" �̰��� �αװ��� ����մϴ�. ����, ���α����� �ڿ��α����� �����մϴ�. �� ��, ������ �Է¹޾� ������� ��µ˴ϴ�.\n");
			break;
		case 6:
			printf(" �̰��� ���丮���� ����մϴ�. ���丮���� ���� ���� �Է��ϸ� �� ���� ���丮���� ��µ˴ϴ�.\n");
			break;
		case 7:
			printf(" �̰��� 10����(����)�� 8������ ��ȯ�մϴ�. 8������ ��ȯ�� 10����(����)���� �Է��ϸ� �� ���� 8�������� ��µ˴ϴ�.\n");
			break;
		case 8:
			printf(" �̰��� 10����(����)�� 16������ ��ȯ�մϴ�. 16������ ��ȯ�� 10����(����)���� �Է��ϸ� �� ���� 16�������� ��µ˴ϴ�.\n");
			break;
		case 9:
			printf(" �̰��� 10������ �ε��Ҽ���������� ��ȯ�մϴ�. �ε��Ҽ��� ������� ��ȯ�� 10�������� �Է��ϸ� �� ���� �ε��Ҽ��� ����� ��µ˴ϴ�.\n");
			break;
		case 10:
			printf(" �̰��� �������� �ظ� ã���ϴ�. ����, �������������� �������������� �����մϴ�.(������������ ���, 3������ ����� 1�̴�. ) �� ��, �� ���� ����� �Է��ϸ� �� �������� �Ǻ����� ����� �ذ�  ��µ˴ϴ�.\n");
			break;
		case 11:
			printf(" �̰��� �����Լ��� �̺��մϴ�. ������ ����� ���ʷ� �Է��մϴ�.(5���׺��� ����� ������) �׷���, �� �Լ��� �̺е� ����  ��µ˴ϴ�.\n");
			break;
		case 12:
			printf(" �̰��� �ﰢ�Լ��� �̺��մϴ�. ����, sin�Լ����� cos�Լ����� �����մϴ�. �� ��, �ﰢ�Լ� ���� ���� ������ ����� ���ʷ�  �Է��մϴ�.(5���׺��� ����� ������) �׷���, �� �Լ��� �̺е� ���� ��µ˴ϴ�.\n");
			break;
		case 13:
			printf(" �̰��� �����Լ��� ������ ���� ����մϴ�. �ִ� 5���ױ����� ����� ���� ������ �Է¹ް�, ��ٸ��� ��ġ ������ Ȱ���� ��  �� ����մϴ�.\n");
			break;
		case 14:
			printf(" �̰��� �ﰢ�Լ��� ������ ���� ����մϴ�. �ִ� 5���ױ����� ����� ���� ������ �Է¹ް�[sin(f(x)) ��], ��ٸ��� ��ġ ��  ���� Ȱ���� ���� ����մϴ�.\n");
			break;
		case 15:
			printf(" �̰��� ���Ϸ����� ����մϴ�. �ݺ����� �ݺ� Ƚ���� �Է¹��� ��, ���丮���� Ȱ���� ���Ϸ� �޼��� ���·� ���Ϸ����� ���  �� ����մϴ�.\n");
			break;
		case 16:
			printf(" �̰��� ���̰��� ����մϴ�. �ݺ����� �ݺ� Ƚ���� �Է¹��� ��, ������������ ������ ������ �̿��� �������� ����մϴ�.\n");
			break;
		default:
			printf(" \n [ERROR] :: �߸��� ���� �Է��ϼ̽��ϴ� ::\n");
			break;
		}
		printf("\n ��Press any key to continue��\n");
		getch();
	}
	setColor(7);
	menu();
	Title();
}

void HelpTitle() {
	printf("	  ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                             Help Menu                                           ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                 ������ - �ǿ���. ������, ������ ��                              ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     1. ��Ģ����            2. �ﰢ�Լ� ����       3. ���� ����       4. ������ ����     ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     5. �αװ� ����       6. ���丮�� ����       7. 8���� ��ȯ��        8. 16���� ��ȯ��     ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     9. �ε��Ҽ��� ��ȯ��   10. �������� �� ã��     11. �����Լ� �̺�      12. �ﰢ�Լ� �̺�    ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��     13. �����Լ� ������    14. �ﰢ�Լ� ������      15. ���Ϸ��� e ���    16. ���� ���        ��\n");
	printf("	  ��                                                                                                 ��\n");
	printf("	  ��                                           0. ���ư���                                           ��\n");
	printf(" 	  ��                                                                                                 ��\n");
	printf(" 	  ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}

//�޴� ���� 
int MenuSelect() {
	int input = 0;
	printf("����������������������������������������������������������\n");
	printf("��    �޴��� �������ּ���    ��\n����������������������������������������������������������\n");
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

//�޴� ���� 
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
			printf(" \n [ERROR] :: �߸��� ���� �Է��ϼ̽��ϴ� ::\n");
			break;
		}
		printf("\n ��Press any key to continue��\n");
		getch();

		// �̰� ������ ȭ���� �������ϴ� 
		system("cls");
		menu();
		Title();
	}
}

//���� �Լ�  
int main() {
	menu();
	Title();
	MenuRun();
	return 0;
}
