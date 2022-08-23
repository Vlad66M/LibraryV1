#pragma once
#ifndef READERSCOLLECTION_H
#define READERSCOLLECTION_H
#include "Reader.h"
#include <map>
#include<vector>
#include <memory>
#include <fstream>
#include"SplitToWords.h"

namespace Model {

	class ReadersCollection {
	public:
		using sh_reader = std::shared_ptr<Reader>;

		void addReader(const std::string surname, const std::string name, 
			const std::string patronymic, const std::string phoneNumber);
		void recieveReaders();
		std::vector<sh_reader> findReader(const int docNum)const;
		std::vector<sh_reader> findReader(const std::string surname, 
			const std::string name, const std::string patrynomic)const;
		void delReader(const int docNum);
		void changeName(const int docNum, const std::string newSurname,
			const std::string newName, const std::string newPatronymic);
		void changePhoneNum(const int docNum, const std::string newPhoneNum);
		int getLastDocNumber()const {
			return (--readersByNumber.end())->second->getDocNumber();
		}
		bool isRegistered(const int readerDocNum)const;

	private:
		template<typename T>
		void updateFile(const std::multimap<T, sh_reader>& collection,
			const std::string fileName);

		std::multimap<std::string, sh_reader> readersByName;
		std::multimap<int, sh_reader> readersByNumber;
		std::string fileReadersByName = "data/readersByName.txt";
		std::string fileReadersByNum = "data/readersById.txt";

	};
}

#endif // !READERSCOLLECTION_H
