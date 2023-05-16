#include <iostream>

#include "linkedList.h"

int main() {
	LinkedList<DictionaryWord, std::string> list;

	DictionaryWord word1("test", "meaning for test");
	DictionaryWord word2("test2", "meaning for test2");
	DictionaryWord word3("test3", "meaning for test3");
	DictionaryWord word4("test4", "meaning for test4");
	
	list.insert(word1);
	list.insert(word2);
	list.insert(word3);
	list.insert(word4);

	list.remove(word2.getWord());

	std::string find;

	std::getline(std::cin, find);

	DictionaryWord* found = list.getNode(find);

	if (found != nullptr) std::cout << *found << std::endl;
	else std::cout << "Not found" << std::endl;

	return 0;
}
