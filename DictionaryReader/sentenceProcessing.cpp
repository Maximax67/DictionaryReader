#include "sentenceProcessing.h"

void sentenceProcessing::processSentence(const HashTable& data, const std::string& sentence, const std::string& delim) {
	std::istringstream iss(sentence);
	std::string line, word;

	while (std::getline(iss, line)) {
		size_t start = 0, end = 0;
		while ((end = line.find_first_of(delim, start)) != std::string::npos) {
			if (end != start) {
				word = line.substr(start, end - start);
				processWord(data, word);
			}
			start = end + 1;
		}
		if (start < line.length()) {
			word = line.substr(start, end - start);
			processWord(data, word);
		}
	}
}

void sentenceProcessing::findWord(const HashTable& data, const std::string& word) {
	DictionaryWord* dw = data.getValue(word);
	if (dw != nullptr) {
		std::cout << *dw << std::endl;
	}
	else {
		std::cout << "!!! " << word << " not found !!!" << std::endl << std::endl;
	}
}

void sentenceProcessing::processWord(const HashTable& data, std::string& word) {
	if (checkIfWord(word)) {
		capitalizeWord(word);
		findWord(data, word);
	}
}

bool sentenceProcessing::checkIfWord(const std::string& s) {
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] < 'A' && s[i] > 'ÿ') || (s[i] > 'Z' && s[i] < 'a') || s[i] >= 'z') {
			return false;
		}
	}

	return true;
}

void sentenceProcessing::capitalizeWord(std::string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
	}
}
