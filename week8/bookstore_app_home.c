/*
Name: doyeon kim
Student number: 139766166
Email: dkim126@myseneca.ca
Workshop:8
Section:
Date:2017-07-13
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



void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);
void menu();


int main()
{
	int select;
	int	size = 0;

	struct Book book[MAX_BOOKS];

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do {
		menu();
		printf("Select: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			displayInventory(book, size);
			break;
		case 2:
			addBook(book, &size);
			break;
		case 3:
			checkPrice(book, size);
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
		"0) Exit.\n\n");
}


void displayInventory(const struct Book book[], const int size)
{

	int v;
	if (size == 0)
		printf("The inventory is empty!\n");
	else {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for (v = 0; v<size; v++)
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[v]._isbn, book[v]._title, book[v]._year, book[v]._price, book[v]._qty);
	}
	printf("===================================================\n\n");
}


void addBook(struct Book book[], int *size)
{

	int isbn, qty, index;

	printf("ISBN:");
	scanf("%d", &isbn);

	printf("Quantity:");
	scanf("%d", &qty);



	index = searchInventory(book, isbn, *size);

	if (index != -1) {
		printf("The book exists in the repository,"
			" quantity is updated.\n\n");
		book[index]._qty += qty;
	}
	else {
		if (*size>MAX_BOOKS)
			printf("Inventory is full!\n\n");
		else {
			book[*size]._isbn = isbn;
			book[*size]._qty = qty;

			printf("Title:");
			scanf("\n%[^\n]", book[*size]._title);

			printf("Year:");
			scanf("%d", &book[*size]._year);

			printf("Price:");
			scanf("%f", &book[*size]._price);

			*size = *size + 1;
		}
		printf("The book is successfully added to the inventory.\n\n");
	}

}

void checkPrice(const struct Book book[], const int size)
{
	int isbn, index = -1;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn);

	index = searchInventory(book, isbn, size);

	if (index != -1)
		printf("Book %d costs $%.2lf\n\n", isbn, book[index]._price);
	else
		printf("Book does not exist in the bookstore! Please try again.\n\n");

}

int searchInventory(const struct Book book[], const int isbn, const int size)
{
	int index = -1, i;

	for (i = 0; i < size && index == -1; i++) {
		if (book[i]._isbn == isbn)
			index = i;
	}

	return index;

}
