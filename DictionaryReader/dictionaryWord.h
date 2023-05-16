#pragma once

#include <iostream>
#include <string>

class DictionaryWord {
private:
	std::string word;
	std::string meaning;
public:
	DictionaryWord(const std::string&, const std::string&);
	std::string getWord() const;
	std::string getMeaning() const;
	bool operator==(const std::string& compared_word) const;
	friend std::ostream& operator<<(std::ostream&, const DictionaryWord);
};
