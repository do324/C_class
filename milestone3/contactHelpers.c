/* -------------------------------------------

---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"




//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt function definition goes here:
int getInt(void)
{
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


// getIntInRange function definition goes here:
int getIntInRange(int lowerBound, int upperBound)
{
	int value;
	do {
		value = getInt();

		if (lowerBound > value || upperBound < value) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
		}
	} while (value < lowerBound || value > upperBound);
	return value;
}



// yes function definition goes here:

int yes(void)
{
	char new = '\0';
	char choice;
	int valid = 0;
	do
	{
		scanf("%c%c", &choice, &new);
		if (new != '\n')
		{
			clearKeyboard();
			valid = 0;
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else
		{
			switch (choice)
			{
			case 'y':
			case 'Y':
			case 'n':
			case 'N':
				valid = 1;
				break;
			default:
				valid = 0;
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			}
		}
	} while (new != '\n' || valid != 1);

	if (choice == 'y' || choice == 'Y')
		return 1;
	else
		return 0;
}


// menu function definition goes here:
int menu(void)
{
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


// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void)
{
	int prompt;
	int exit = 0;
	
    while (exit== 0)
	{
		prompt = menu();
		switch (prompt) {
		case 1:
			printf("<<< Feature 1 is unavailable >>>\n\n");
		    pause();
			printf("\n");
			break;

		case 2:
			printf("<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("<<< Feature 5 is unavailable >>>\n\n");
	        pause();
			printf("\n");
			break;

		case 6:
			printf("<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		default:
			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			if (exit == 1) {
				printf("\n");
				printf("Contact Management System: terminated");
			}
			printf("\n");
			break;
		}
	}

}
