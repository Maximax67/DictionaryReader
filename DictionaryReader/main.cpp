#include <sstream>

#include "dictionaryReader.h"
#include "askUser.h"

int main() {
	HashTable data;

	std::string path = getPath();
	DictionaryReader::processFile(data, path);

	do {
		std::string sentence = getSentence();
	
		std::stringstream ss(sentence);
		std::string word;
		while (ss >> word) {
			DictionaryWord* dw = data.getValue(word);
			if (dw != nullptr) {
				std::cout << *dw << std::endl;
			}
			else {
				std::cout << word << " not found!" << std::endl;
			}
		}
	} while (askToContinue());

	return 0;
}
