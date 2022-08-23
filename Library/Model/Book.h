#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>

namespace Model {

	class Book {
	public:

		Book(std::string isbn, int idAuthor, int year, std::string name) :
			isbn(isbn), idAuthor(idAuthor),
			year(year), name(name) {}

		Book() :Book("", -1, -1, "") {}

		
		int getAuthorId()const { return idAuthor; }
		void setAuthorId(const int id) { idAuthor = id; }
		int getYear()const { return year; }
		void setYear(const int year) { this->year = year; }
		std::string getName()const { return name; }
		void setName(const std::string name) { this->name = name; }
		std::string getIsbn()const { return isbn; }
		void setIsbn(const std::string isbn) { this->isbn = isbn; }
		int getId()const  { return id; }

	private:
		void setId(const int id) { this->id = id; }

		int idAuthor;
		int year;
		int id;
		std::string name;
		std::string isbn;
		friend class BooksCollection;
	};
}
#endif // !BOOK_H
