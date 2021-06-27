#define _crt_secure_no_warnings
#include <stdio.h>
#include <math.h>

void QuadraticEquation();
void CubicEquation();

void Ten_Quadratic() {
	int input = 0;

	printf("[10] 근의 공식으로 방정식 근 찾기입니다.\n");
	printf(" 1. 이차방정식 \t 2. 삼차방정식\n");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		QuadraticEquation();
		break;

	case 2:
		CubicEquation();
		break;

	default:
		printf("잘못입력하셨습니다.\n");
		break;
	}
}


void QuadraticEquation() {
	double a, b, c;
	double D;
    double x, y;
	printf("ax2 + bx + c = 0의 해를 구하려고 합니다.\n");
	printf("계수 a, b, c의 값을 입력해주세요.\n");
	scanf_s("%lf %lf %lf", &a, &b, &c);

	D = b * b - (4 * a * c);
	printf("판별식은 %lf \n", D);

	if (D > 0) //근이 2개일 때 
	{ 
		x = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		y = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf("두개의 근은 %lf와 %lf이다. \n", x, y);
	}

	else if (D == 0) //근이 1개일 때
	{
		x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("중근은 %lf이다. \n", x);
	}

	else if (D < 0) //D가 0보다 작으므로 근은 없다.
	{
		printf("근이 없다. \n");
	}

}

void CubicEquation() {
    double a, b, c;
    double p, q;
    double D;
    double x, y, z;

    printf("x^3 + ax^2 + bx + c = 0의 해를 구하려고 합니다.");
    printf("계수 a, b, c의 값을 입력해주세요.\n");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    p = (-a * a / 3.0 + b) / 3.0;
    q = (2.0 * a * a * a / 27.0 - a * b / 3.0 + c) / 2.0;

    D = p * p * p + q * q;
    printf("판별식 %lf \n", D);

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
        printf("세실근은 %lf, %lf, %lf 입니다.\n", x, y, z);

    }

    else if (D == 0) {
        y = -b / (2.0 * a);
        printf("하나의 실근 %lf와 중근 %lf 입니다.\n", x, y);
    }

    else {
        y = (-b / (2.0 * a));
        z = sqrt(abs(D)) / (2.0 * a);
        if (y == 0)
        {
            printf("하나의 실근 %lf와 두 허근% lfi, %lfi 입니다.\n", x, z, -z);
        }

        else
        {
            printf("하나의 실근 %lf와 두 허근 %lf% + lfi, %lf% + lfi 입니다.\n", x, y, z, y, -z);
        }
    }
}