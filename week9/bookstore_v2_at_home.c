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
#define MAX_TITLE_SIZE 30+1

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
	struct Book books;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");



	do {
		menu();
		printf("Select: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			displayInventory(filename);
			break;
		case 2:

			printf("ISBN:");
			scanf("%d", &books._isbn);

			printf("Title:");
			scanf("\n%[^\n]", books._title);

			printf("Year:");
			scanf("%d", &books._year);

			printf("Price:");
			scanf("%f", &books._price);

			printf("Quantity:");
			scanf("%d", &books._qty);
			addBook(filename, &books);


			break;

		case 3:
			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &books._isbn);
			checkPrice(filename, books._isbn);

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
	FILE *fp = NULL;
	int found;
	fp = fopen(filename, "a+");

	if (fp == NULL) {
		printf("Error opening file!\n");
	}
	else {

		found = searchInventory(fp, b2Add->_isbn);

		if (found >= 0) {
			printf("The book exists in the repository!\n\n");
		}
		else {



			fprintf(fp, "%d;%.2lf;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
			printf("The book is successfully added to the inventory.\n\n");

		}

		fclose(fp);
	}

}

void checkPrice(const char filename[], const int isbn2find)
{
	int found = -1;
	struct Book b2read;


	FILE *fp = NULL;
	fp = fopen(filename, "r");


	if (fp == NULL) {
		printf("Error opening file!\n");
	}
	else
	{
		while ((found < 0) && readRecord(fp, &b2read) == 5) {
			if (b2read._isbn == isbn2find) {
				found = 1;
			}
		}

	}


	if (found != -1)
		printf("Book %d costs $%.2lf\n\n", b2read._isbn, b2read._price);
	else
		printf("Book does not exist in the bookstore! Please try again.\n\n");




}

int searchInventory(FILE *fp, const int isbn2find)
{
	
	int found = -1, i = 0;
	struct Book b2read;
	
	if (fp == NULL) {
		return found;
	}
	else {
		rewind(fp);
		while ((found < 0) && readRecord(fp, &b2read) == 5) {
			if (b2read._isbn == isbn2find) {
				found = 1;
			}
			i++;
		}

	}

	return (found < 0) ? found : i;

}



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