#pragma once

#include "hashTable.h"

#include <fstream>

namespace DictionaryReader {
	DictionaryWord processLine(const std::string&, const int, const char);
	void processFile(HashTable<DictionaryWord, std::string>&, const std::string&, const char = ';');
};
