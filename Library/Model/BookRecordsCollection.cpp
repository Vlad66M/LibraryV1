#include "BookRecordsCollection.h"

namespace Model {

	using sh_book_records = std::shared_ptr<BookRecord>;

	void BookRecordsCollection::addRecord(const int id, const int count,
		const BookRecord::BookLocation location) {
		auto newRecord = std::make_shared<BookRecord>();
		newRecord->setBookId(id);
		newRecord->setCount(count);
		newRecord->setLocation(location);
		bookRecords.insert(std::make_pair(id, newRecord));
		updateFile();
	}

	void BookRecordsCollection::updateFile() {
		std::ofstream file;
		file.open("data/book_record.txt");
		if (file.is_open()) {
			for (auto el : bookRecords) {
				file << "\nBook Id\n" << el.second->getBookId()<<
					"\nCount\n" << el.second->getCount()<<
					"\nRack\n" <<el.second->getLocation().getRack()<<
					"\nShelf\n" << el.second->getLocation().getShelf()<<
				    "\nSection\n" << el.second->getLocation().getSection()<<"\nnew";
			}
			file.close();
		}
	}

	void BookRecordsCollection::recieveRecords() {
		std::ifstream file;
		file.open("data/book_record.txt");
		if (file.is_open()) {
			std::string current{};
			std::string previous;
			int id{ 0 };
			int rack{ 0 };
			int shelf{ 0 };
			int section{ 0 };
			int count{ 0 };
			while (!file.eof()) {
				std::getline(file, current);
				auto record = std::make_shared<BookRecord>();
				if (previous == "Book Id") {
					id = std::stoi(current);
				}
				if (previous == "Count") {
					count = std::stoi(current);
				}
				if (previous == "Rack") {
					rack = std::stoi(current);
				}
				if (previous == "Shelf") {
					shelf = std::stoi(current);
				}
				if (previous == "Section") {
					section = std::stoi(current);
				}
				if (current == "new") {
					record->setBookId(id);
					record->setCount(count);
					record->setLocation({ rack,shelf,section });
					bookRecords.insert(std::make_pair(id, record));
				}
				previous = current;
			}
			file.close();
		}
	}

	void BookRecordsCollection::delRecord(const int id) {
		bookRecords.erase(id);
		updateFile();
	}

	void BookRecordsCollection::changeId(const int id, const int newId) {
		if (id != newId) {
			bookRecords.erase(newId);
			auto record = std::make_shared<BookRecord>();
			record->setBookId(newId);
			record->setCount(bookRecords[id]->getCount());
			record->setLocation(bookRecords[id]->getLocation());
			bookRecords.erase(id);
			bookRecords.insert(std::make_pair(newId, record));
			updateFile();
		}
	}

	void BookRecordsCollection::changeCount(const int id, const int newCount) {
		bookRecords[id]->setCount(newCount);
		updateFile();
	}

	void BookRecordsCollection::changeLocation(const int id, 
		const BookRecord::BookLocation location) {
		bookRecords[id]->setLocation(location);
		updateFile();
	}

	sh_book_records BookRecordsCollection::find(const int id)const {
		auto result = std::make_shared<BookRecord>();
		result->setBookId(-1);
		auto search = bookRecords.find(id);
		if (search != bookRecords.end()) {
			return search->second;
		}
		else { return result; }
	}

	int BookRecordsCollection::getBookCount(const int bookId)const {
		auto search = bookRecords.find(bookId);
		if (search != bookRecords.end()) {
			return search->second->getCount();
		}
	}

	void BookRecordsCollection::increaseBookCount(const int bookId) {
		auto search = bookRecords.find(bookId);
		if (search != bookRecords.end()) {
			search->second->setCount(search->second->getCount() + 1);
			updateFile();
		}
	}

	void BookRecordsCollection::decreaseBookCount(const int bookId) {
		auto search = bookRecords.find(bookId);
		if (search != bookRecords.end()) {
			if (search->second->getCount() > 0) {
				search->second->setCount(search->second->getCount() - 1);
				updateFile();
			}
		}
	}

}