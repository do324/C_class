// -------------------------------------------
//  Name: doyeon kim	
//  ID: 139766166
//  Email: dkim126@myseneca.ca
//  Description: Milestone #4
// -------------------------------------------



// Copy your milestone #3 source code below
// - Add new function prototypes and definitions
//   for milestone #4 as per the directions
// Final Project Milestone 3
//doyeon kim

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define TAX 1.13
#define MAX_ITEM_NO 500
#define DATAFILE "items.txt"

void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void pause(void);
void flushKeyboard(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

//4
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);

// user interface tools function Definition:
void welcome(void) {

	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");

}

void printTitle(void) {

	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");

}

void printFooter(double gTotal) {
	if (gTotal > 0) {
		printf("--------------------------------------------------------+----------------\n");
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
	}
}

void pause(void) {

	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

void flushKeyboard(void) {

	while (getchar() != '\n');

}

int getInt(void) {

	char NL;
	int Value;

	do {

		scanf("%d%c", &Value, &NL);

		if (NL != '\n') {

			flushKeyboard();
			printf("Invalid integer, please try again: ");

		}

	} while (NL != '\n');

	return Value;
}
int getIntLimited(int lowerLimit, int upperLimit) {

	int betVal;

	scanf("%d", &betVal);

	while (betVal < lowerLimit || betVal > upperLimit) {

		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		scanf("%d", &betVal);

	}

	return betVal;

}
double getDouble(void) {

	char NL = 'a';
	double Value;

	do {

		scanf("%lf%c", &Value, &NL);


		if (NL != '\n') {

			flushKeyboard();
			printf("Invalid number, please try again: ");

		}
	} while (NL != '\n');

	return Value;

}
double getDoubleLimited(double lowerLimit, double upperLimit) {

	double betweenValue;

	scanf("%lf", &betweenValue);

	while (betweenValue <= lowerLimit || betweenValue >= upperLimit) {

		printf("Invalid value, %0.6lf< value < %0.6lf: ", lowerLimit, upperLimit);
		scanf("%lf", &betweenValue);

	}

	return betweenValue;

}
// application user interface function Definition:
int yes(void) {

	char ch;
	int value;

	scanf(" %c", &ch);

	switch (ch)
	{
	case 'y':

		value = 1;
		break;

	case 'n':

		value = 0;
		break;
	}

	return value;

}

int menu(void)
{
	int Value;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- Delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	scanf("%d", &Value);

	while (0 > Value || Value > 7)
	{

		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &Value);

	}

	return Value;

}

