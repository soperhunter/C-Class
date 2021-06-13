//////////////////////////////////
// This program is a shipping calculator that takes the current shipping prices and adds them to your order's total.
// If the object is fragile it will add a $2 fee. It will then print you a receipt with all the information both calculated
// and given.
//////////////////////////////////

#include <iostream> //Declaring basic libraries 
#include <iomanip>
#include <fstream>
#include <string>


using namespace std; //Using standard namespace

const string Week3Data = "Week3Data.txt"; //imporitng the InputFile

int main()
{
    ifstream fInstream; //initiating the input
    ofstream fOutStream; //initiating the output

    fInstream.open(Week3Data); //Opening the Initiated Input
    if (!fInstream) {
        cout << "Error in Opening File:" << endl;
        return 1;
    }
    fOutStream.open("Output.txt");
    

    /////////////////////////Actual Code Body

    double usa1;
    double usa2;
    double usa3;
    double can1;
    double can2; //initializing variables so we can input our data to them
    double can3;
    double aus1;
    double aus2;
    double aus3;
    double mars1;
    double mars2;
    double mars3;

    fInstream >> usa1 >> usa2 >> usa3 >> can1 >> can2 >> can3 >> aus1 >> aus2 >> aus3 >> mars1 >> mars2 >> mars3; //inputing data from file into variables

    string Intro = "ITCS 2530 - Programming Assignment for week #3";
    string string1 = "Please enter the item name (no spaces)";
    string string2 = "Is the item fragile? (y-yes/n-no)";
    string string3 = "Please enter your order total";
    string string4 = "Please enter desitination. (USA/CAN/AUS)";  //Declaring all of my strings as variables so they can
    string string5 = "Your item is";                              //be properly manipulated later.
    string string6 = "Your shipping cost is"; 
    string string7 = "You are shipping to";
    string string8 = "Your total cost including shipping is";
    string Outro = "Thank You!";
    string Error = "Invalid entry, exiting";
    char colon = ':';
    char dollarsign = '$';

    string orderItem;
    char orderFragile; //initializing variables that are more relevant to our inputs/outputs
    string orderLocation;
    double orderCost;
    int alf = 53; //Auto Fill Length

    cout.precision(2); //setting our decimal length to two

    cout << setw(alf) << setfill('.') << " " << endl << setfill(' ') << Intro << endl << setfill(' ') << setw(alf) << setfill('.') << " " << endl;
    cout << endl; //Introduction Output

    cout << left << setw(alf) << string1 << setfill('.');
    cout << colon; //output of frist line
    cin >> orderItem;

    cout << left << setw(alf) << string2 << setfill('.');
    cout << colon;
    cin >> orderFragile; //output of second line
    if (tolower(orderFragile) == 'y' && tolower(orderFragile) == 'n') {
        cout << "Invalid Input, exiting" << endl; //checking to make sure input is valid
        return 1;}


    cout << left << setw(alf) << string3 << setfill('.');
    cout << colon; //output of third line
    cin >> orderCost;

    cout << left << setw(alf) << string4 << setfill('.');
    cout << colon; //output of fourth line
    cin >> orderLocation; cout << endl;

    double shippingCost{};
    double totalCost;

    for (int i = 0; i <= orderLocation.length(); i++) {
        orderLocation[i] = tolower(orderLocation[i]); //A loop to turn the orderlocation into all lowercase
    }

    if (orderLocation != "usa" && orderLocation != "can" && orderLocation != "aus" && orderLocation != "mars") {
        cout << "Invalid Input, exiting" << endl; //checking to make sure the input is valid
        return 1;
    }

    if (orderLocation == "usa") {
        if (orderCost < 50) {
            shippingCost = usa1;}
        else if (orderCost >= 50 || orderCost < 100) {
            shippingCost = usa2;}
        else if (orderCost >= 100 || orderCost < 150) {
            shippingCost = usa3;}
        else {
            shippingCost = 0;}
    }
    else if (orderLocation == "can") {
        if (orderCost < 50) {
            shippingCost = can1;
        }
        else if (orderCost >= 50 || orderCost < 100) {
            shippingCost = can2;                                   //If statements to determine shipping price, we don't need to worry about
        }                                                      //capitilization because we turned the string into lowercase previously.
        else if (orderCost >= 100 || orderCost < 150) {
            shippingCost = can3;
        }
        else {
            shippingCost = 0;
        }
    }
    else if (orderLocation == "aus") {
        if (orderCost < 50) {
            shippingCost = aus1;
        }
        else if (orderCost >= 50 || orderCost < 100) {
            shippingCost = aus2;
        }
        else if (orderCost >= 100 || orderCost < 150) {
            shippingCost = aus3;
        }
        else {
            shippingCost = 0;
        }
    }
    else if (orderLocation == "mars") {
        if (orderCost < 50) {
            shippingCost = mars1;
        }
        else if (orderCost >= 50 || orderCost < 100) {
            shippingCost = mars2;
        }
        else if (orderCost >= 100 || orderCost < 150) {
            shippingCost = mars3;
        }
        else {
            shippingCost = 0;
        }
    }
    else {
        cout << "Invalid Entry, exiting" << endl;
    }
    
    totalCost = orderCost + shippingCost; //calculating the total cost

    if (tolower(orderFragile) == 'y') {
        orderCost = orderCost + 2;  } //adding $2 charge if its fragile

    string string9 = "Your item is";
    string string10 = "Your shipping cost is";
    string string11 = "You are shipping to";
    string string12 = "Your total cost including shipping is";

    alf = alf - 7;
    for (int i = 0; i <= orderLocation.length(); i++) {
        orderLocation[i] = toupper(orderLocation[i]); //Turning phrase to uppercase so it prints all pretty
    }

    cout << left << setw(alf) << string9 << setfill('.') << orderItem << endl;
    cout << left << fixed << setw(alf) << string10 << setfill('.') << dollarsign << shippingCost << endl; //outputting all information given
    cout << left << setw(alf) << string11 << setfill('.') << orderLocation << endl;
    cout << left << fixed << setw(alf) << string12 << setfill('.') << dollarsign << totalCost << endl << endl;

    cout << right << setw(alf) << setfill('-') << "Thank You!" << endl;



    /////////////////////////Actual Code Body

    fInstream.close(); //closing stream
    fOutStream.close();
    return 0; //return zero is a successful build, return 1 above is error
}