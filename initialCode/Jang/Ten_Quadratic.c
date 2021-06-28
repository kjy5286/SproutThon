#define _crt_secure_no_warnings
#include <stdio.h>
#include <math.h>

void QuadraticEquation();
void CubicEquation();

void Ten_Quadratic() {
	int input = 0;

	printf("[10] ���� �������� ������ �� ã���Դϴ�.\n");
	printf(" 1. ���������� \t 2. ����������\n");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		QuadraticEquation();
		break;

	case 2:
		CubicEquation();
		break;

	default:
		printf("�߸��Է��ϼ̽��ϴ�.\n");
		break;
	}
}


void QuadraticEquation() {
	double a, b, c;
	double D;
    double x, y;
	printf("ax2 + bx + c = 0�� �ظ� ���Ϸ��� �մϴ�.\n");
	printf("��� a, b, c�� ���� �Է����ּ���.\n");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	D = b * b - (4 * a * c);
	printf("�Ǻ����� %lf \n", D);

	if (D > 0) //���� 2���� �� 
	{ 
		x = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		y = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf("�ΰ��� ���� %lf�� %lf�̴�. \n", x, y);
	}

	else if (D == 0) //���� 1���� ��
	{
		x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("�߱��� %lf�̴�. \n", x);
	}

	else if (D < 0) //D�� 0���� �����Ƿ� ���� ����.
	{
		printf("���� ����. \n");
	}

}

void CubicEquation() {
    double a, b, c;
    double p, q;
    double D;
    double x, y, z;

    printf("x^3 + ax^2 + bx + c = 0�� �ظ� ���Ϸ��� �մϴ�.");
    printf("��� a, b, c�� ���� �Է����ּ���.\n");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    p = (-a * a / 3.0 + b) / 3.0;
    q = (2.0 * a * a * a / 27.0 - a * b / 3.0 + c) / 2.0;

    D = p * p * p + q * q;
    printf("�Ǻ��� %lf \n", D);

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
        printf("���Ǳ��� %lf, %lf, %lf �Դϴ�.\n", x, y, z);

    }

    else if (D == 0) {
        y = -b / (2.0 * a);
        printf("�ϳ��� �Ǳ� %lf�� �߱� %lf �Դϴ�.\n", x, y);
    }

    else {
        y = (-b / (2.0 * a));
        z = sqrt(abs(D)) / (2.0 * a);
        if (y == 0)
        {
            printf("�ϳ��� �Ǳ� %lf�� �� ���% lfi, %lfi �Դϴ�.\n", x, z, -z);
        }

        else
        {
            printf("�ϳ��� �Ǳ� %lf�� �� ��� %lf% + lfi, %lf% + lfi �Դϴ�.\n", x, y, z, y, -z);
        }
    }
}