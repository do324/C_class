#include <stdio.h>

int main(void){

	double b;
	int l;

	printf("Enter number: ");
	scanf("%lf", &b);
	printf("your number is: %.2lf\n", b);

	l=b/1;
	printf("division 1: %d\n", l);

	return 0;
}
