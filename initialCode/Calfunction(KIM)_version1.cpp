#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.141592

typedef struct integElem{
	int count =500000;
	double x[6] = {0,0,0,0,0,0};
	double sum = 0,a = 0,b = 0,dx = 0;
} integral;

//��Ģ���� 
double arithOper(double x,char op, double y){
	switch(op){
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/':
			if(y==0){
				printf("Zero Division Error\n");
				return x;
			}
			else{
				return x / y;
			}
	}
}

//���丮�� 
unsigned long long factorial(int x){
	if(x < 3){
		return x;
	}
	else{
		return x * factorial(x-1);
	}
}

//�ε��Ҽ� 
void floatPoint(float x){
	union{
		unsigned int y;
		float x;
	} input;
	input.x = x;
	
	for(unsigned int m = 0x80000000; m; m>>=1){
		printf("%d",(m & input.y) ? 1 : 0);
	}
}

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

//�����Լ� ������(5�� �����ı���) 
double polyIntegral(){
	integral poly;
	for(int i =0;i<6;i++){
		if(i == 5) printf("������� ����� �Է��ϼ���: ");
		else printf("%d�� ���� ����� �Է��ϼ���: ",-i+5);
		scanf("%lf",&poly.x[i]);
	}
	printf("���� ������ �Է����ּ���. Ex) [2,4] -> 2 4\n");
	scanf("%lf %lf",&poly.a,&poly.b);
    poly.dx = (poly.b-poly.a)/poly.count;
    calSum(poly.x,&poly);
	printf("%.5lf",poly.sum);
	return poly.sum;
}
 
//�ﰢ�Լ� ������(sin(����),cos(����) �ø� ����
double triIntegral(){
	int select;
	integral tri;
	printf("1. �����Լ� ����\n2. �ڻ����Լ� ����\n���� :");
	scanf("%d",&select);
	for(int i =0;i<6;i++){
		if(i == 5) printf("������� ����� �Է��ϼ���: ");
		else printf("%d�� ���� ����� �Է��ϼ���: ",-i+5);
		scanf("%lf",&tri.x[i]);
	}
	printf("���� ������ �Է����ּ���. Ex) [0,3.141591] -> 0 3.141592\n");
	scanf("%lf %lf",&tri.a,&tri.b);
    tri.dx = (tri.b-tri.a)/tri.count;
    if(select == 1) calSum(tri.x,&tri,1); 
	else calSum(tri.x,&tri,2); 
	printf("%.5lf",tri.sum);
	return tri.sum;
}

int main(){
	triIntegral();
	return 0;
}
