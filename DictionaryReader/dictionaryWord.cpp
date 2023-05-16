#include "dictionaryWord.h"

DictionaryWord::DictionaryWord(const std::string& w, const std::string& m) {
	if (w.empty() || m.empty()) {
		if (w.empty() && m.empty()) {
			throw std::invalid_argument("Empty word and meaning! You can't use default constructor here");
		}

		if (w.empty()) {
			throw std::invalid_argument("Empty word");
		}

		if (m.empty()) {
			throw std::invalid_argument("Empty meaning of the word");
		}
	}

	word = w;
	meaning = m;
}

std::string DictionaryWord::getWord() const {
	return word;
}

std::string DictionaryWord::getMeaning() const {
	return meaning;
}

bool DictionaryWord::operator==(const std::string& compared_word) const {
	return compared_word == word;
}

std::ostream& operator<<(std::ostream& os, const DictionaryWord w) {
	os << w.getWord() << ": " << w.getMeaning() << std::endl;
	return os;
}
