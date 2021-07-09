#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
#define currentBowlers 10 //our current number of bowlers

struct Bowler { //creating the bowler structure with the name, their scores, and their average

	string bowlerName;
	int scores[4];
	int averageScore;

};

bool GetBowlingData(string filename, Bowler bowlers[], int& counter) { 
	
	ifstream inFile; //initializing and opening the file
	inFile.open(filename); 

	while (inFile >> bowlers[counter].bowlerName) { //while there are still bowlers in the file, take the bowlers name

		for (int i = 0; i < 4; i++) {
			inFile >> bowlers[counter].scores[i]; //take the bowlers 4 scores and store them into an array
		}
		counter++; //move to the next bowler
	}

	return true; //return true for a successful file read
	inFile.close(); //close the file

}

void GetAverageScore(Bowler bowlers[], int counter) {

	double sum = 0; //initializing the variable for what will be the sum of the bowlers scores

	for (int i = 0; i < counter; i++) { //the first loop is what loops through the bowlers

		int sum = 0;

		for (int j = 0; j < 4; j++) { //this second loop is what adds up the individual bowlers score
			sum += bowlers[i].scores[j];
		}

		bowlers[i].averageScore = sum / 4; //then we just divide their total score by 4 to get the average
	}

}

void PrettyPrintResults(Bowler bowlers[], int counter) {

	cout << "Name\t" << "Score1\tScore2\tScore3\tScore4\tAverage" << endl; //header line

	for (int i = 0; i < counter; i++) { //similar to before, the first loop is what loops through individual bowlers

		cout << setw(10) << left << bowlers[i].bowlerName; //printing the bowler name
		for (int j = 0; j < 4; j++) { //the second loop prints each individual score
			cout << bowlers[i].scores[j] << "\t";
		}
		cout << setw(5) << bowlers[i].averageScore << endl; //and then we print the average and move to the next line and bowler

	}

}

int main() {

	int counter = 0; //starting our counter at zero
	string filename = "BowlingScores.txt"; //specifying file name
	Bowler bowlers[currentBowlers]; //creating an array of bowlers with the current size of the league

	if (GetBowlingData(filename, bowlers, counter)) { //calling our functions, note that it is in an if statement because it is a bool function that returns true or false

		GetAverageScore(bowlers, counter);
		PrettyPrintResults(bowlers, counter);

	}
	else {

		cout << "Error opening file." << endl; //if the bool function returns false, it means the file wasn't found or invalid, so the program exits.
		return 1;

	}

	return 0;

}