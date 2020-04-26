/*
== Vehicle Rentals ==

Author	: Doyeon Kim
Date	: 14-02-2017
Revision: 1.0
Workshop: #6 in-Lab

*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

/* prototype functions addPositive Here*/

double addPositive(double amount, double newAmount);



/* Implement Function addPositive Here*/
double addPositive(double amount, double newAmount) {
	if (newAmount > 0) {
		amount += newAmount;
}
return amount;
}




/* main program */
int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters
   int day;
   double baseprice,kilocost;
   int kilo;
   double charge;

   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

   /*Declare Your Variables Here*/




   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");

         // Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
         // using a loop construct
		 for (i = 0; i < 2; i++) {
			 
				 printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
		 }
		printf("\n");


         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);

         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) {

            // Capture #days for the rental from user input
			 printf("Enter Rental Period (in Days): ");
			 scanf("%d", &day);

            // Calculate the base price (baseDay * Days)
			 baseprice = vRent[flag].baseDay *day;


            // Calculate cost for Kilometers driven using "distRate1 & 2 above"
			 printf("Enter kilometers driven: ");
			 scanf("%d",&kilo);
			 if (kilo >= 0 && kilo <= 100) {
				 kilocost = kilo*distRate1;
	         }
			 else {
				 kilocost = (kilo-100)*distRate2+100*distRate1;
			 }

			 



            // Add base Price and cost for kilometer driven in to a new variable 
            // "charge"
			 charge = baseprice + kilocost;



            /* Call addPositive function with current earnings for the rental and
               charge(calculated above) as arguments and assign the returned
               result back to earnings
            */
			 vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);
			 

            // Display Base Charge, cost for km and the Total 
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
            // Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
			printf("%6.2lf %6.2lf %6.2lf\n\n",baseprice,kilocost,charge);

         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}

/* SAMPLE INPUT/OUTPUT EXPECTED */

/*

***** Rental Vehicle Management App *****

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 123
Enter Rental Period (in Days): 2
Enter kilometers driven: 125

Base   kmCost Total
====== ====== ======
 19.90  81.25 101.15

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 124
Enter Rental Period (in Days): 3
Enter kilometers driven: 79

Base   kmCost Total
====== ====== ======
 59.85  54.51 114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 125
ERROR: Vehicle ID does not exist.

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 1

-- Rental Vehicle Status --

ID#      Earnings
-------- ----------
     123     101.15
     124     114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 0

*/
