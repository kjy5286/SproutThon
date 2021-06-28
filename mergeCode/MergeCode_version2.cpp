#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <string.h>
#include <windows.h>

#define pi 3.141592653589793
 
//ÀûºÐ ±¸Á¶Ã¼ 
typedef struct integElem{
	int count = 500000;
	double x[6] = {0,0,0,0,0,0};
	double sum = 0,a = 0,b = 0,dx = 0;
} integral;
 
void Title() { 
	printf("	  ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                                      Calculator Program                                         ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                               »õ½ÏÅæ - ±Ç¿µ¿í. ±èÇö¼ö, ÀåÇý¿ø Á¶                                ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");  
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     1. »çÄ¢¿¬»ê            2. »ï°¢ÇÔ¼ö °è»ê±â       3. Àý´ë°ª °è»ê±â       4. Áö¼ö°ª °è»ê±â     ¦­\n");  
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     5. ·Î±×°ª °è»ê±â       6. ÆÑÅä¸®¾ó °è»ê±â       7. 8Áø¼ö º¯È¯±â        8. 16Áø¼ö º¯È¯±â     ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     9. ºÎµ¿¼Ò¼öÁ¡ º¯È¯±â   10. ¹æÁ¤½ÄÀÇ ÇØ Ã£±â     11. ´ÙÇ×ÇÔ¼ö ¹ÌºÐ      12. »ï°¢ÇÔ¼ö ¹ÌºÐ    ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     13. ´ÙÇ×ÇÔ¼ö Á¤ÀûºÐ    14. »ï°¢ÇÔ¼ö Á¤ÀûºÐ      15. ¿ÀÀÏ·¯¼ö e °è»ê    16. ÆÄÀÌ °è»ê        ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                                     0. Á¾·á     17. help                                        ¦­\n");
	printf(" 	  ¦­                                                                                                 ¦­\n");  
	printf(" 	  ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
}  

//»çÄ¢¿¬»ê 
int arithOper(){
	printf("\n [01] »çÄ¢ ¿¬»ê±â\n");
	double x,y;
	char op;
	while(1){
		printf("\n µÎ ¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 2 4 : ");
		scanf("%lf %lf",&x,&y);
		rewind(stdin);
		printf("\n ¿¬»êÀÚ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) + : ");
		scanf("%c",&op);
		switch(op){
		    case '+': printf(" %.2lf + %.2lf = %.6lf\n",x,y,x + y); return 0;
		    case '-': printf(" %.2lf - %.2lf = %.6lf\n",x,y,x - y); return 0;
		    case '*': printf(" %.2lf * %.2lf = %.6lf\n",x,y,x * y); return 0;
		    case '/':
			    if(y==0){
				    printf(" \n [ERROR] :: 0À¸·Î´Â ³ª´­ ¼ö ¾ø½À´Ï´Ù ::\n");
				    break;
			    }
			    else{
				    printf(" %.2lf / %.2lf = %.6lf\n",x,y,x / y);
				    return 0; 
			    }
			default: printf("Àß¸øµÈ ¿¬»êÀÚ¸¦ ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù.\n");
	    }
	}
}

//»ï°¢ÇÔ¼ö °è»ê±â
void trigfunc() {
	printf("\n [2] »ï°¢ÇÔ¼ö °è»ê±â\n");
	double angle;
	char tirg[4];
	char sinC[4] = "sin", cosC[4] = "cos", tanC[4] = "tan", cscC[4] = "csc", secC[4] = "sec", cotC[4] = "cot";
	printf("\n »ï°¢ ÇÔ¼öÀÇ Á¾·ù¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) sin : ");
	scanf("%s", tirg);
	rewind(stdin);
	printf("\n °¢µµ(¢ª)¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 60 : ");
	scanf("%lf", &angle);
    double angle1 = angle;
	angle = angle * (pi / 180);
	if(strcmp(tirg,sinC) == 0) printf(" sin(%.2lf) = %.6lf\n",angle1, sin(angle));
	if (strcmp(tirg, cosC) == 0) printf(" cos(%.2lf) = %.6lf\n",angle1, cos(angle));
	if (strcmp(tirg, tanC) == 0) printf(" tan(%.2lf) = %.6lf\n",angle1, tan(angle));
	if (strcmp(tirg, cscC) == 0) printf(" csc(%.2lf) = %.6lf\n",angle1, 1.f / sin(angle));
	if (strcmp(tirg, secC) == 0) printf(" sec(%.2lf) = %.6lf\n",angle1, 1.f / cos(angle));
	if (strcmp(tirg, cotC) == 0) printf(" cot(%.2lf) = %.6lf\n",angle1, 1.f / tan(angle));
} 
 
//Àý´ñ°ª 
void abss() {
	printf("\n [3] Àý´ñ°ª °è»ê±â\n");
	double num;
		printf("\n °ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 1 : ");
		scanf("%lf", &num);
		if (num < 0) {
			printf(" |%.2lf| = %.6lf\n", num, 0 - num);
		}
		else {
			printf(" |%.2lf| = %.6lf\n", num);
		}
		rewind(stdin);
}

//Áö¼ö°ª °è»ê±â
void poww() {
	printf("\n [4] Áö¼ö°ª °è»ê±â\n");
	double x,y;
	printf("\n ¹ØÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 5 : ");
	scanf("%lf",&x); 
	rewind(stdin);
	printf("\n Áö¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
	scanf("%lf",&y); 
	printf(" %.2lf^%.2lf = %.6lf",x,y,pow(x, y));
} 

//·Î±×°ª °è»ê±â 
void Loge();
void Log10();

void Five_Log() {
	int input = 0;

	printf("\n [5] ·Î±×°ª °è»ê±â\n");
	printf(" 1. ÀÚ¿¬·Î±× (¹ØÀÌ eÀÎ ·Î±×)\t 2. »ó¿ë·Î±× (¹ØÀÌ 10ÀÎ ·Î±×)\n");
	scanf("%d", &input);

	switch (input) {
		case 1 :
			Loge();
			break;
 
		case 2 :
			Log10();
			break;

		default :  
			printf(" Àß¸øÀÔ·ÂÇÏ¼Ì½À´Ï´Ù\n");
			break;
	}
}

void Loge() {
	double num;
	printf(" ÀÚ¿¬·Î±×ÀÇ Áö¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
	scanf("%lf", &num);

	printf(" log(%lf)ÀÇ °ªÀº %lfÀÔ´Ï´Ù.\n", num, log(num));
}

void Log10() {
	double num;
	printf(" »ó¿ë·Î±×ÀÇ Áö¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
	scanf("%lf", &num);

	printf(" log10(%lf)ÀÇ °ªÀº %lfÀÔ´Ï´Ù.\n", num, log10(num));
}

//ÆÑÅä¸®¾ó 
unsigned long long factorial(int x){
	if(x < 3){
		return x;
	}
	else{
		return x * factorial(x-1);
	}
}

void factorial2(){
	printf("\n [6] ÆÑÅä¸®¾ó °è»ê±â\n");
	int x;
	printf(" ¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 3 : ");
	scanf("%d",&x);
	unsigned long long n = factorial(x);
	printf(" %d! = %lld",x,n);
}

//8Áø¼ö º¯È¯±â
void Seven_Oct() {
	int num;
	printf("\n [7] 8Áø¼ö º¯È¯±â\n");
	printf(" ¼ýÀÚ(Á¤¼ö)¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
	scanf("%d", &num);
	printf(" %dÀÇ 8Áø¼ö = %o\n",num, num);
}

//16Áø¼ö º¯È¯±â
void Eight_Hex() {
	int num;
	printf("\n [8] 16Áø¼ö º¯È¯±â\n");
	printf(" ¼ýÀÚ(Á¤¼ö)¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
	scanf("%d", &num);
	printf(" %dÀÇ 16Áø¼ö = %X\n",num, num);
} 

//ºÎµ¿¼Ò¼ö  
void floatPoint(){
	printf("\n [9] ºÎµ¿¼Ò¼ö º¯È¯±â\n");
	union{
		unsigned int y;
		float x;
	} input;
	printf(" º¯È¯ÇÒ ¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) 1.5 : ");
	scanf("%f",&(input.x));
	printf("\n %fÀÇ ºÎµ¿¼Ò¼ö -> ",input.x); 
	for(unsigned int m = 0x80000000; m; m>>=1){
		printf("%d",(m & input.y) ? 1 : 0);
	}
}

//±ÙÀÇ °ø½Ä
void QuadraticEquation();
void CubicEquation(); 

void Ten_Quadratic() {
	int input = 0;

	printf("\n [10] ¹æÁ¤½ÄÀÇ ÇØ °è»ê±â\n");
	printf(" 1. ÀÌÂ÷¹æÁ¤½Ä \t 2. »ïÂ÷¹æÁ¤½Ä\n");
	scanf("%d", &input);

	switch (input) {
	case 1:
		QuadraticEquation();
		break;

	case 2:
		CubicEquation();
		break;

	default:
		printf(" \n [ERROR] :: Àß¸øµÈ ¼ö¸¦ ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù ::\n");
		break;
	}
}
 
void QuadraticEquation() {
	double a, b, c;
	double D;
    double x, y, z;
	printf(" ax^2 + bx + c = 0ÀÇ ÇØ¸¦ ±¸ÇÏ·Á°í ÇÕ´Ï´Ù\n");
	printf(" °è¼ö a, b, cÀÇ °ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	D = b * b - (4 * a * c);
	printf(" ÆÇº°½Ä D = %lf \n", D);

	if (D > 0) //±ÙÀÌ 2°³ÀÏ ¶§ 
	{ 
		x = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		y = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf(" µÎ°³ÀÇ ±ÙÀº %lf¿Í %lfÀÔ´Ï´Ù \n", x, y);
	}

	else if (D == 0) //±ÙÀÌ 1°³ÀÏ ¶§
	{
		x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf(" Áß±ÙÀº %lfÀÔ´Ï´Ù \n", x);
	}

	else if (D < 0) //D°¡ 0º¸´Ù ÀÛÀ¸¹Ç·Î ±ÙÀº ¾ø´Ù.
	{
		y = (-b / (2.0 * a));
        z = sqrt(abs(D)) / (2.0 * a);
        if (y == 0)
        {
            printf(" µÎ Çã±Ù% lfi, %lfi ÀÔ´Ï´Ù\n", z, -z);
        }

        else
        {
            printf(" µÎ Çã±Ù %lf% + lfi, %lf% + lfi ÀÔ´Ï´Ù\n", y, z, y, -z);
        }
	}

}

void CubicEquation() {
    double a, b, c;
    double p, q;
    double D;
    double x, y, z;

    printf(" x^3 + ax^2 + bx + c = 0ÀÇ ÇØ¸¦ ±¸ÇÏ·Á°í ÇÕ´Ï´Ù");
    printf(" °è¼ö a, b, cÀÇ °ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    p = (-a * a / 3.0 + b) / 3.0;
    q = (2.0 * a * a * a / 27.0 - a * b / 3.0 + c) / 2.0;

    D = p * p * p + q * q;
    printf(" ÆÇº°½Ä D = %lf \n", D);

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
        printf(" ¼¼½Ç±ÙÀº %lf, %lf, %lf ÀÔ´Ï´Ù\n", x, y, z);

    }

    else if (D == 0) {
        y = -b / (2.0 * a);
        printf(" ÇÏ³ªÀÇ ½Ç±Ù %lf¿Í Áß±Ù %lf ÀÔ´Ï´Ù\n", x, y);
    }

    else {
        y = (-b / (2.0 * a));
        z = sqrt(abs(D)) / (2.0 * a);
        if (y == 0)
        {
            printf(" ÇÏ³ªÀÇ ½Ç±Ù %lf¿Í µÎ Çã±Ù% lfi, %lfi ÀÔ´Ï´Ù\n", x, z, -z);
        }

        else
        {
            printf(" ÇÏ³ªÀÇ ½Ç±Ù %lf¿Í µÎ Çã±Ù %lf% + lfi, %lf% + lfi ÀÔ´Ï´Ù\n", x, y, z, y, -z);
        }
    }
}

//´ÙÇ×½Ä, »ï°¢ÇÔ¼ö ¹ÌºÐ
void diff() {
	printf("\n [11] ´ÙÇ×ÇÔ¼ö ¹ÌºÐ °è»ê±â\n");
	double x[6] = { 0,0,0,0,0,0 };
	double a, b;
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" »ó¼öÇ×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
		else printf(" %dÂ÷ Ç×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ", -i + 5);
		scanf("%lf", &x[i]);
	}
	printf("d/dx(");
	for(int i = 0; i<6;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^5",x[0]);
				else if(i==5) printf(" + %lf",x[5]); 
				else printf(" + %lfx^%d",x[i],-i+5);
			}
		}  
	printf(") = ");  
	for(int i = 0; i<5;i++){
		if(x[i] != 0.f){
			if(i==0) printf("%lfx^4",5*x[0]);
			else if(i==4) printf(" + %lf",x[4]); 
			else printf(" + %lfx^%d",(-i +5)*x[i],-i+4);
		}
	}
}

void diff2() {
	printf("\n [12] »ï°¢ÇÔ¼ö ¹ÌºÐ °è»ê±â\n");
	double x[6] = { 0,0,0,0,0,0 };
	int select;
	printf(" 1. »çÀÎÇÔ¼ö ¹ÌºÐ\n2. ÄÚ»çÀÎÇÔ¼ö ¹ÌºÐ\n¼±ÅÃ :");
	scanf("%d", &select);
	for (int i = 0; i < 6; i++) {
		if (i == 5) printf(" »ó¼öÇ×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
		else printf(" %dÂ÷ Ç×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ", -i + 5);
		scanf("%lf", &x[i]);
	}
	if (select == 1) {
		printf("d/dx(sin(");
		for(int i = 0; i<6;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^5",x[0]);
				else if(i==5) printf(" + %lf",x[5]); 
				else printf(" + %lfx^%d",x[i],-i+5);
			}
		}
		printf(")) = "); 
		printf(" cos(");
		for(int i = 0; i<6;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^5",x[0]);
				else if(i==5) printf(" + %lf",x[5]); 
				else printf(" + %lfx^%d",x[i],-i+5);
			}
		}
		printf(") * (");
		for(int i = 0; i<5;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^4",5*x[0]);
				else if(i==4) printf(" + %lf",x[4]); 
				else printf(" + %lfx^%d",(-i +5)*x[i],-i+4);
			}
		}
		printf(")");
	}
	else if(select == 2) {
		printf("d/dx(cos("); 
		for(int i = 0; i<6;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^5",x[0]);
				else if(i==5) printf(" + %lf",x[5]); 
				else printf(" + %lfx^%d",x[i],-i+5);
			}
		}
		printf(")) = "); 
		printf(" -sin(");
		for(int i = 0; i<6;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^5",x[0]);
				else if(i==5) printf(" + %lf",x[5]); 
				else printf(" + %lfx^%d",x[i],-i+5);
			}
		}
		printf(") * (");
		for(int i = 0; i<5;i++){
			if(x[i] != 0.f){
				if(i==0) printf("%lfx^4",5*x[0]);
				else if(i==4) printf(" + %lf",x[4]); 
				else printf(" + %lfx^%d",(-i +5)*x[i],-i+4);
			}
		}
		printf(")");
	}
} 

//´ÙÇ×½Ä °è¼ö ÀÔ·Â
void inputCoef(integral* integral){
	for(int i =0;i<6;i++){
		if(i == 5) printf(" »ó¼öÇ×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
		else printf(" %dÂ÷Ç×ÀÇ °è¼ö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ",-i+5);
		scanf("%lf",&integral->x[i]);
	}
} 

//ÀûºÐ °è»ê 
void calSum(double* x,integral* integral,int type = 0){
	for(int i =0; i<integral->count;i++){ 
    	double resultA = (*x)*(pow(integral->a,5))+ (*(x+1))*(pow(integral->a,4))+(*(x+2))*(pow(integral->a,3))+(*(x+3))*(pow(integral->a,2))+(*(x+4))*(integral->a)+ *(x+5);
        double resultB = (*x)*(pow(integral->a+integral->dx,5))+ (*(x+1))*(pow(integral->a+integral->dx,4))+(*(x+2))*(pow(integral->a+integral->dx,3))+(*(x+3))*(pow(integral->a+integral->dx,2))+(*(x+4))*((integral->a+integral->dx))+ *(x+5);
        if(type == 1){
        	resultA = sin(resultA);
			resultB = sin(resultB); 
		}
		else if(type == 2){
			resultA = cos(resultA);
			resultB = cos(resultB);
		}
        integral->sum += (resultA+resultB)/2*integral->dx;
        integral->a += integral->dx;
    }
}

//´ÙÇ×½Ä Á¤ÀûºÐ 
void polyIntegral(){
	printf("\n [13] ´ÙÇ×½Ä Á¤ÀûºÐ °è»ê±â\n");
	integral poly;
	inputCoef(&poly);
	printf(" ÀûºÐ ±¸°£À» ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) [2,4] -> 2 4 : ");
	scanf("%lf %lf",&poly.a,&poly.b);
    poly.dx = (poly.b-poly.a)/poly.count;
    calSum(poly.x,&poly);
	printf("%.5lf",poly.sum);
}

//»ï°¢ÇÔ¼ö Á¤ÀûºÐ
void triIntegral(){
	printf("\n [14] »ï°¢ÇÔ¼ö Á¤ÀûºÐ °è»ê±â\n");
	int select;
	integral tri;
	printf(" 1. »çÀÎÇÔ¼ö 2. ÄÚ»çÀÎ ÇÔ¼ö : ");
	scanf("%d",&select);
	inputCoef(&tri);
	printf(" ÀûºÐ ±¸°£À» ÀÔ·ÂÇØÁÖ¼¼¿ä Ex) [0,3.141591] -> 0 3.141592 : ");
	scanf("%lf %lf",&tri.a,&tri.b);
    tri.dx = (tri.b-tri.a)/tri.count;
    if(select == 1) calSum(tri.x,&tri,1); 
	else calSum(tri.x,&tri,2); 
	printf("%.5lf",tri.sum);
} 

//¿ÀÀÏ·¯¼ö °è»ê
void Fifteen_e(){
	int num, i;
	double j, k;
	k = 1;

	printf("\n [15] ¿ÀÀÏ·¯¼ö e °è»ê±âÀÔ´Ï´Ù\n");
	printf(" ¾ó¸¶³ª °è»êÇÒ±î¿ä? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		j = 1 / double(factorial(i));
		k = k + j;
	}
	printf(" ¿ÀÀÏ·¯ÀÇ ¼ö´Â %lf ÀÔ´Ï´Ù \n", k);
} 

//ÆÄÀÌ °è»ê
void Sixteen_Pie() {
	double PI = 0;
	double temp = 1;
	double p = -1;
	int num, i;

	printf("\n [16] ÆÄÀÌ °è»ê±âÀÔ´Ï´Ù\n");
	printf(" ¾ó¸¶³ª °è»êÇÒ±î¿ä? : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		p *= -1;
		PI += p * 1.0 / temp;
		temp += 2;
	}

	printf(" ÆÄÀÌ´Â %lf ÀÔ´Ï´Ù \n", 4*PI);
}

//help ¸Þ´º
void setColor(int i){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
} 
 
void helpMenu(){
	printf("        ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"); 
	printf("        ¦­                                                                                                     ¦­\n");
	printf("        ¦­                      ¡á      ¡á      ¡á¡á¡á¡á¡á      ¡á              ¡á¡á¡á¡á                       ¦­\n");
	printf("        ¦­                      ¡á      ¡á      ¡á              ¡á              ¡á     ¡á                      ¦­\n");
	printf("        ¦­                      ¡á      ¡á      ¡á              ¡á              ¡á     ¡á                      ¦­\n");
	printf("        ¦­                      ¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á      ¡á              ¡á¡á¡á¡á                       ¦­\n"); 
	printf("        ¦­                      ¡á      ¡á      ¡á              ¡á              ¡á                             ¦­\n");
	printf("        ¦­                      ¡á      ¡á      ¡á              ¡á              ¡á                             ¦­\n");
	printf("        ¦­                      ¡á      ¡á      ¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á      ¡á                             ¦­\n");
	printf("        ¦­                                                                                                     ¦­\n");
	printf("        ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n"); 
}

void menu(){
	printf("        ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"); 
	printf("        ¦­                                                                                                     ¦­\n");
	printf("        ¦­                    ¡á        ¡á      ¡á¡á¡á¡á¡á      ¡á        ¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á¡á    ¡á¡á      ¡á              ¡á¡á      ¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á  ¡á¡á  ¡á      ¡á              ¡á  ¡á    ¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á   ¡á   ¡á      ¡á¡á¡á¡á¡á      ¡á   ¡á   ¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á        ¡á      ¡á              ¡á    ¡á  ¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á        ¡á      ¡á              ¡á      ¡á¡á      ¡á      ¡á                   ¦­\n");
	printf("        ¦­                    ¡á        ¡á      ¡á¡á¡á¡á¡á      ¡á        ¡á        ¡á¡á¡á                     ¦­\n");
	printf("        ¦­                                                                                                     ¦­\n");
	printf("        ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
}

int MenuSelect(); 

void helpRun() {
	int input = 0;

	while ((input = MenuSelect()) != 0) {
		switch (input) {
		case 1:
		    printf(""); 
			break;
		case 2:
			printf("");
			break;
		case 3:
			printf("");
			break;
		case 4:
			printf("");
			break;
		case 5:
			printf("");
			break;
		case 6:
			printf("");
			break;
		case 7:
			printf("");
			break;
		case 8:
			printf("");
			break;
		case 9:
			printf("");
			break;
		case 10:
			printf("");
			break;
		case 11:
			printf("");
			break;
		case 12:
			printf("");
			break;
		case 13:
			printf("");
			break;
		case 14:
			printf("");
			break; 
		case 15:
			printf("");
			break;
		case 16:
			printf("");
			break;
		default :
			printf(" \n [ERROR] :: Àß¸øµÈ ¼ö¸¦ ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù ::\n");
			break;  
		}
		printf("\n ¡ØPress any key to continue¡Ø\n");
		getch();
	}
	setColor(7);
	menu();
	Title(); 
}
 
void HelpTitle() {
    printf("	  ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                                             Help Menu                                           ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                                 »õ½ÏÅæ - ±Ç¿µ¿í. ±èÇö¼ö, ÀåÇý¿ø Á¶                              ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");  
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     1. »çÄ¢¿¬»ê            2. »ï°¢ÇÔ¼ö °è»ê±â       3. Àý´ë°ª °è»ê±â       4. Áö¼ö°ª °è»ê±â     ¦­\n");  
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     5. ·Î±×°ª °è»ê±â       6. ÆÑÅä¸®¾ó °è»ê±â       7. 8Áø¼ö º¯È¯±â        8. 16Áø¼ö º¯È¯±â     ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     9. ºÎµ¿¼Ò¼öÁ¡ º¯È¯±â   10. ¹æÁ¤½ÄÀÇ ÇØ Ã£±â     11. ´ÙÇ×ÇÔ¼ö ¹ÌºÐ      12. »ï°¢ÇÔ¼ö ¹ÌºÐ    ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­     13. ´ÙÇ×ÇÔ¼ö Á¤ÀûºÐ    14. »ï°¢ÇÔ¼ö Á¤ÀûºÐ      15. ¿ÀÀÏ·¯¼ö e °è»ê    16. ÆÄÀÌ °è»ê        ¦­\n");
	printf("	  ¦­                                                                                                 ¦­\n");
	printf("	  ¦­                                           0. µ¹¾Æ°¡±â                                           ¦­\n");
	printf(" 	  ¦­                                                                                                 ¦­\n");  
	printf(" 	  ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
}
 
//¸Þ´º ¼±ÅÃ 
int MenuSelect() {
	int input = 0;
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"); 
    printf("¦­    ¸Þ´º¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä    ¦­\n¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	printf(" => ") ;
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

//¸Þ´º ½ÇÇà 
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
		default :
			printf(" \n [ERROR] :: Àß¸øµÈ ¼ö¸¦ ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù ::\n");
			break;
		}
		printf("\n ¡ØPress any key to continue¡Ø\n");
		getch();
	}
}

//¸ÞÀÎ ÇÔ¼ö  
int main(){
	menu();
	Title();
	MenuRun(); 
	return 0;
}
