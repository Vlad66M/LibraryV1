#pragma once
#ifndef BOOKRECORDSCOLLECTION_H
#define BOOKRECORDSCOLLECTION_H
#include "BookRecord.h"
#include <map>
#include <memory>
#include <fstream>
#include<string>



namespace Model {

	class BookRecordsCollection {
	public:
		using sh_book_records = std::shared_ptr<BookRecord>;

		void addRecord(const int id, const int count, const BookRecord::BookLocation location);
		void recieveRecords();
		void delRecord(const int id);
		void changeId(const int id, const int newId);
		void changeCount(const int id, const int newCount);
		void changeLocation(const int id, const BookRecord::BookLocation location);
		sh_book_records find(const int id)const;
		int getBookCount(const int bookId)const;
		void increaseBookCount(const int bookId);
		void decreaseBookCount(const int bookId);

	private:

		void updateFile();

		std::map<int, sh_book_records> bookRecords;

	};
}
#endif // !BOOKRECORDSCOLLECTION_H
