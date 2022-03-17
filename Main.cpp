#include "ConvertText.h"
// main function
int main() {
	string convertChoice = "";
	string input = "";
	string output = "";
	ifstream inputFile;
	ofstream outputFile;
	string morseStrings[91];
	ifstream in;
	in.open("morseConverter.txt");
	for (int i = 48; i < 91; i++) {
		in >> morseStrings[i];
		if(i == 57)
			i+=7;
	}
	// prompt the user
	cout << "Welcome to the Morse/English phrase converter. Please enter your command below." << endl << "CMD> ";
	cin >> convertChoice >> input >> output;
	bool choice = (convertChoice == "-m");
	if (choice) {
		// open the file
		openinputFile(inputFile, "english.txt");
		openoutputFile(outputFile, "morse.txt");
		// process file
		processFile(inputFile, outputFile, morseStrings, choice);
		// close file
		inputFile.close();
		outputFile.close();
	}
	else {
		// open the file
		openinputFile(inputFile, "morse.txt");
		openoutputFile(outputFile, "english.txt");
		// process file
		processFile(inputFile, outputFile, morseStrings, choice);
		// close file
		inputFile.close();
		outputFile.close();
	}

	return 0;
}
