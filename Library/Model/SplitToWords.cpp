#include "SplitToWords.h"

std::vector<std::string> splitToWords(const std::string& str)
{
	std::vector<std::string> words;
	std::string delimiters = ",. ?!-\t;:(){}[]";
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (std::string::npos != pos || std::string::npos != lastPos) {
		words.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
	return words;
}
