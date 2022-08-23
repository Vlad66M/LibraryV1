#include"BooksCollection.h"
#include <msclr\marshal.h>
#include <fstream>
#include <typeinfo>

namespace Model {

	void BooksCollection::addBook(const int param, const int idAuthor, const int year,
		const std::string name, const std::string isbn) {
		auto newBook = std::make_shared<Book>();
		newBook->setAuthorId(idAuthor);
		newBook->setYear(year);
		newBook->setName(name);
		newBook->setIsbn(isbn);
		if (allBooks.empty()) {
			newBook->setId(0);
			availableBooksIds.insert({ 0, 0 });
		}
		else {
			newBook->setId(allBooks.rbegin()->second->getId() + 1);
			availableBooksIds.insert(std::make_pair(allBooks.rbegin()->second->getId() + 1, 
									   allBooks.rbegin()->second->getId() + 1));
		}
		allBooks.insert(std::make_pair(newBook->getName(), newBook));
		allBooksByAuthor.insert(std::make_pair(std::to_string(idAuthor), newBook));
		updateFile(allBooksByAuthor, fileAllByAuthor);
		updateFile(allBooks, fileAll);
		if (param == 0) {
			availableBooks.insert(std::make_pair(newBook->getName(), newBook));
			availableBooksByAuthor.insert(std::make_pair(std::to_string(idAuthor), newBook));
			updateFile(availableBooks, fileAvailable);
			updateFile(availableBooksByAuthor, fileAvailableByAuthor);
		}
		updateAvailableBooksIds();
	}
	
	void BooksCollection::updateFile(const std::multimap<std::string, sh_book>& books,
		const std::string fileName) {
		std::ofstream booksFile;
		booksFile.open(fileName);
		if (booksFile.is_open()) {
			for (auto el : books) {
				booksFile << "\nISBN\n" << el.second->getIsbn() <<
					 "\nId\n"<< el.second->getId() <<
					"\nAuthor Id\n" << el.second->getAuthorId() <<
					"\nName\n" << el.second->getName() << "\nYear\n" <<
					el.second->getYear() <<"\nnew";
			}
			booksFile.close();
		}
	}

	void BooksCollection::recieveBooks() {
		getBooksFromFile(allBooks, fileAll);
		getBooksFromFile(availableBooks, fileAvailable);
		getBooksFromFile(allBooksByAuthor, fileAllByAuthor);
		getBooksFromFile(availableBooksByAuthor, fileAvailableByAuthor);
	}

	void BooksCollection::updateAvailableBooksIds() {
		std::ofstream file;
		file.open(fileAvailableIds);
		if (file.is_open()) {
			for (auto el : availableBooksIds) {
				file << el.second << "\n";
			}
			file.close();
		}
	}

