///////////////////////////
// This program is essentially a console version of a shops pos system. It has a function to show information on the program, a function to make purchases of any sized board,
// a function to display the current size and quantity of sizes of boards purchased, and a function to display the total cost of each individual size of board and total cost of the
// entire order. It uses constant variables declared in the functions, this is so the variables can be consistetly updated in each individual function, while the value wont be reset
// every time the function is called.
///////////////////////////

#include <iostream>
#include <string> // declaring all used libraries
#include <iomanip>
#include <fstream>

using namespace std; //declaring the namespace we used so I dont have to type std::, helps code readability

const double smallCost = 175.00;
const double mediumCost = 190.00; //declaring constants - values that dont change
const double largeCost = 200.00;

void printIntroduction() {

	char ch = '*';
	double ln = 70; //these are just some variables for formatting strings: string length, autofill character, and the division int for the centered text.
	double lnt = 6.5;
	string intro = " Welcome to my Johnny Utah's PointBreak Surf Shop ";
	string string1 = "To show program usage 'S'";
	string string2 = "To purchase a surfboard press 'P'"; //declaring all my strings in advance to make code more readable and maniputable. 
	string string3 = "To display current purchases press 'C'";
	string string4 = "To display total amount due press 'T'";
	string string5 = "To quit the program press 'Q'";

	std::cout << std::setfill(ch) << std::setw(ln) << " " << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln / lnt) << " " << intro << std::setfill(ch) << std::setw(ln / lnt) << " " << std::endl; //Printing the intro exactly as shown in the example.
	std::cout << std::setfill(ch) << std::setw(ln) << " " << std::endl << std::endl;

	cout << endl;

	cout << left << string1 << endl;
	cout << left << string2 << endl;
	cout << left << string3 << endl; //This block of strings is displaying the introduction informative paragraph.
	cout << left << string4 << endl;
	cout << left << string5 << endl;
	cout << endl;

}

void ShowUsage() { 

	string string1 = "Entering 'S' shows this help menu.";
	string string2 = "Entering 'P' will ask you to enter a quantity and size of surfboard, for example: '3 m' would order 3 medium surfboards.";
	string string3 = "Entering 'C' will show what and how many surfboards you have bought and what size they are.";
	string string4 = "Entering 'T' will display the total amount of money that you owe for purchased surfboards.";
	string string5 = "Entering 'Q' will quit the program.";

	cout << left << string1 << endl;
	cout << left << string2 << endl;
	cout << left << string3 << endl; //This is the informative paragraph shown in the introduction, but it can be pulled up at any time by the user.
	cout << left << string4 << endl;
	cout << left << string5 << endl;

}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) {

	string string1 = "Please enter quantity and type (S=small, M=medium, L=large) of surfboard(s) you would like to purchase:";
	char size; //again initializing variables.
	int quantity;

	cout << string1;
	cin >> skipws >> quantity >> size; //this inputs our variable quantity and size, but ignores all white spaces. (hence skipws)
	size = tolower(size);

	if (size == 's') {
		iTotalSmall = iTotalSmall + quantity;
	}
	else if (size == 'm') {
		iTotalMedium = iTotalMedium + quantity; //each branch in this if statement adds to the totalquantity constant variable. This tree is what sorts out the small/medium/large options.
	}
	else if (size == 'l') {
		iTotalLarge = iTotalLarge + quantity;
	}

}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

	string string1 = "The total number of small surfboards is ";
	string string2 = "The total number of medium surfboards is "; //again initializing strings
	string string3 = "The total number of large surfboards is ";

	if (iTotalSmall > 0) {

		cout << left << string1 << iTotalSmall << endl;

	}
	if (iTotalMedium > 0) {

		cout << left << string2 << iTotalMedium << endl; //this if statement group is told to print the total quantity of boards purchased, but only if there is a board purchased (quantity > 0)

	}
	if (iTotalLarge > 0) {

		cout << left << string3 << iTotalLarge << endl;

	}

}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

	double smallTotal, mediumTotal, largeTotal, totalTotal = 0;
	string string1 = "The total number of small surfboards is ";
	string string2 = "The total number of medium surfboards is "; //again declaring strings and other used variables
	string string3 = "The total number of large surfboards is ";
	string string4 = " at a total of $";
	string string5 = "Amount due: $";

	cout << fixed << setprecision(2); //setting precision to 2 because i'm dealing with a currency.

	if (iTotalSmall > 0) {

		smallTotal = iTotalSmall * smallCost;
		totalTotal = totalTotal + smallTotal; //if there is a small board sold, then the quantity of boards purchased is multiplied by the current cost of the small boards
		
		cout << left << string1 << iTotalSmall << string4 << smallTotal << endl;

	}
	if (iTotalMedium > 0) {

		mediumTotal = iTotalMedium * mediumCost;
		totalTotal = totalTotal + mediumTotal; //if there is a medium board sold, then the quantity of boards purchased is multiplied by the current cost of the medium boards

		cout << left << string2 << iTotalMedium << string4 << mediumTotal << endl;

	}
	if (iTotalLarge > 0) {

		largeTotal = iTotalLarge * largeCost;
		totalTotal = totalTotal + largeTotal; //if there is a Large board sold, then the quantity of boards purchased is multiplied by the current cost of the Large boards

		cout << left << string3 << iTotalLarge << string4 << largeTotal << endl;

	}

	cout << left << string5 << totalTotal << endl; // prints the overall total of small, medium, and large boards.

}

