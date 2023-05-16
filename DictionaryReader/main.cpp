#include <sstream>

#include "dictionaryReader.h"

void capitalize(std::string& s);

int main() {
	HashTable<DictionaryWord, std::string> data;

	std::string path;
	std::cout << "Enter path: ";
	std::getline(std::cin, path);

	DictionaryReader::processFile(data, path);

	std::string sentence, word;
	do {
		std::cout << "Enter sentence: ";
		std::getline(std::cin, sentence);
	
		std::stringstream ss(sentence);

		while (ss >> word) {
			capitalize(word);
			DictionaryWord* dw = data.getValue(word);
			if (dw != nullptr) {
				std::cout << *dw << std::endl;
			}
			else {
				std::cout << word << " not found!" << std::endl;
			}
		}
	} while (true);

	return 0;
}

void capitalize(std::string& s)
{
	for (int i = 0; i <= s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = toupper(s[i]);
		}
	}
}
