#pragma once
#ifndef READER_H
#define READER_H
#include "Human.h"


namespace Model {

	class Reader :public Human {
	public:
		int getDocNumber()const { return docNumber; }
		std::string getPhone()const { return phoneNum; }
		void setPhone(const std::string number) { phoneNum = number; }

	private:
		void setDocNumber(const int docNumber) { this->docNumber = docNumber; }
		int docNumber;
		std::string phoneNum;
		friend class ReadersCollection;
	};
}

#endif // !READER_H
