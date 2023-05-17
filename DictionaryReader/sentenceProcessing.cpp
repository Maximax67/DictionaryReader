#include "sentenceProcessing.h"

void sentenceProcessing::processSentence(const HashTable& data, const std::string& sentence, const std::string& delim) {
	std::istringstream iss(sentence);
	std::string word;

	while (std::getline(iss, word)) {
		size_t start = 0, end = 0;
		while ((end = word.find_first_of(delim, start)) != std::string::npos) {
			if (end != start) {
				processWord(data, word.substr(start, end - start));
			}
			start = end + 1;
		}
		if (start < word.length()) {
			processWord(data, word.substr(start));
		}
	}
}

void sentenceProcessing::processWord(const HashTable& data, const std::string& word) {
	DictionaryWord* dw = data.getValue(word);
	if (dw != nullptr) {
		std::cout << *dw << std::endl;
	}
	else {
		std::cout << "!!! " << word << " not found !!!" << std::endl << std::endl;
	}
}
