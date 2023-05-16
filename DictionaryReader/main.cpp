#include <iostream>

#include "hashTable.h"

int main() {
	DictionaryWord word1("test", "meaning for test");
	DictionaryWord word2("test2", "meaning for test2");
	DictionaryWord word3("test3", "meaning for test3");
	DictionaryWord word4("test4", "meaning for test4");
	
	HashTable<DictionaryWord, std::string> table(3);

	table.insert(word1, word1.getWord());
	table.insert(word2, word2.getWord());
	table.insert(word3, word3.getWord());
	table.insert(word4, word4.getWord());

	std::string find;

	std::getline(std::cin, find);

	DictionaryWord* found = table.getValue(find);

	if (found != nullptr) std::cout << *found << std::endl;
	else std::cout << "Not found" << std::endl;

	return 0;
}
