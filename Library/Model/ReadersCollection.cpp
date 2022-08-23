#include"ReadersCollection.h"

namespace Model {

	using sh_reader = std::shared_ptr<Reader>;

	void ReadersCollection::addReader(const std::string surname, const std::string name,
		const std::string patronymic, const std::string phoneNumber) {
		auto newReader = std::make_shared<Reader>();
		newReader->setSurname(surname);
		newReader->setName(name);
		newReader->setPatronymic(patronymic);
		newReader->setPhone(phoneNumber);
		int docNum{ 0 };
		if (readersByNumber.empty()) {
			newReader->setDocNumber(docNum);
		}
		else {
			docNum = (--readersByNumber.end())->second->getDocNumber() + 1;
			newReader->setDocNumber(docNum);
		}
		readersByName.insert(std::make_pair(surname, newReader));
		readersByNumber.insert(std::make_pair(docNum, newReader));
		updateFile(readersByName, fileReadersByName);
		updateFile(readersByNumber, fileReadersByNum);
	}

	template<typename T>
	void ReadersCollection::updateFile(const std::multimap<T, sh_reader>& collection,
		const std::string fileName) {
		std::ofstream file;
		file.open(fileName);
		if (file.is_open()) {
			for (auto el : collection) {
				file << "\nDoc number\n" << el.second->getDocNumber() << "\nName\n" <<
					el.second->getName() << "\nPatronymic\n" <<
					el.second->getPatronymic() << "\nSurname\n" <<
					el.second->getSurname() << "\nPhone num\n"<<
					el.second->getPhone()<<"\nnew";
			}
			file.close();
		}
	}

	void ReadersCollection::recieveReaders() {
		//recieve readers sorted by surname
		std::ifstream file;
		file.open(fileReadersByName);
		int docNum{ 0 };
		std::string phoneNum{};
		std::string name{};
		std::string surname{};
		std::string patronymic{};
		std::string current{};
		std::string previous{};
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, current);
				auto r = std::make_shared<Reader>();
				if (previous == "Doc number") {
					docNum = std::stoi(current);
				}
				if (previous == "Name") {
					name = current;
				}
				if (previous == "Surname") {
					surname = current;
				}
				if (previous == "Patronymic") {
					patronymic = current;
				}
				if (previous == "Phone num") {
					phoneNum = current;
				}
				if (current == "new") {
					r->setDocNumber(docNum);
					r->setName(name);
					r->setSurname(surname);
					r->setPatronymic(patronymic);
					r->setPhone(phoneNum);
					readersByName.insert(std::make_pair(surname, r));
				}
				previous = current;
			}
			file.close();
		}
		//recieve readers sorted by Id
		file.open(fileReadersByNum);
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, current);
				auto r = std::make_shared<Reader>();
				if (previous == "Doc number") {
					docNum = std::stoi(current);
				}
				if (previous == "Name") {
					name = current;
				}
				if (previous == "Surname") {
					surname = current;
				}
				if (previous == "Patronymic") {
					patronymic = current;
				}
				if (previous == "Phone num") {
					phoneNum = current;
				}
				if (current == "new") {
					r->setDocNumber(docNum);
					r->setName(name);
					r->setSurname(surname);
					r->setPatronymic(patronymic);
					r->setPhone(phoneNum);
					readersByNumber.insert(std::make_pair(docNum, r));
				}
				previous = current;
			}
			file.close();
		}
	}

	std::vector<sh_reader> ReadersCollection::findReader(const int docNum)const {
		std::vector<sh_reader> search;
		auto range = readersByNumber.equal_range(docNum);
		for (auto i = range.first; i != range.second; i++) {
			search.push_back(i->second);
		}
		return search;
	}

	std::vector<sh_reader> ReadersCollection::findReader(const std::string surname, 
		const std::string name, const std::string patronymic)const {
		std::vector<sh_reader> result;
		auto range = readersByName.equal_range(surname);
		bool found = true;
		for (auto i = range.first; i != range.second; i++) {
			bool found = true;
			if (!name.empty()) {
				if ((i->second->getName() != name)) { found = false; }
			}
			if (!patronymic.empty()) {
				if ((i->second->getPatronymic() != patronymic)) { found = false; }
			}
			if (found) {
				result.push_back(i->second);
			}
		}
		return result;
	}


	void ReadersCollection::delReader(const int docNum) {
		auto search = readersByNumber.find(docNum);
		std::string surname = search->second->getSurname();
		search = readersByNumber.erase(search);
		auto range = readersByName.equal_range(surname);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getDocNumber() == docNum) {
				i = readersByName.erase(i);
				break;
			}
		}
		updateFile(readersByName, fileReadersByName);
		updateFile(readersByNumber, fileReadersByNum);
	}

	void ReadersCollection::changeName(const int docNum, const std::string newSurname, 
		const std::string newName, const std::string newPatronymic) {
		auto aReader = std::make_shared<Reader>();
		auto search = readersByNumber.find(docNum);
		std::string oldSurname = search->second->getSurname();
		if (search != readersByNumber.end()) {
			search->second->setSurname(newSurname);
			search->second->setName(newName);
			search->second->setPatronymic(newPatronymic);
			aReader->setSurname(newSurname);
			aReader->setName(newName);
			aReader->setPatronymic(newPatronymic);
			aReader->setDocNumber(docNum);
			aReader->setPhone(search->second->getPhone());
		}
		auto range = readersByName.equal_range(oldSurname);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getDocNumber() == docNum) {
				i = readersByName.erase(i);
				break;
			}
		}
		readersByName.insert(std::make_pair(newSurname, aReader));
		updateFile(readersByName, fileReadersByName);
		updateFile(readersByNumber, fileReadersByNum);
	}

	void ReadersCollection::changePhoneNum(const int docNum, const std::string newPhoneNum) {
		auto search = readersByNumber.find(docNum);
		std::string surname = search->second->getSurname();
		if (search != readersByNumber.end()) {
			search->second->setPhone(newPhoneNum);
		}
		auto range = readersByName.equal_range(surname);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getDocNumber() == docNum) {
				i->second->setPhone(newPhoneNum);
				break;
			}
		}
	}

	bool ReadersCollection::isRegistered(const int docNum)const {
		auto search = readersByNumber.find(docNum);
		if (search != readersByNumber.end()) {
			return true;
		}
		else {
			return false;
		}
	}

}

