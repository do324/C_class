/* -------------------------------------------
Name: Doyeon Kim
Student number: 139766166
Email: dkim126@myseneca.ca
Section:ipc144
Date:2018/03/10
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"


int main(void)
{
	// Declare variables here:

	struct Name name ;
	struct Address address; 
	struct Numbers num ;
	char choice;
	char prompt;
	char prompt1;

	num.cell[0] = '\0';
	num.home[0] = '\0';
	num.business[0] = '\0';
	
	

	
	// Display the title
	
	printf("Contact Management System\n");
	printf("-------------------------\n");
	
	// Contact Name Input:
	
	printf("Please enter the contact's first name: ");
	scanf("%s", name.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%s", &choice);
	
	if (choice == 'y' || choice == 'Y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name.middleInitial);
	}
	
    printf("Please enter the contact's last name: ");
	scanf("%s", name.lastName);

	
	// Contact Address Input:

	printf("Please enter the contact's street number: ");
	scanf("%d", &address.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%s", address.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%s", &choice);
	
	if (choice == 'y' || choice == 'Y')
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address.apartmentNumber);
	}
	
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address.postalCode);
	printf("Please enter the contact's city: ");
	scanf("%s", address.city);
	
	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &prompt1);

	if (prompt1 == 'y' || prompt1 == 'Y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", num.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %s", &prompt1);
	if (prompt1 == 'y' || prompt1 == 'Y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%s", num.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%s", &prompt);
	if (prompt == 'y' || prompt == 'Y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%s", num.business);
	}

	
	/*printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %s", &choice);
	
	if (choice == 'y' || choice == 'Y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", num.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%s", &choice);
	
	if (choice == 'y' || choice == 'Y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%s", num.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	
	scanf("%s", &choice);
	
	if (choice == 'y' || choice == 'Y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%s", num.business);
	}*/


	// Display Contact Summary Details
	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s", name.firstName);
	printf("\n");
	printf("Middle initial(s): %s", name.middleInitial);
	printf("\n");
	printf("Last name: %s", name.lastName);
	printf("\n\n");
	printf("Address Details\n");
	printf("Street number: %d", address.streetNumber);
	printf("\n");
	printf("Street name: %s", address.street);
	printf("\n");
	printf("Apartment: %d", address.apartmentNumber);
	printf("\n");
	printf("Postal code: %s", address.postalCode);
	printf("\n");
	printf("City: %s", address.city);
	printf("\n\n");
	printf("Phone Numbers:");
	printf("\n");
	printf("Cell phone number: %s", num.cell);
	printf("\n");
	printf("Home phone number: %s", num.home);
	printf("\n");
	printf("Business phone number: %s", num.business);
	printf("\n");
	printf("\n");
	printf("Structure test for Name, Address, and Numbers Done!\n");
	


	

	return 0;
}


