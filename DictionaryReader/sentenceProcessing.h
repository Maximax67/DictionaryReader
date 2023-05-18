#pragma once

#include <sstream>

#include "hashTable.h"

namespace sentenceProcessing {
	void findWord(const HashTable&, const std::string&);
	void processWord(const HashTable&, std::string&);
	void capitalizeWord(std::string&);
	bool checkIfWord(const std::string&);
	void processSentence(const HashTable&, const std::string&, const std::string& = " .,:;-!");
};