	void BooksCollection::recieveAvailableIds() {
		std::ifstream file;
		file.open(fileAvailableIds);
		std::string current;
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, current);
				if (current != "") {
					int id = std::stoi(current);
					availableBooksIds.insert(std::make_pair(id, id));
				}
			}
			file.close();
		}
	}

	void BooksCollection::getBooksFromFile(std::multimap<std::string, sh_book>& books,
										   const std::string fileName) {
		std::ifstream booksFile;
		booksFile.open(fileName);
		std::string current;
		std::string previous{ "" };
		std::string isbn{ "" };
		int idBook{ 0 };
		int idAuthor{ 0 };
		int year{ 0 };
		std::string name{ "" };

		if (booksFile.is_open()) {
			while (!booksFile.eof()) {
				std::getline(booksFile, current);
				auto b = std::make_shared<Book>();
				if (previous == "ISBN") {
					isbn = current;
				}
				if (previous == "Id") {
					idBook = std::stoi(current);
				}
				if (previous == "Author Id") {
					idAuthor = std::stoi(current);
				}
				if (previous == "Name") {
					name = current;
				}
				if (previous == "Year") {
					year = std::stoi(current);
				}
				if (current == "new") {
					b->setId(idBook);
					b->setAuthorId(idAuthor);
					b->setIsbn(isbn);
					b->setName(name);
					b->setYear(year);
					if ((fileName == fileAll) || (fileName == fileAvailable)) {
						books.insert(std::make_pair(name, b));
					}
					if ((fileName == fileAllByAuthor) || (fileName == fileAvailableByAuthor)) {
						books.insert(std::make_pair(std::to_string(idAuthor), b));
					}
				}
				previous = current;
			}
			booksFile.close();
		}
	}

	std::vector<sh_book> BooksCollection::findBook(const std::multimap<std::string, sh_book>& collection,
		 const std::string name, const std::string isbn, const int year, const int authorId)const {
		std::vector<sh_book> result;
		if (name != "") {
			auto range = collection.equal_range(name);
			for (auto i = range.first; i != range.second; i++) {
				bool found = true;
				if (!isbn.empty()) {
					if (isbn != i->second->getIsbn()) {
						found = false;
						continue;
					}
				}
				if (authorId != -1) {
					if (authorId != i->second->getAuthorId()) {
						found = false;
						continue;
					}
				}
				if (year != -1) {
					if (year != i->second->getYear()) {
						found = false;
						continue;
					}
				}
				if (found) {
					result.push_back(i->second);
				}
			}
			return result;
		}
		else if (!isbn.empty()) {
			for (auto el : collection) {
				if (el.second->getIsbn() == isbn) {
					result.push_back(el.second);
				}
			}
			return result;
		}
	}

	std::vector<sh_book> BooksCollection::findInAll(const std::string name, 
		const std::string isbn, const int year, const int authorId)const {
		return findBook(allBooks, name, isbn, year, authorId);
	}

	std::vector<sh_book> BooksCollection::findInAvailable(const std::string name, 
		const std::string isbn, const int year, const int authorId)const {
		return findBook(availableBooks, name, isbn, year, authorId);
	}

	void BooksCollection::delBook(std::multimap<std::string, sh_book>& collection,
								  std::multimap<std::string, sh_book>& collectionByAuthor,
								  const std::string name, const std::string isbn) {
		int authorId;
		auto range = collection.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				authorId = i->second->getAuthorId();
				i=collection.erase(i);
				break;
			}
		}

		auto rangeByAuthor = collectionByAuthor.equal_range(std::to_string(authorId));
		for (auto i = rangeByAuthor.first; i != rangeByAuthor.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i = collectionByAuthor.erase(i);
				return;
			}
		}
	}

	std::vector<sh_book> BooksCollection::findById(const std::multimap<std::string, sh_book>& collection, 
												   const int id)const {
		std::vector<sh_book> result;
		for (auto el : collection) {
			if (el.second->getId() == id) {
				result.push_back(el.second);
			}
		}
		return result;
	}

	std::vector<sh_book> BooksCollection::findByIdAll(const int id)const {
		return findById(allBooks, id);
	}

	std::vector<sh_book> BooksCollection::findByIdAvailable(const int id)const {
		return findById(availableBooks, id);
	}


	void BooksCollection::delFromAll(const std::string name, const std::string isbn) {
		delBook(allBooks, allBooksByAuthor, name, isbn);
		delBook(availableBooks, availableBooksByAuthor, name, isbn);
		updateFile(allBooks, fileAll);
		updateFile(allBooksByAuthor, fileAllByAuthor);
		updateFile(availableBooks, fileAvailable);
		updateFile(availableBooksByAuthor, fileAvailableByAuthor);
		updateAvailableBooksIds();
		delAvailableId(name, isbn);
	}

	void BooksCollection::delAvailableId(const std::string name, const std::string isbn) {
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				int id = i->second->getId();
				availableBooksIds.erase(id);
				updateAvailableBooksIds();
				break;
			}
		}
	}

	void BooksCollection::delFromAvailable(const std::string name, const std::string isbn) {
		delBook(availableBooks, availableBooksByAuthor, name, isbn);
		updateFile(availableBooks, fileAvailable);
		updateFile(availableBooksByAuthor, fileAvailableByAuthor);
		delAvailableId(name, isbn);
	}

	void BooksCollection::changeName(const std::string name, const std::string newName,
		const std::string isbn) {
		int authorId{ -1 };
		auto aBook = std::make_shared<Book>();
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				authorId = i->second->getAuthorId();
				aBook->setName(newName);
				aBook->setIsbn(isbn);
				aBook->setAuthorId(authorId);
				aBook->setYear(i->second->getYear());
				aBook->setId(i->second->getId());
				i = allBooks.erase(i);
				break;
			}
		}
		bool isAvailable = false;
		auto rangeAvailabe = availableBooks.equal_range(name);
		for (auto i = rangeAvailabe.first; i != rangeAvailabe.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i = availableBooks.erase(i);
				isAvailable = true;
				break;
			}
		}
		allBooks.insert(std::make_pair(newName, aBook));
		changeName_(allBooksByAuthor, authorId, isbn, newName);
		if (isAvailable) {
			availableBooks.insert(std::make_pair(newName, aBook));
			changeName_(availableBooksByAuthor, authorId, isbn, newName);
			updateFile(availableBooks, fileAvailable);
			updateFile(availableBooksByAuthor, fileAvailableByAuthor);
		}
		updateFile(allBooks, fileAll);
		updateFile(allBooksByAuthor, fileAllByAuthor);
	}

	void BooksCollection::changeName_(std::multimap<std::string, sh_book>& collection,
		const int authorId, const std::string isbn, const std::string newName) {
		auto range = collection.equal_range(std::to_string(authorId));
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i->second->setName(newName);
				break;
			}
		}
	}

	void BooksCollection::changeAuthorId(const std::string name, const std::string isbn, 
		const int newAuthorId) {
		int authorId;
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				authorId = i->second->getAuthorId();
				i->second->setAuthorId(newAuthorId);
				break;
			}
		}
		bool isAvailable = false;
		auto rangeAvailable = availableBooks.equal_range(name);
		for (auto i = rangeAvailable.first; i != rangeAvailable.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i->second->setAuthorId(newAuthorId);
				isAvailable = true;
				break;
			}
		}
		changeAuthorId_(allBooksByAuthor, isbn, authorId, newAuthorId);
		if (isAvailable) {
			changeAuthorId_(availableBooksByAuthor, isbn, authorId, newAuthorId);
			updateFile(availableBooks, fileAvailable);
			updateFile(availableBooksByAuthor, fileAvailableByAuthor);
		}
		updateFile(allBooks, fileAll);
		updateFile(allBooksByAuthor, fileAllByAuthor);
	}

	void BooksCollection::changeAuthorId_(std::multimap<std::string, sh_book>& collection,
							const std::string isbn, const int authorId, const int newAuthorId) {
		auto aBook = std::make_shared<Book>();
		auto range = collection.equal_range(std::to_string(authorId));
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				aBook->setName(i->second->getName());
				aBook->setIsbn(isbn);
				aBook->setAuthorId(newAuthorId);
				aBook->setYear(i->second->getYear());
				aBook->setId(i->second->getId());
				i = collection.erase(i);
				break;
			}
		}
		collection.insert(std::make_pair(std::to_string(newAuthorId), aBook));
	}

	void BooksCollection::changeYear(const std::string name, const std::string isbn, 
		const int newYear) {
		int authorId;
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i->second->setYear(newYear);
				authorId = i->second->getAuthorId();
				break;
			}
		}
		auto rangeAvailable = availableBooks.equal_range(name);
		for (auto i = rangeAvailable.first; i != rangeAvailable.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i->second->setYear(newYear);
				break;
			}
		}
		changeYear_(allBooksByAuthor, isbn, authorId, newYear);
		changeYear_(availableBooksByAuthor, isbn, authorId, newYear);
		updateFile(allBooks, fileAll);
		updateFile(allBooksByAuthor, fileAllByAuthor);
		updateFile(availableBooks, fileAvailable);
		updateFile(availableBooksByAuthor, fileAvailableByAuthor);
	}

	void BooksCollection::changeYear_(std::multimap<std::string, sh_book>& collection,
									  const std::string isbn, const int authorId, const int year) {
		auto range = collection.equal_range(std::to_string(authorId));
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				i->second->setYear(year);
				break;
			}
		}
	}

	void BooksCollection::makeAvailable(const std::string name, const std::string isbn) {
		int authorId;
		auto aBook = std::make_shared<Book>();
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				aBook->setIsbn(isbn);
				aBook->setId(i->second->getId());
				availableBooksIds.insert(std::make_pair(i->second->getId(), i->second->getId()));
				aBook->setAuthorId(i->second->getAuthorId());
				aBook->setName(name);
				aBook->setYear(i->second->getYear());
				authorId = i->second->getAuthorId();
				break;
			}
		}
		availableBooks.insert(std::make_pair(name, aBook));
		availableBooksByAuthor.insert(std::make_pair(std::to_string(authorId), aBook));
		updateFile(availableBooks, fileAvailable);
		updateFile(availableBooksByAuthor, fileAvailableByAuthor);
	}

	std::vector<sh_book> BooksCollection::findByAuthor_(const std::multimap<std::string, sh_book>& collection,
								const std::vector<int> authorIds)const {
		std::vector<sh_book> search;
		for (size_t i = 0; i < authorIds.size(); i++) {
			auto range = collection.equal_range(std::to_string(authorIds[i]));
			for (auto i = range.first; i != range.second; ++i) {
				search.push_back(i->second);
			}
		}
		return search;
	}

	std::vector<sh_book> BooksCollection::findByAuthorAll(const std::vector<int> authorIds)const {
		return findByAuthor_(allBooksByAuthor, authorIds);
	}

	std::vector<sh_book> BooksCollection::findByAuthorAvailable(const std::vector<int> authorIds)const {
		return findByAuthor_(availableBooksByAuthor, authorIds);
	}

	void BooksCollection::changeIsbn(const std::string name, const std::string oldIsbn,
									 const std::string newIsbn) {
		int authorId;
		auto range = allBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == oldIsbn) {
				i->second->setIsbn(newIsbn);
				authorId = i->second->getAuthorId();
				break;
			}
		}
		auto rangeAvailable = availableBooks.equal_range(name);
		for (auto i = rangeAvailable.first; i != rangeAvailable.second; ++i) {
			if (i->second->getIsbn() == oldIsbn) {
				i->second->setIsbn(newIsbn);
				break;
			}
		}
		changeIsbn_(allBooksByAuthor, oldIsbn, authorId, newIsbn);
		changeIsbn_(availableBooksByAuthor, oldIsbn, authorId, newIsbn);
		updateFile(allBooks, fileAll);
		updateFile(allBooksByAuthor, fileAllByAuthor);
		updateFile(availableBooks, fileAvailable);
		updateFile(availableBooksByAuthor, fileAvailableByAuthor);
	}

	void BooksCollection::changeIsbn_(std::multimap<std::string, sh_book>& collection,
							const std::string oldIsbn, const int authorId, 
							const std::string newIsbn) {
		auto range = collection.equal_range(std::to_string(authorId));
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == oldIsbn) {
				i->second->setIsbn(newIsbn);
				break;
			}
		}
	}

	bool BooksCollection::isAvailable(const std::string name, const std::string isbn)const {
		auto range = availableBooks.equal_range(name);
		for (auto i = range.first; i != range.second; ++i) {
			if (i->second->getIsbn() == isbn) {
				return true;
			}
		}
		return false;
	}

	bool BooksCollection::isAvailable(const int id)const {
		auto search = availableBooksIds.find(id);
		if (search != availableBooksIds.end()) {
			return true;
		}
		else {
			return false;
		}
	}


}