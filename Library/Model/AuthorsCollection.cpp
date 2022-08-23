#include "AuthorsCollection.h"

namespace Model {

	using sh_author = std::shared_ptr<Author>;

	void AuthorsCollection::addAuthor(const std::string surname, const std::string name,
		const std::string patronymic) {
		auto newAuthor = std::make_shared<Author>();
		newAuthor->setSurname(surname);
		newAuthor->setName(name);
		newAuthor->setPatronymic(patronymic);
		int id{0};
		if (authorsById.empty()) {
			newAuthor->setId(id);
		}
		else {
			id = (--authorsById.end())->second->getId() + 1;
			newAuthor->setId(id);
		}
		authorsByName.insert(std::make_pair(surname, newAuthor));
		authorsById.insert(std::make_pair(id, newAuthor));
		updateFile(authorsByName, fileAuthorsByName);
		updateFile(authorsById, fileAuthorsById);
	}
	
	std::vector<sh_author> AuthorsCollection::findAuthor(const int id, const std::string surname,
		const std::string name, const std::string patronymic) const {
		std::vector<sh_author> result;
		if (id == -1) {
			auto range = authorsByName.equal_range(surname);
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
		else {
			auto search = authorsById.find(id);
			if (search!= authorsById.end()) {
				result.push_back(search->second);
			}
			return result;
		}
	}

	std::vector<sh_author> AuthorsCollection::findAuthor(const int id,
		const std::vector <std::string> names) const {
		std::vector<sh_author> result;
		if (id != -1) {
			if (names.size() == 0) {
				result = findAuthor(id, "", "", "");
				return result;
			}
			else {
				result = findAuthor(id, "", "", "");
				for (auto el : result) {
					bool found = false;
					for (auto e : names) {
						if (el->getSurname() == e) {
							found = true;
						}
					}
				}
				return result;
			}
		}		
		else {
			for (auto el : names) {
				auto search = findAuthor(-1, el, "", "");
				for (auto e : search) {
					result.push_back(e);
				}
			}
			return result;
		}
	}

	std::vector<sh_author> AuthorsCollection::findAuthor(const int id) const {
		std::vector<sh_author> search;
		auto range = authorsById.equal_range(id);
		for (auto i = range.first; i != range.second; i++) {
			search.push_back(i->second);
		}
		return search;
	}

	std::vector<sh_author> AuthorsCollection::findAuthor(const std::vector <std::string> names)const {
		std::vector<sh_author> search;
		for (auto el : names) {
			auto range = authorsByName.equal_range(el);
			for (auto i = range.first; i != range.second; i++) {
				search.push_back(i->second);
			}
		}
		return search;
	}

	template<typename T>
	void AuthorsCollection::updateFile(const std::multimap<T, sh_author>& collection,
									   const std::string fileName) {
		std::ofstream file;
		file.open(fileName);
		if (file.is_open()) {
			for (auto el : collection) {
				file << "\nId\n" << el.second->getId() << "\nName\n" <<
					el.second->getName() << "\nPatronymic\n" <<
					el.second->getPatronymic() << "\nSurname\n" <<
					el.second->getSurname() << "\nnew";
			}
			file.close();
		}
	}

	void AuthorsCollection::recieveAuthors() {
		//recieve authors sorted by surname
		std::ifstream file;
		file.open(fileAuthorsByName);
		int id{ 0 };
		std::string name{};
		std::string surname{};
		std::string patronymic{};
		std::string current{};
		std::string previous{};
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, current);
				auto a = std::make_shared<Author>();
				if (previous == "Id") {
					id = std::stoi(current);
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

				if (current == "new") {
					a->setId(id);
					a->setName(name);
					a->setSurname(surname);
					a->setPatronymic(patronymic);
					authorsByName.insert(std::make_pair(surname, a));
				}
				previous = current;
			}
			file.close();
		}
		//recieve authors sorted by Id
		file.open(fileAuthorsById);
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, current);
				auto a = std::make_shared<Author>();
				if (previous == "Id") {
					id = std::stoi(current);
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

				if (current == "new") {
					a->setId(id);
					a->setName(name);
					a->setSurname(surname);
					a->setPatronymic(patronymic);
					authorsById.insert(std::make_pair(id, a));
				}
				previous = current;
			}
			file.close();
		}
	}

	void AuthorsCollection::delAuthor(const int id) {
		auto search = authorsById.find(id);
		std::string surname = search->second->getSurname();
		search = authorsById.erase(search);
		auto range = authorsByName.equal_range(surname);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getId() == id) {
				i = authorsByName.erase(i);
				break;
			}
		}
		updateFile(authorsByName, fileAuthorsByName);
		updateFile(authorsById, fileAuthorsById);
	}

	void AuthorsCollection::changeName(const int id, const std::string newSurname,
		const std::string newName, const std::string newPatronymic) {
		auto aAuthor = std::make_shared<Author>();
		auto search = authorsById.find(id);
		std::string oldSurname = search->second->getSurname();
		if (search != authorsById.end()) {
			search->second->setSurname(newSurname);
			search->second->setName(newName);
			search->second->setPatronymic(newPatronymic);
			aAuthor->setSurname(newSurname);
			aAuthor->setName(newName);
			aAuthor->setPatronymic(newPatronymic);
			aAuthor->setId(id);
		}
		auto range = authorsByName.equal_range(oldSurname);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getId() == id) {
				i = authorsByName.erase(i);
				break;
			}
		}
		authorsByName.insert(std::make_pair(newSurname, aAuthor));
		updateFile(authorsByName, fileAuthorsByName);
		updateFile(authorsById, fileAuthorsById);
	}

}