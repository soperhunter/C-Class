/////////////////////////////////////////////
// A cheese container can hold 2.76 kg of cheese. Each evening containers are shipped to local stores. The cost of a single container
// is $4.12. The profit from each container is $1.45. This calculator is designed to compute the total amount of containers needed, the cost to produce the containers
// and also the profit from said containers. Note that the amount of containers needed is rounded up because even if we have .12 extra kg of cheese it would need a
// seperate container.
/////////////////////////////////////////////

#include <iostream> //Declaring basic libraries 
#include <iomanip>
#include <fstream>
#include <string>


using namespace std; //Using standard namespace

const string Week2Data = "Week2Data.txt"; //imporitng the InputFile

int main() 
{
    ifstream fInstream; //initiating the input
    ofstream fOutStream; //initiating the output


    fInstream.open(Week2Data); //Opening the Initiated Input
    if (!fInstream) {
        cout << "Error in Opening File:" << endl;
        return 1;
        }

    /////////////////////////Actual Code Body
    
    double storageCapacity; //Declaring all of our variables used for calculations
    int containersRequired;
    double containerCost;
    double totalCost;
    double totalProfit;
    double profit;
    double quantityCheese;
    
    fInstream >> storageCapacity >> containerCost >> profit; //Importing our data into our variables

    cout << setfill('*') << setw(75) << " " << endl;
    cout << setfill('*') << setw(23) << " " << "Welcome to my Cheesy Program" << setfill('*') << setw(23) << " " << endl; //Introduction Paragraph
    cout << setfill('*') << setw(75) << " " << endl << endl << setfill(' ') ;
    
    string s1 = "Please enter the total amount in Kilograms of cheese produced: ";
    cout << left << s1;
    cin >> quantityCheese; //Asking for input
    cout << endl;

    containersRequired = ceil(quantityCheese * storageCapacity); //Calculating containers required and rounding up
    totalCost = containerCost * containersRequired; //Calculating Total Production Cost
    totalProfit = profit * containersRequired; //Calculating Total Profit

    string s2 = "The number of containers needed to hold the cheese is: ";
    string s3 = "The cost of producing " + to_string(containersRequired) + " containers of cheese is: "; //Setting our strings as variables so they can be manipulated later
    string s4 = "The profit from producing " + to_string(containersRequired) + " containers of cheese is: ";
   
    int sLength = 60; //I was changing this a few times so i made it a variable
    cout << setw(sLength) << left << s2 << right << containersRequired << endl;
    cout << setw(sLength) << left << s3 << right << totalCost << endl; //Actually outputting strings
    cout << setw(sLength) << left << s4 << right << totalProfit << endl;


    /////////////////////////Actual Code Body

    fInstream.close(); //closing streams

    return 0; //return zero is a successful build, return 1 above is error
}