void GroceryInventorySystem(void) {

    struct Item Items[MAX_ITEM_NO];
	int SEL, HoldRecords;
	int done = 0;
	welcome();
	if (0 == loadItems(Items, DATAFILE, &HoldRecords)) {
		printf("Could not read from %s.\n", DATAFILE);

	}
	while (!done)
	{
		SEL = menu();
		if (SEL == 1)
		{

			listItems(Items, HoldRecords);
			pause();
		}
		else if (SEL == 2)
		{

			search(Items, HoldRecords);
			pause();
		}
		else if (SEL == 3)
		{
			adjustQuantity(Items, HoldRecords, CHECKOUT);
			saveItems(Items, DATAFILE, HoldRecords);
			if (0 == saveItems(Items, DATAFILE, HoldRecords)) {
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 4)
		{
			adjustQuantity(Items, HoldRecords, STOCK);
			saveItems(Items, DATAFILE, HoldRecords);
			if (0 == saveItems(Items, DATAFILE, HoldRecords)) {
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 5)
		{
			addOrUpdateItem(Items, &HoldRecords);
			saveItems(Items, DATAFILE, HoldRecords);
			if (0 == saveItems(Items, DATAFILE, HoldRecords)) {
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 6)
		{
			printf("Not implemented!\n");
			pause();
		}
		else if (SEL == 7)
		{
			printf("Not implemented!\n");
			pause();
		}
		else if (SEL == 0)
		{
			printf("Exit the program? (Y)es/(N)o) : ");
			done = yes();
		}
	}
	}
	
	


double totalAfterTax(struct Item item)
{
	double totalAfterTax;

	totalAfterTax = item.price * item.quantity;

	if (item.isTaxed == 1)
	{

		totalAfterTax = totalAfterTax * TAX;

	}


	return totalAfterTax;;
}
int isLowQuantity(struct Item item)
{
	int isLowQuantity = 0;

	if (item.quantity < item.minQuantity)
		isLowQuantity = 1;

	return isLowQuantity;

}
struct Item itemEntry(int sku)
{
	struct Item itemEntry;

	itemEntry.sku = sku;
	printf("        SKU: ");
	itemEntry.sku = getInt();
	//flushKeyboard();

	printf("       Name: ");
	scanf("%20[^\n]", itemEntry.name);
	flushKeyboard();

	printf("      Price: ");
	itemEntry.price = getDouble();

	printf("   Quantity: ");
	itemEntry.quantity = getInt();

	printf("Minimum Qty: ");
	itemEntry.minQuantity = getInt();

	printf("   Is Taxed: ");
	itemEntry.isTaxed = yes();

	return itemEntry;

}
void displayItem(struct Item item, int linear)
{
	double totalTAX;
	double total;
	char* yesOrNo[4];

	if (linear == 1)
	{

		if (item.isTaxed == 0)
		{
			*yesOrNo = "No";
			total = item.price * item.quantity;

			printf("|%d|%-20s|%8.2lf|%5s|%4d |%4d |%12.2lf|", item.sku, item.name, item.price, *yesOrNo, item.quantity, item.minQuantity, total);

			if (item.quantity < item.minQuantity) {
				printf("***\n");
			}
			else {
				printf("\n");
			}

		}
		else if (item.isTaxed == 1)
		{
			*yesOrNo = "Yes";
			totalTAX = item.price * item.quantity * TAX;

			printf("|%d|%-20s|%8.2lf|%5s|%4d |%4d |%12.2lf|", item.sku, item.name, item.price, *yesOrNo, item.quantity, item.minQuantity, totalTAX);

			if (item.quantity < item.minQuantity) {
				printf("***\n");
			}
			else {
				printf("\n");
			}

		}
	}
	else
	{

		if (item.isTaxed == 0)
		{
			*yesOrNo = "No";
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			printf("   Is Taxed: %s\n", *yesOrNo);
			if (item.quantity <= item.minQuantity) printf("WARNING: Quantity low, please order ASAP!!!\n");

		}
		else if (item.isTaxed == 1)
		{
			*yesOrNo = "Yes";
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			printf("   Is Taxed: %s\n", *yesOrNo);
			if (item.quantity <= item.minQuantity) printf("WARNING: Quantity low, please order ASAP!!!\n");

		}

	}
}

void listItems(const struct Item item[], int noOfItems)
{
	int i;
	double gTotal = 0;

	printTitle();

	for (i = 0; i < noOfItems; i++)
	{

		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);

		if (item[i].isTaxed == 0)
		{

			gTotal += item[i].price * item[i].quantity;

		}
		else if (item[i].isTaxed == 1)
		{

			gTotal += totalAfterTax(item[i]);

		}
	}

	printFooter(gTotal);

}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i;
	int Value = 0;

	for (i = 0; i < NoOfRecs; i++)
	{

		if (item[i].sku == sku)
		{

			*index = i;
			Value = 1;

		}

	}

	return Value;

}

//MS3

void search(const struct Item item[], int NoOfRecs)
{
	int tmpSKU;
	int index;

	printf("Please enter the SKU: ");

	tmpSKU = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, NoOfRecs, tmpSKU, &index) == 0)
	{

		printf("Item not found!\n");

	}
	else
	{

		displayItem(item[index], FORM);

	}
}

