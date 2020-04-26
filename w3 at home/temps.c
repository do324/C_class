// Name: doyeon kim
// Student Number: 139766166
// Email: do324@naver.com
// Section: 
// Workshop: week 3


#include <stdio.h> 
#define NUMS 4
int main(void)
{
	double average;
	int totalhigh = 0, totallow = 0;
	int day;
	int highvalue, lowvalue;
	int highest = -41, lowest = 41;
	int highday;
	int lowday;


	printf("---=== IPC Temperature Analyzer ===---\n");

	for (day = 0; day < NUMS; day++)
	{
		printf("Enter the high value for day %d: ", day+1);
		scanf("%d", &highvalue);
		printf("\n");
		printf("Enter the low value for day %d: ", day+1);
		scanf("%d", &lowvalue);
		printf("\n");


		while (highvalue > 40 || lowvalue < -40 || highvalue < lowvalue) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Enter the high value for day %d: ", day+1);
			scanf("%d", &highvalue);
			printf("\n");
			printf("Enter the low value for day %d: ", day+1);
			scanf("%d", &lowvalue);
			printf("\n");
		}

		if (highvalue > highest) {
			highest = highvalue;
			highday = day + 1;
		}
		
		if (lowvalue < lowest) {
			lowest = lowvalue;
			lowday = day + 1;
		}

		totalhigh += highvalue;
		totallow += lowvalue;

	}
	
	average = (double)(totalhigh + totallow) / (NUMS*2);
	printf("The average (mean) temperature was: %.2lf\n", average);
	printf("The highest temperature was %d, on day %d\n", highest, highday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday);
	return 0;
}
