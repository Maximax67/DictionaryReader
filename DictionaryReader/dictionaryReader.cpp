#include "dictionaryReader.h"

void DictionaryReader::processFile(HashTable& data, const std::string& filename, const char sep) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		printError("Can't open file for reading: " + filename);
		return;
	}

	int line_counter = 1;
	std::string line;

	while (std::getline(file, line)) {
		processLine(data, line, line_counter, sep);
		line_counter++;
	}

	if (line_counter == 1) {
		printError("Can't read any line in dictionary!");
	}

	file.close();
}

void DictionaryReader::processLine(HashTable& data, const std::string& line, const int line_counter, const char sep) {
	if (line.length() == 0) {
		printError("Empty line", line_counter);
		return;
	}

	size_t pos = line.find_first_of(sep);
	if (pos == std::string::npos || pos == 0 || pos == line.length() - 1) {
		if (pos == std::string::npos) {
			printError("Can't find separator for word and it's meaning!", line_counter, line);
		} else if (line.length() == 1) {
			printError("Only separator found, no word and it's meaning!", line_counter, line);
		} else if (pos == 0) {
			printError("No word, only meaning!", line_counter, line);
		} else if (pos == line.length()) {
			printError("No meaning, only word!", line_counter, line);
		}

		return;
	}

	DictionaryWord word(line.substr(0, pos), line.substr(pos + 1));
	data.insert(word);
}

void DictionaryReader::printError(const std::string& message, const int n_line, const std::string& line) {
	if (n_line) {
		std::cout << std::endl << "Error in dictionary! Line: " << n_line << std::endl
			<< message << std::endl;
		if (!line.empty()) {
			std::cout << "Readed line: " << std::endl << line << std::endl;
		}
	}
}
