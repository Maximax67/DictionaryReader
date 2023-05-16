#include "dictionaryReader.h"

void DictionaryReader::processFile(HashTable<DictionaryWord, std::string>& data, const std::string& filename, const char sep) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		throw std::exception("Can't open file for reading");
	}

	int line_counter = 1;
	std::string line;

	while (std::getline(file, line)) {
		try {
			DictionaryWord word = processLine(line, line_counter, sep);
			data.insert(word, word.getWord());
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		line_counter++;
	}

	file.close();
}

DictionaryWord DictionaryReader::processLine(const std::string& line, const int nline, const char sep) {
	size_t pos = line.find_first_of(sep);

	if (pos == std::string::npos) {
		throw std::exception("Can't find separator for word and it's meaning");
	}

	if (pos == 0) {
		throw std::exception("No word, only meaning");
	}

	if (pos == line.length()) {
		throw std::exception("No meaning, only word");
	}

	return DictionaryWord(line.substr(0, pos), line.substr(pos + 1));
}
