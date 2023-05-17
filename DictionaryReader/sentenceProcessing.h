#pragma once

#include <sstream>

#include "hashTable.h"

namespace sentenceProcessing {
	void processWord(const HashTable&, const std::string&);
	void processSentence(const HashTable&, const std::string&, const std::string& = " .,:;-!?");
};
