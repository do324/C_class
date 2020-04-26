//doyeon kim
//139766166

#include <stdio.h>

int main(void) {

	int day;
	int daynum;
	int highTemps[10];
	int lowTemps[10];
	int highest = 0;
	int lowest = 0;
	int highday;
	int lowday;
	int number;
	
	double average[10];
	int sumH = 0, sumL = 0;



	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &daynum);
	printf("\n");

    while (daynum <3  || daynum >10 ) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &daynum);
		printf("\n");		
	}
	
	
	for (day = 0; day < daynum; day++) 
	{
	
		printf("Day %d - High: ", day + 1);
		scanf("%d",&highTemps[day]);

		printf("Day %d - Low: ", day + 1);
		scanf("%d", &lowTemps[day]);


		
		if (highTemps[day] > highest) {
			highest = highTemps[day];
			highday = day + 1;
		}

		if (lowTemps[day] < lowest) {
			lowest = lowTemps[day];
			lowday = day + 1;
		}
		
		sumH += highTemps[day];
		sumL += lowTemps[day];
		average[day] = (double)(sumH + sumL) / ((day + 1) * 2);
	}
	
	printf("\n");
	printf("Day  Hi  Low\n");
	
	

	for (day = 0; day < daynum; day++) {
		printf("%d %4d %5d\n", day + 1, highTemps[day], 
lowTemps[day]);	
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, highday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday);

	printf("\n");
	printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &number);
	printf("\n");
	

	while (number < 1 || number >4) {
		printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
		scanf("%d", &number);
		printf("\n");
	}



		while (number > 0) {
			printf("The average temperature up to day %d is: %.2lf\n", number, average[number - 1]);
			printf("\n");

			printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
			scanf("%d", &number);
			printf("\n");
		}

		printf("Goodbye!\n");





		return 0;
	}




