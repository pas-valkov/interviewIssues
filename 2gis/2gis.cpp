#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const string helpDescription = "This program can be used in two ways:\n"
	"1) To count amount of specified word in file\n"
	"2) To find 32-bit checksum of the file. Checksum is counted as sum of all 32-bit words in file\n"
	"-m, specify working option\n\tUse 'words' to count word and 'checksum' to find checksum\n"
	"-f, specify filename\n"
	"-v, specify word\n"
	"-h, display this help\n";
const string optionCountWord = "words";
const string optionCheckSum = "checksum";

char* getCmdOption (char** start, char** end, const string& option) {
	auto it = find(start, end, option);
	if (it != end && ++it != end) {
		return *it;
	}
	return nullptr;
}

bool cmdOptionExists (char** start, char** end, const string& option) {
	return find(start, end, option) != end;
}

int main (int argc, char** argv) {
	if (cmdOptionExists(argv, argv + argc, "-h")) {
		cout << helpDescription << endl;
	}
	else {
		char* option = getCmdOption(argv, argv + argc, "-m");
		char* fileName = getCmdOption(argv, argv + argc, "-f");
		char* wordToCount = getCmdOption(argv, argv + argc, "-v");
		if (option == nullptr) {
			cout << "Specify option. Use -h for help" << endl;
			return -1;
		}
		if (optionCountWord.compare(option) == 0) {
			if (fileName == nullptr || wordToCount == nullptr) {
				cout << "Missing option value" << endl;
				return -1;
			}
			ifstream inputFile(fileName);
			if (!inputFile) {
				cout << fileName << ": file not found" << endl;
				return -1;
			}
			unsigned long long int wordCounter = 0;
			while (!inputFile.eof()) {
				string word;
				inputFile >> word;
				if (word.compare(wordToCount) == 0) {
					++wordCounter;
				}
			}
			inputFile.close();
			cout << "Matches of word '" << wordToCount << "': " << wordCounter << endl;
		}
		else if (optionCheckSum.compare(option) == 0) {
			ifstream inputFile(fileName, ifstream::binary);
			if (!inputFile) {
				cout << fileName << ": file not found" << endl;
				return -1;
			}
			uint32_t checksum = 0, word = 0;
			while (inputFile.read(reinterpret_cast<char*>(&word), sizeof(word))) {
				checksum += word;
				word = 0;
			}
			checksum += word; // if file size is not divisiable by 4 checksum != 0
			inputFile.close();
			cout << "32-bit checksum: " << checksum << endl;
		}
		else {
			cout << "Unknown option. Use -h for help" << endl;
			return -1;
		}
	}
	return 0;
}
