#include "ConvertText.h"
// function definitions
 /*************************************************************
 * Function: openinputFile()
 * Date Created: 01/21/20
 * Date Last Modified: 01/21/20          
 * Description: This function opens file for reading in.
 * Input parameters: The ifstream file must be pass by 
 *				reference and the name of the file.
 * Returns: nothing
 * Pre: The ifstream file must be pass by 
 *				reference and the name of the file had to have 
 *            	been scanned in by the user.
 * Post: The file is opened or not and a message is displayed.
 *************************************************************/
void openinputFile(ifstream& inputFile, string iname) {
	// opens file for reading & outputs message
	inputFile.open(iname);
	if (inputFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
 /*************************************************************
 * Function: openoutputFile()
 * Date Created: 01/21/20
 * Date Last Modified: 01/21/20          
 * Description: This function opens file for writing.
 * Input parameters: The ofstream file must be pass by 
 *				reference and the name of the file.
 * Returns: nothing
 * Pre: The ofstream file must be pass by 
 *				reference and the name of the file had to have 
 *            	been scanned in by the user.
 * Post: The file is opened or not and a message is displayed.
 *************************************************************/
void openoutputFile(ofstream& outputFile, string oname) {
	// opens file for writing & outputs message
	outputFile.open(oname);
	if (outputFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
 /*************************************************************
 * Function: processFile()
 * Date Created: 01/21/20
 * Date Last Modified: 01/21/20          
 * Description: This function reads the file content and
 *				converts the lines from English to Morse or vice
 *				versa.
 * Input parameters: The ifstream and ofstream files must be 
 *				pass by reference, the string array, and the
 *				boolean condition for the user choice.
 * Returns: nothing
 * Pre: The ifstream and ofstream file must be pass by 
 *				reference and the Morse code array and bool 
 *				had to have been scanned in by the user.
 * Post: The content of the input file is read, converted, and 
 *				written to the output file.
 *************************************************************/
void processFile(ifstream& inputFile, ofstream& outputFile, string morseString[], bool toMorse) {
	string line, word;
	istringstream iss;
	int counterTrack = 0;
	while (!inputFile.eof()) {
		// read line by line from the file
		getline(inputFile, line);
		if (inputFile.good()) {
			// read word by word from the line
			iss.clear();
			iss.str(line);
			// if converting from English to Morse code
			if (toMorse) {
				while (iss.good()) {
					iss >> word;
					// read char by char from word
					string result = "";
					if (iss.peek() == -1 && line.back() < 48) {
						counterTrack++;
						break;
					}
					// checks characters and matches them to corresponding Morse
					for (char c : word) {
						if (c >= 97) {
							c -= 32;
						}
						counterTrack++;
						result = morseString[c];
						outputFile<<result;
						outputFile<<" ";
					}
					if (iss.peek() != -1 && line.back() >= 48){
						counterTrack++;
						outputFile << " ";
					}
				}
			}
			// if converting from Morse code to English
			else {
				char result;
				string letter = "";
				// loop to convert Morse code into English characters and group them by word
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ' ') {
						for (int j = 48; j < 91; j++) {
							if (letter == morseString[j]) {
								result = j;
								outputFile << result;
								counterTrack++;
								break;
							}
							if (j == 57) {
								j += 7;
							}
						}
						// checks if the next character signifies continuation of word or new word
						if (line[i+1] == ' ') {
							outputFile<<' ';
							counterTrack++;
							i++;
						}
						letter = "";
					}
					else {
						letter += line[i];
					}
				}
			}
			outputFile << endl;
			counterTrack++;
		}
	}
	// outputs how many characters were converted
	cout << "Total characters converted successfully: " << counterTrack << endl;
}
