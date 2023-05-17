#include "askUser.h"

std::string inputString() {
	std::string line;
	getline(std::cin, line);
	return line;
}

bool inputYesNo() {
	while (true) {
		char c, buf;
		if (std::cin >> std::noskipws >> c >> buf && buf == '\n') {
			if (c == 'y' || c == 'Y') {
				return true;
			}

			if (c == 'n' || c == 'N') {
				return false;
			}
		}
		std::cin.clear();
		if (buf != '\n') {
			std::cin.ignore(INT_MAX, '\n');
		}
		std::cout << "Input error!" << std::endl << "Try again: ";
	}
}

bool askToContinue() {
	std::cout << "Do you want run program again? (Y/N): ";
	return inputYesNo();
}

bool validatePath(const std::string& path) {
	struct stat sb;
	return stat(path.c_str(), &sb) == 0 && !(sb.st_mode & S_IFDIR);
}

std::string getPath() {
	while (true) {
		std::cout << "Enter path to directory: ";
		std::string path = inputString();

		if (validatePath(path)) {
			return path;
		}

		std::cout << "ERROR! Invalid path!" << std::endl << "Enter again: ";
	}
}

void capitalize(std::string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			s[i] = toupper(s[i]);
		}
	}
}

std::string getSentence() {
	std::cout << "Enter sentence: ";
	std::string input = inputString();
	capitalize(input);
	return input;
}