/*
Name:doyeon kim
Student number:139766166
Email:dkim126@myseneca.ca
Workshop:workshop7
Section:
Date:2017/07/06
*/

#include <stdio.h>
#define SIZE 3

void decompose(long long number, int *area, int *prefix, int *line);
void decompose(long long number, int *area, int *prefix, int *line) {
	*area = (int)(number / (10000000));
	*prefix = (int)((number % (10000000) / 10000));
	*line = (int)(number % (10000));
}


/* main program */
int main(void) {

	int option;
	long long phoneNumber[SIZE] = { 0LL };
	int area;
	int prefix;
	int line;
	int *a = &area, *p = &prefix, *l = &line;
	int i;
	int c = 0;


	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;



		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for (i = 0; i < SIZE; i++) {
				decompose(phoneNumber[i], &area, &prefix, &line);
				if (phoneNumber[i] > 0) {
					printf("(%3d)-%3d-%4d\n", *a, *p, *l);
				}
			}
			printf("\n");
			break;





		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
			if (c<SIZE) {
				scanf("%lld", &phoneNumber[c]);
				printf("\n");
				c++;
			}
			else {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}
			break;



		default:printf("ERROR: Incorrect Option: Try Again\n\n");

		}

	} while (option != 0);

	return 0;
}

