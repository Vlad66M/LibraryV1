#pragma once
#ifndef AUTHORSCOLLECTION_H
#define AUTHORSCOLLECTION_H
#include "Author.h"
#include <map>
#include<vector>
#include <memory>
#include <fstream>
#include"SplitToWords.h"

namespace Model {

	class AuthorsCollection {
	public:
		using sh_author = std::shared_ptr<Author>;

		void addAuthor(const std::string surname, const std::string name, 
			const std::string patronymic);
		void recieveAuthors();
		std::vector<sh_author> findAuthor(const int id, const std::string surname, 
							 const std::string name, const std::string patronymic) const;
		std::vector<sh_author> findAuthor(const int id, 
			const std::vector <std::string> names) const;
		std::vector<sh_author> findAuthor(const int id) const;
		std::vector<sh_author> findAuthor(const std::vector <std::string> names) const;
		void delAuthor(const int id);
		void changeName(const int id, const std::string newSurname, 
			const std::string newName, const std::string newPatronymic);

		
	private:

		template<typename T>
		void updateFile(const std::multimap<T, sh_author>& collection,
						const std::string fileName);
		
		std::multimap<std::string, sh_author> authorsByName;
		std::multimap<int, sh_author> authorsById; 
		std::string fileAuthorsByName = "data/authorsByName.txt";
		std::string fileAuthorsById = "data/authorsById.txt";

	};
}
#endif // !AUTHORSCOLLECTION_H