int main() {

	printIntroduction(); //printing the introduction paragraph.

	char selection = 0;
	int tQSmall = 0;
	int tQMedium = 0; //delcaring values so they can be used as arguments when MakePurchase and DisplayPurchase and Display Total are called, even if its the first choice.
	int tQLarge = 0;
	string string1 = "Please enter selection: ";

	cout << left << string1;
	cin >> selection; //getting user selection
	selection = tolower(selection);

	if (selection == 's') { //this entire if statement tree takes the user selection and outputs the corresponding function as defined in the introduction paragraph.
		ShowUsage();
	}
	else if (selection == 'p') {
		MakePurchase(tQSmall, tQMedium, tQLarge); //taking the current quantity of purchased boards and adding to it depending on user input
	}
	else if (selection == 'c') {
		
		if (tQSmall == 0 && tQMedium == 0 && tQLarge == 0) { //if there are no purchases so far, output that, if there are purchases made output the quantity of sizes currently purchased.
			cout << "No purchases made yet." << endl;
		}
		else {
			DisplayPurchase(tQSmall, tQMedium, tQLarge);
		}

	}
	else if (selection == 't') {
		
		if (tQSmall == 0 && tQMedium == 0 && tQLarge == 0) { //if there are no purchases so far, output that, if there are purchases made output the quantity of sizes, and the total cost of each individual size, and the total cost.
			cout << "No purchases made yet." << endl;
		}
		else {
			DisplayTotal(tQSmall, tQMedium, tQLarge);
		}

	}

	while ((selection) != 'q') {

		char selection;
		string string1 = "\nPlease enter selection: ";

		cout << left << string1;
		cin >> selection;
		selection = tolower(selection);

		if (selection == 's') {
			ShowUsage();
		}
		else if (selection == 'p') {
			MakePurchase(tQSmall, tQMedium, tQLarge);
		}
		else if (selection == 'c') {

			if (tQSmall == 0 && tQMedium == 0 && tQLarge == 0) { //This whole if tree is identical to the one above, it had to be used twice so the user only had to input once the first time
				cout << "No purchases made yet." << endl;
			}
			else {
				DisplayPurchase(tQSmall, tQMedium, tQLarge);
			}

		}
		else if (selection == 't') {

			if (tQSmall == 0 && tQMedium == 0 && tQLarge == 0) {
				cout << "No purchases made yet." << endl;
			}
			else {
				DisplayTotal(tQSmall, tQMedium, tQLarge);
			}

		}

	}
	
	cout << "Thank you" << endl;

}
