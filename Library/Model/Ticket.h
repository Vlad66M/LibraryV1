#pragma once
#ifndef TICKET_H
#define TICKET_H
#include <vector>
#include <string>
#include <chrono>
#include<memory>

namespace Model {

	class Ticket {
	public:
		Ticket(){
			idReader = -1;
		}

		int getIdBook()const { return idBook; }
		void setIdBook(const int idBook) { this->idBook = idBook; }
		int getIdReader()const { return idReader; }
		void setIdReader(const int idReader) { this->idReader = idReader; }
		void setReturnDate(const std::string returnDate) {
			this->returnDate = returnDate;
		}
		void setIssueDate(const std::string issueDate) {
			this->issueDate = issueDate;
		}
		std::string getReturnDate()const {
			return returnDate;
		}
		std::string getIssueDate()const {
			return issueDate;
		}

		private:
			int idReader;
			int idBook;
			std::string issueDate;
			std::string returnDate;
	};
}
#endif // !TICKET_H
