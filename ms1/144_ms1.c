// Final Project Milestone 1
// Student defined values tester
// Version 1.0
// Date	2017/07/04
// Author	doyeon kim
// Description
// This program test the student implementation of the UI tools
// and Application User Interface for submission.
//
/////////////////////////////////////////////////////////////////


#include <stdio.h>
int menu(void);
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void) {
	printf(
		"Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf(
		"----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal) {
	printf(
		"--------------------------------------------------------+----------------\n");
	if (gTotal > 0.0) {
		printf(
			"                                           Grand Total: |%12.2lf\n",
			gTotal);
	}
}

void flushKeyboard(void) {
	char ch;
	while (scanf("%c", &ch)) {
		if (ch == '\n') {
			break;
		}
	}
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}


int getInt(void) {
	int value = 0;
	char N = 'x';
	while (N != '\n') {
		scanf("%d%c", &value, &N);
		if (N != '\n') {
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	return value;
}


int getIntLimited(int lowerLimit, int upperLimit)
{
	int Value;
	Value = getInt();
	while (Value < lowerLimit || Value > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		scanf("%d", &Value);
	}
	return Value;
}


double getDouble(void) {
	double value = 0;
	char N = 'x';

	while (N != '\n') {
		scanf("%lf%c", &value, &N);

		if (N != '\n') {
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}

	}
	return value;
}


double getDoubleLimited(double lowerLimit, double upperLimit) {
	double value = 0;
	int flag = 1;
	while (flag) {
		value = getDouble();
		if ((value < lowerLimit || value > upperLimit)) {
			printf("Invalid value, %.6lf< value < %.6lf: ", lowerLimit,
				upperLimit);
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	return value;
}


int yes(void) {  
	char CH;
	int INT = 0;
	
	do {
		scanf("%c", &CH);
		flushKeyboard();
		if (CH != 'Y' && CH != 'y' && CH != 'N' && CH != 'n') {
			printf("Only (Y)es or (N)o are acceptable: ");
		}
	} while (CH != 'Y' && CH != 'y' && CH != 'N' && CH != 'n');
	if (CH == 'Y' || CH == 'y') {
		INT = 1;
	}


	return INT;
}
void GroceryInventorySystem(void)
{
	int sel;
	int done = 0;
	welcome();
	while (!done)
	{
		sel = menu();
		if (sel == 1)
		{
			printf("List Items under construction!\n");
			pause();
		}
		else if (sel == 2)
		{
			printf("Search Items under construction!\n");
			pause();
		}
		else if (sel == 3)
		{
			printf("Checkout Item under construction!\n");
			pause();
		}
		else if (sel == 4)
		{
			printf("Stock Item under construction!\n");
			pause();
		}
		else if (sel == 5)
		{
			printf("Add/Update Item under construction!\n");
			pause();
		}
		else if (sel == 6)
		{
			printf("Delete Item under construction!\n");
			pause();
		}
		else if (sel == 7)
		{
			printf("Search by name under construction!\n");
			pause();
		}
		else if (sel == 0)
		{
			printf("Exit the program? (Y)es/(N)o: ");
			done = yes();
		}
	}
}
int menu(void)
{
	int select = 0;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- Delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &select);
	flushKeyboard();
	while (select < 0 || select>7)
	{
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &select);
		flushKeyboard();
	}
	return select;
}
