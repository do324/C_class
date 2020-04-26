// doyeon kim 139766166 

#include <stdio.h>

int main(void)
{
	int loonie, quarter, dime, nickle, penny, total,GSTint,numint;
	double num;
	double GST;

	printf("please enter the amount to be paid:$");
	scanf("%lf", &num);
	
	GST = num *0.13 + 0.005;
	printf("GST%.2lf\n",GST);
	
	GSTint = GST * 100 + 0.5;
	numint = num * 100 + 0.5;
	
	total = numint + GSTint;
	printf("balance owing: $%.2lf\n", (float)total / 100);

	loonie = total / 100;
	total = total % 100;
	printf("lonnie required %d,balance owing: $%.2lf\n", loonie, (float)total / 100);

	quarter = total / 25;
	total = total % 25;
	printf("quarter required %d, balance owing: $%.2lf\n", quarter, (float)total / 100);
	
	dime = total / 10;
	total = total % 10;
	printf("dime required %d, balance owing; $%.2lf\n", dime, (float)total / 100);

	nickle = total / 5;
	total = total % 5;
	printf("nickle required %d, balance owing: $%.2lf\n", nickle, (float)total / 100);

	penny = total / 1;
	total = total % 1;
	printf("penny required %d, balance owing; $%.2lf\n", penny, (float)total / 100);

	return 0;

}
