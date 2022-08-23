#include "View.h"

bool isNumeric_(const std::string& str) {
	bool result = true;
	if ((str == "") || (str.size() > 9)) { return false; }
	for (size_t i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			result = false;
		}
	}
	return result;
}

bool isPhoneNum(const std::string& str) {
	if ((str[0] == '8') && (str.size() == 11)) {
		for (auto el : str) {
			if (!isdigit(el)) {
				return false;
			}
		}
		return true;
	}
	else if ((str[0] == '+') && (str[1] != '0') && (str.size() == 12)) {
		for (size_t i = 1; i < 11; ++i) {
			if (!isdigit(str[i])) {
				return false;
			}
			return true;
		}
	}
	else{
		return false;
	}
}

