/* -------------------------------------------
Name: Doyeon Kim
Student number: 139766166
Email: dkim126@myseneca.ca
Section:
Date: 2018-04-07
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"



// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:

void getName(Name *name) {
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name->middleInitial);
		clearKeyboard();
	}
	else {
		name->middleInitial[0] = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", name->lastName);
	clearKeyboard();
}


void getAddress(Address *address) {
	do {
		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();
	} while (address->streetNumber <= 0);


	printf("Please enter the contact's street name: ");
	
	scanf("%40[^\n]%*c", address->street);
	

	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes()) {
		do {
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &address->apartmentNumber);
		} while (address->apartmentNumber <= 0);
	}
	else {
		address->apartmentNumber = '\0';
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", address->city);
	clearKeyboard();
}



// getNumbers:
void getNumbers(Numbers *numbers) {
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");

	
	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else {
		numbers->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");

	
	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else {
		numbers->business[0] = '\0';
	}
}
// getContact:
void getContact(struct Contact *contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
