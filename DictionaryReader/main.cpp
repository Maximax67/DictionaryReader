#include "dictionaryReader.h"
#include "sentenceProcessing.h"
#include "askUser.h"

int main() {
	HashTable data;

	std::string path = getPath();
	DictionaryReader::processFile(data, path);

	do {
		std::string sentence = getSentence();
		sentenceProcessing::processSentence(data, sentence);
	} while (askToContinue());

	return 0;
}
