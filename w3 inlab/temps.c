// Name: doyeon kim
// Student Number: 139766166
// Email: do324@naver.com
// Section: 
// Workshop: week 3


#include <stdio.h> 
#define NUMS 3
int main(void)
{
	double average;
	int totalhigh = 0, totallow = 0;
	int day;
	int highvalue, lowvalue;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (day = 1; day < 4; day++)
	{
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &highvalue);
		printf("\n");
		printf("Enter the low value for day %d: ", day);
		scanf("%d", &lowvalue);
		printf("\n");

		while (highvalue > 40 || lowvalue < -40 || highvalue < lowvalue) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Enter the high value for day %d: ", day);
			scanf("%d", &highvalue);
			printf("\n");
			printf("Enter the low value for day %d: ", day);
			scanf("%d", &lowvalue);
			printf("\n");
		}

		totalhigh += highvalue;
		totallow += lowvalue;

	}

	average = (double)(totalhigh + totallow) / 6;
	printf("The average (mean) temperature was: %.2lf\n", average);
	
	return 0;
}
