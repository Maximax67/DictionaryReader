#include <windows.h>

#include "dictionaryReader.h"
#include "sentenceProcessing.h"
#include "askUser.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::setlocale(LC_ALL, "Ukr");

	HashTable data;

	std::string path = getPath();
	DictionaryReader::processFile(data, path);

	do {
		std::string sentence = getSentence();
		sentenceProcessing::processSentence(data, sentence);
	} while (askToContinue());

	return 0;
}
