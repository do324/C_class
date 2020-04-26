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

#include "contacts.h"




// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	int value;
	char NL = 'x';
	do {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');
	return value;
}

// getIntInRange:
int getIntInRange(int lowerBound, int upperBound) {
	int value;
	do {
		value = getInt();

		if (lowerBound > value || upperBound < value) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
		}
	} while (value < lowerBound || value > upperBound);
	return value;
}

// yes:
int yes(void) {
	char choice;
	char new= 0;
	do {
		scanf("%c%c", &choice, &new);
		if (!(choice == 'y' || choice == 'Y' || choice == 'N' || choice == 'n') || new != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			if (new != '\n') clearKeyboard();
		}
	} while (!(choice == 'y' || choice == 'Y' || choice== 'N' || choice == 'n') || new != '\n');
	if (new != '\n') clearKeyboard();
	return choice == 'y' || choice == 'Y';
}

// menu:
int menu(void) {
	int value;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	value = getIntInRange(0, 6);
	printf("\n");
	return value;
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	int choice;
	int exit = 0;
	struct Contact contact[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
  {
	  { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	  {
		  { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } } };

	int num = MAXCONTACTS;

	while (exit == 0)
	{
		choice = menu();
		switch (choice) {
		case 1:
			displayContacts(contact, num);
			pause();
			printf("\n");
			break;

		case 2:
			addContact(contact, num);
			pause();
			printf("\n");
			break;

		case 3:
			updateContact(contact, num);
			pause();
			printf("\n");
			break;

		case 4:
			deleteContact(contact, num);
			pause();
			printf("\n");
			break;

		case 5:
			searchContacts(contact, num);
			pause();
			printf("\n");
			break;

		case 6:
			sortContacts(contact, num);
			pause();
			printf("\n");
			break;

		default:
			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			if (exit == 1) {
				printf("\n");
				printf("Contact Management System: terminated\n");
			}
			printf("\n");
			break;
		}
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
			return i;
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int Total) {
	printf("+-----------------------------------------------------------------------------+\n");

	if (Total >= 0) {
		printf("Total contacts: %d\n\n", Total);
	}
}

// displayContact:
void displayContact(const struct Contact* contact) {
	if (strcmp((*contact).name.middleInitial, "") != 0) {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	if (contact->address.apartmentNumber > 0) {
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else {
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}

}

// displayContacts:
void displayContacts(const struct Contact contact[], int size) {
	int i;
	int total = 0;

	displayContactHeader();

	for (i = 0; i < size; i++) {
		if (strlen(contact[i].numbers.cell)>0)
		{
			displayContact(&contact[i]);

			total = total+1;
		}
	}

	displayContactFooter(total);

}

// searchContacts:
void searchContacts(const struct Contact contact[], int size) {
	int find;
	char phoneNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	find = findContactIndex(contact, size, phoneNum);

	if (find == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		displayContact(&contact[find]);
		printf("\n");
	}
}


// addContact:
void addContact(struct Contact contact[], int size) {
	int i;
	int add = -1;

	for (i = 0; i<size; i++)
	{
		if (strlen(contact[i].numbers.cell) == 0)
		{
			add = i;
			break;
		}
	}
	if (add>-1) {
		getContact(&contact[add]);
		printf("--- New contact added! ---\n");
	}
	else {
		printf("*** ERROR: The contact list is full! ***\n");
	}
}


// updateContact:
void updateContact(struct Contact contact[], int size) {
	char phoneNum[11];
	int find;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	find = findContactIndex(contact, size, phoneNum);

	if (find>-1)
	{
		printf("\nContact found:\n");
		displayContact(&contact[find]);

		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1) {
			getName(&contact[find].name);
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&contact[find].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&contact[find].numbers);
		}

		printf("--- Contact Updated! ---\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}

// deleteContact:
void deleteContact(struct Contact contact[], int size) {
	int find;
	char phoneNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	find = findContactIndex(contact, size, phoneNum);

	if (find == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[find]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1)
		{
			contact[find].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) {
	int i;
	struct Contact temp;

	for (i = 0; i < size - 1; i++)
	{
		if (strcmp(contact[i].numbers.cell, contact[i + 1].numbers.cell) > 0) {
			temp = contact[i + 1];
			contact[i + 1] = contact[i];
			contact[i] = temp;
		}
	}
	printf("--- Contacts sorted! ---\n");
}

