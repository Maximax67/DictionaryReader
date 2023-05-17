#pragma once

#include "hashTable.h"

#include <fstream>

namespace DictionaryReader {
	void printError(const std::string&, const int = 0, const std::string& = "");
	void processLine(HashTable&, const std::string&, const int, const char);
	void processFile(HashTable&, const std::string&, const char = ';');
};
