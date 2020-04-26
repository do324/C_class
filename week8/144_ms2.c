// -------------------------------------------
//  Name:doyeon kim
//  ID:139766166
//  Email:do324@naver.com
//  Description: Milestone #2
// -------------------------------------------


// Copy your milestone #1 source code below
// - Add new function prototypes and definitions
//   for milestone #2 as per the directions
#include <stdio.h>

#define LINEAR 1
#define FORM 0


struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


int menu(void);
double TAX= 0.13;
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

//2

double totalAfterTax(struct Item item) {

	double total;
	if (item.isTaxed == 1) {
		total = (item.quantity * item.price) + (item.quantity * item.price * TAX);
	}
	else if (item.isTaxed == 0) {
		total = item.quantity * item.price;
	}
	return total;
}


int isLowQuantity(struct Item item) {

	int num = 0; 

	if (item.quantity < item.minQuantity) {

		num = 1; 
	}

	return num;

}

struct Item itemEntry(int sku) {

	struct Item item; 

	item.sku = sku; 

	printf("        SKU: %3d\n", item.sku);

	printf("       Name: ");

	scanf("%21[^\n]", item.name); 

	flushKeyboard(); 

	printf("      Price: ");

	item.price = getDouble();

	printf("   Quantity: ");

	item.quantity = getInt();

	printf("Minimum Qty: ");

	item.minQuantity = getInt();

	printf("   Is Taxed: ");

	item.isTaxed = yes();
	return item; 
}


void displayItem(struct Item item, int linear) {

	double total;
	int islow;

	total = totalAfterTax(item); 

	islow = isLowQuantity(item); 

	if (linear != FORM) { 

		printf("|%3d|%-20s|%8.2lf|", item.sku, item.name, item.price);

		if (item.isTaxed == 1)

			printf("  Yes| ");

		else
			printf("   No| ");

		printf("%3d | ", item.quantity);
		printf("%3d |", item.minQuantity);

		printf("%12.2lf|", total);

		if (islow == 1)
			printf("***\n");
		else
			printf("\n");
	}
	else {

		printf("        SKU: %3d\n", item.sku);

		printf("       Name: %-s\n", item.name);

		printf("      Price: %.2lf\n", item.price);

		printf("   Quantity: %d\n", item.quantity);

		printf("Minimum Qty: %d\n", item.minQuantity);

		if (item.isTaxed == 1)
			printf("   Is Taxed: Yes\n");

		else printf("   Is Taxed: No\n");

		if (islow == 1)
			printf("WARNING: Quantity low, please order ASAP!!!\n");

	}
}



void listItems(const struct Item item[], int noOfItems) {

	int n;
	double grand = 0;

	printTitle();

	for (n = 0; n < noOfItems; n++) {

		printf("%-4d", n + 1); 

		displayItem(item[n], LINEAR); 

		grand += totalAfterTax(item[n]);

	}

	printFooter(grand); 
}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	int i;
    int num = 0;

	for (i = 0; i < NoOfRecs; i++) { 

		if (item[i].sku == sku) {

			*index = i;
			num = 1;
		}
	}

	return num;
}