void updateItem(struct Item* itemptr)
{
	struct Item dummyItem;


	printf("Enter new data:\n");
	dummyItem = itemEntry(itemptr->sku);

	printf("Overwrite old data? (Y)es/(N)o: ");

	if (yes() == 1)
	{

		flushKeyboard();
		*itemptr = dummyItem;
		printf("--== Updated! ==--\n");

	}
	else
	{

		flushKeyboard();
		printf("--== Aborted! ==--\n");

	}

}
void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	struct Item dummyItem;

	if (*NoOfRecs < MAX_ITEM_NO)
	{

		dummyItem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");

		if (yes() == 1)
		{

			item[*NoOfRecs] = dummyItem;
			*NoOfRecs += 1;

			printf("--== Added! ==--\n");

		}
		else
		{

			printf("--== Aborted! ==--\n");

		}
	}
	else
	{

		printf("Can not add new item; Storage Full!\n");

	}
}
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int tmpSKU;
	int index;
	struct Item tmpItem;

	printf("Please enter the SKU: ");
	tmpSKU = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, *NoOfRecs, tmpSKU, &index) == 0)
	{

		addItem(item, NoOfRecs, tmpSKU);

	}
	else
	{
		displayItem(item[index], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes() == 1)
		{
			updateItem(&tmpItem);

			item[index] = tmpItem;

		}
		else
		{
			printf("--== Aborted! ==--\n");
		}

	}

}
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int tmpSKU;
	int index;
	const int ABORTBUTTON = 0;

	printf("Please enter the SKU: ");
	tmpSKU = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, NoOfRecs, tmpSKU, &index) == 0)
	{

		printf("SKU not found in storage!\n");

	}
	else
	{

		displayItem(item[index], FORM);

		if (stock == 1)
		{
			int tmpStocked;
			printf("Please enter the quantity to %s; Maximum of %d or 0 to abort: ", "stock", MAX_QTY - item[index].quantity);
			tmpStocked = getIntLimited(ABORTBUTTON, MAX_QTY - item[index].quantity);
			if (tmpStocked == ABORTBUTTON)
			{

				printf("--== Aborted! ==--\n");

			}
			else
			{
				item[index].quantity += tmpStocked;
				printf("--== Stocked! ==--\n");

			}

		}
		else
		{

			int tmpCheckOut;
			printf("Please enter the quantity to %s; Maximum of %d or 0 to abort: ", "checkout", item[index].quantity);
			tmpCheckOut = getIntLimited(ABORTBUTTON, item[index].quantity);
			if (tmpCheckOut == ABORTBUTTON)
			{

				printf("--== Aborted! ==--\n");

			}
			else
			{
				item[index].quantity -= tmpCheckOut;
				printf("--== Checked out! ==--\n");

			}

			if (item[index].quantity <= item[index].minQuantity)
			{

				printf("Quantity is low, please reorder ASAP!!!\n");

			}

		}

	}

}

void saveItem(struct Item item, FILE* dataFile) {
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}




 
int loadItem(struct Item* item, FILE* dataFile) {

	int retVal = 0;
	int rv = 6;

	if (dataFile != NULL) {
		if (rv == fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name)) {
			retVal = 1;
							
							
		}
	}
	return retVal;
}



int saveItems(const struct Item item[], char fileName[], int NoOfRecs) {
	int i;
	FILE *fp = NULL;
	fp = fopen(fileName, "w");
	int retVal;

	
	if (fp != NULL) {
		for (i = 0; i < NoOfRecs; i++) {
			saveItem(item[i], fp);
			retVal = 1;
		}

		fclose(fp);
	}

	else {
		retVal = 0;
	}
	return retVal;
}

int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr) {
	

	int retVal;
	int temp;
	int i = 0;

	FILE *fp = NULL;
	fp = fopen(fileName, "r");

	if (fp != NULL) {

		temp = loadItem(&item[i], fp);
		while (temp == 1) {
			i++;
			temp = loadItem(&item[i], fp);
		}
		*NoOfRecsPtr = i;
		retVal = 1;
		fclose(fp);
	}

	else {
		retVal = 0;
	}



	return retVal;
}

int main(void) {
	GroceryInventorySystem();
	return 0;
}

