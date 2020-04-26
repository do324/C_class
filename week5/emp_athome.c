/*
Name: Doyeon Kim
Student number: 139766166
Email: do324@naver.com
Workshop: week5
Section:
Date: 6/15/2017
*/

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4	


// Declare Struct Employee
struct Employee
{
	int id, age;
	double salary;
};


/* main program */
int main(void) {

	int id;
	int j=0;
	int i;
	int option = 0;
	int update;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };


	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0 && emp[i].age > 0 && emp[i].salary)
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");


			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");

			if (j < SIZE) {
				
				printf("Enter Employee ID: ");
				scanf("%d", &emp[j].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[j].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[j].salary);
				j++;
				printf("\n");

			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}


			// Check for limits on the array and add employee 
			// data accordingly. 



			break;
		case 3:
			
			printf("Update Employee Salary\n");
			printf("======================\n");
			do{
				printf("Enter Employee ID: ");
				scanf("%d", &update);
				for (i = 0; i < SIZE; i++) {
					if (update == emp[i].id) {
						break;
					}
				}
			   
			} while (update != emp[i].id);
				printf("The current salary is %.2lf\n", emp[i].salary);
				printf("Enter Employee New Salary: ");
				scanf("%lf", &emp[i].salary);
				printf("\n");

			break;
		
		case 4: 
			do {
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &id);
				for (i = 0; i < SIZE; i++) {
					if (id == emp[i].id) {


						break;
					}

				}
			
				}while (update != emp[i].id);
				printf("Employee %d will be removed\n\n", emp[i].id);
				for (j = i; j < SIZE - 1; j++) {
					emp[j] = emp[j + 1];
				}
				emp[SIZE - 1].age = 0, emp[SIZE - 1].id = 0, emp[SIZE - 1].salary = 0;
				break;
				

		
		
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
			
		}
		

	} while (option != 0);


	return 0;
}