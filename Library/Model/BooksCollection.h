#pragma once
#ifndef BOOKSCOLLECTION_H
#define BOOKSCOLLECTION_H
#include "Book.h"
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <chrono>
#include <iostream>


namespace Model {
	using sh_book = std::shared_ptr<Book>;

	class BooksCollection {
	public:
		using sh_book = std::shared_ptr<Book>;

		void addBook(const int param, const int idAuthor, const int year, 
			const std::string name, const std::string isbn);
		void recieveBooks();
		std::vector<sh_book> findInAll(const std::string name, const std::string isbn, 
			const int year =-1, const int authorId = -1)const;
		std::vector<sh_book> findInAvailable(const std::string name, const std::string isbn, 
											 const int year = -1, const int authorId =-1) const;
		std::vector<sh_book> findByAuthorAll(const std::vector<int> authorIds)const;
		std::vector<sh_book> findByAuthorAvailable(const std::vector<int> authorIds)const;
		std::vector<sh_book> findByIdAll(const int id)const;
		std::vector<sh_book> findByIdAvailable(const int id)const;
		void delFromAll(const std::string name, const std::string isbn);
		void delFromAvailable(const std::string name, const std::string isbn);
		void changeName(const std::string name, const std::string newName, 
			const std::string isbn);
		void changeAuthorId(const std::string name, const std::string isbn, 
			const int newAuthorId);
		void makeAvailable(const std::string name, const std::string isbn);
		void changeYear(const std::string name, const std::string isbn, 
			const int newYear);
		void changeIsbn(const std::string name, const std::string oldIsbn, 
			const std::string newIsbn);
		bool isAvailable(const std::string name, const std::string isbn)const;
		bool isAvailable(const int id)const;
		void recieveAvailableIds();

	private:
		void updateFile(const std::multimap<std::string, sh_book>& books,
			const std::string fileName);
		void getBooksFromFile(std::multimap<std::string, sh_book>& books,
							  const std::string fileName);
		std::vector<sh_book> findBook(const std::multimap<std::string, sh_book>& collection,
			const std::string name, const std::string isbn, const int year, const int authorId)const;
		std::vector<sh_book> findByAuthor_(const std::multimap<std::string, sh_book>& collection,
									      const std::vector<int> authorIds)const;
		std::vector<sh_book> findById(const std::multimap<std::string, sh_book>& collection, 
			const int id)const;
		void delBook(std::multimap<std::string, sh_book>& collection,
					 std::multimap<std::string, sh_book>& collectionByAuthor,
					 const std::string name, const std::string isbn);
		void changeName_(std::multimap<std::string, sh_book>& collection,
						 const int authorId, const std::string isbn, const std::string newName);
		void changeAuthorId_(std::multimap<std::string, sh_book>& collection,
							 const std::string isbn, const int authorId, const int newAuthorId);
		void changeYear_(std::multimap<std::string, sh_book>& collection,
						 const std::string isbn, const int authorId, const int year);

		void changeIsbn_(std::multimap<std::string, sh_book>& collection,
						 const std::string oldIsbn, const int authorId, const std::string newIsbn);
		void updateAvailableBooksIds();
		void delAvailableId(const std::string name, const std::string isbn);

		std::multimap<std::string, sh_book> allBooks;
		std::multimap<std::string, sh_book> availableBooks;
		std::multimap<std::string, sh_book> allBooksByAuthor;
		std::multimap<std::string, sh_book> availableBooksByAuthor;
		std::string fileAll = "data/all_books.txt";
		std::string fileAvailable = "data/available_books.txt";
		std::string fileAllByAuthor = "data/all_books_by_author.txt";
		std::string fileAvailableByAuthor = "data/available_books_by_author.txt";
		std::string fileAvailableIds = "data/available_books_ids.txt";
		std::map<int, int> availableBooksIds;
	};
}
#endif // !BOOKSCOLLECTION_H
