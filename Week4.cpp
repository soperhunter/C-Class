//////////////////////////
// This is a programming assignment designed to select a file and analyze how many vowels are in it.
// It counts how many of each vowel there is in a document, tally's them individually and also adds them up.
//////////////////////////


#include <iostream>
#include <string> //declaring used headers
#include <iomanip>
#include <fstream>

int main(int argc, char* argv[])
{
	// The executable name and at least one argument?
	if (argc < 2)
	{
		std::cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// For debugging purposes only
	for (int i = 0; i < argc; i++)
	{
		std::cout << i << ":" << argv[i] << std::endl;
	}

	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) //if there isn't a file this will run and return an error code.
	{
		std::cout << "Error with file name.." << std::endl;
		return 1;
	}

	///////////////////////

	char chTemp;
	int aCounter{};
	int eCounter{};
	int iCounter{}; //declaring variables so they can be used below
	int oCounter{};
	int uCounter{};
	int hCounter{};
	int jCounter{};
	int zCounter{};

	while (inFile >> std::noskipws >> chTemp) { 

		if (tolower(chTemp) == 'a') {
			aCounter = aCounter + 1;
		}
		else if (tolower(chTemp) == 'e') {
			eCounter = eCounter + 1;
		}
		else if (tolower(chTemp) == 'i') { //every character in the document is being searched, and
			iCounter = iCounter + 1;       //for ever vowel it adds one to the counter
		}
		else if (tolower(chTemp) == 'o') {
			oCounter = oCounter + 1;
		}
		else if (tolower(chTemp) == 'u') {
			uCounter = uCounter + 1;
		}
		else if (tolower(chTemp) == 'h') {
			hCounter = hCounter + 1;
		}
		else if (tolower(chTemp) == 'j') {
			jCounter = jCounter + 1;
		}
		else if (tolower(chTemp) == 'z') {
			zCounter = zCounter + 1;

		}
	}

	int vowelCount = aCounter + eCounter + iCounter + oCounter + uCounter; //calculating sum of vowels
	int ln = 75; //this is the length of my setw lines

	std::string intro = "Welcome to my Letter Count Program ";
	std::string string1 = "Analyzing file ";
	std::string string2 = "The number of A's: ";
	std::string string3 = "The number of E's: "; //declaring all our strings so they can be properly
	std::string string4 = "The number of I's: "; //manipulated later
	std::string string5 = "The number of O's: ";
	std::string string6 = "The number of U's: ";
	std::string string7 = "The total number of vowels is: ";
	std::string string8 = "The number of H's: ";
	std::string string9 = "The number of J's: ";
	std::string string10 = "The number of Z's: ";
	std::string filename = "'Constitution_of_the_United_States.txt'";
	char ch = '.';

	std::cout << std::setfill(ch) << std::setw(ln) << " " << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln/3.6) << " " << intro << std::setfill(ch) << std::setw(ln/3.6) << " " << std::endl; //Introduction Paragraph
	std::cout << std::setfill(ch) << std::setw(ln) << " " << std::endl << std::endl;

	std::setfill(' '); //resetting the autofill because i was having issues with it

	std::cout << string1 << filename << "..." << std::endl << std::endl;

	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string2 << aCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string3 << eCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string4 << iCounter << std::endl; //outputting all our information
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string5 << oCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string6 << uCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string8 << hCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string9 << jCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string10 << zCounter << std::endl;
	std::cout << std::setfill(ch) << std::setw(ln) << std::left << string7 << vowelCount << std::endl;

	///////////////////////
	
	inFile.close(); //closing stream

	return 0; //exiting file.
}
