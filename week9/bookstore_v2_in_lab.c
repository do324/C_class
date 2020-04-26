/*
Name: doyeon kim
Student number: 139766166
Email: dkim126@myseneca.ca
Workshop:9
Section:	
Date:2017-07-27
*/

#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 25+1

struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};


void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);
void menu();
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);


int main()
{
	int select;
    char filename[] = "144_w9_inventory.txt";
	
	printf("Welcome to the Book Store\n");
	printf("=========================\n");



	do {
		menu();
		printf("Select: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			displayInventory("144_w9_inventory.txt");
			break;
		case 2:
			printf("Not implemented");
			break;

		case 3:
			printf("Not implemented");
			break;

		case 4:
			printf("The total capital is: $%.2f.\n", calculateCapital(filename));
			break;

		case 0:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid input, try again:\n");
			break;
		}


	} while (select != 0);

    
    return 0;
}

void menu()
{
	printf("Please select from the following options:\n"
		"1) Display the inventory.\n"
		"2) Add a book to the inventory.\n"
		"3) Check price.\n"
		"4) Calculate total capital of the store.\n"
		"0) Exit.\n\n");

}



void displayInventory(const char filename[])
{
	struct Book b;
	FILE *fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Error\n");
	}

	else {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		while (readRecord(fp, &b) == 5)
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", b._isbn, b._title, b._year, b._price, b._qty);


		printf("===================================================\n\n");

		fclose(fp);
	}

}





void addBook(const char filename[], struct Book *b2Add)
{
 //Not implemented!
}

void checkPrice(const char filename[],const int isbn2find)
{
    
 //Not implemented!

 
}

/*int searchInventory(FILE *fp,const int isbn2find)
{
//Not implemented!
}*/


float calculateCapital(const char filename[])
{
    
	float total = 0;
	struct Book b2read;
	FILE *fp = NULL;
	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Error\n");
	}
	else {
		while (readRecord(fp, &b2read) == 5)
			total += (b2read._price*b2read._qty);

	}


	return total;
    
}

int readRecord(FILE *fp, struct Book *b2read)
{

	int rv = 0;

	rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]\n", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);
	return rv;
}
