/* -------------------------------------------
Name: Doyeon Kim
Student number:139766166
Email: dkim126@myseneca.ca
Section: ipc144
Date:
---------------------------------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address
{
	int streetNumber;
	char street[41];
	char postalCode[8];
	int apartmentNumber;
	char city[41];
};


// Structure type Numbers declaration
// Place your code here...
struct Numbers
{
	char cell[21];
	char home[21];
	char business[21];
};

// Structure type Contact declaration
// Place your code here...
struct Contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};
typedef struct Contact Contact;



//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *);

// Get and store from standard input the values for a Contact
// Place your code here...
void getContact(struct Contact *);