#include "TicketsCollection.h"

namespace Model {

	using sh_tickets = std::shared_ptr<Ticket>;

	void TicketsCollection::addTicket(const int idReader, const int idBook,
		const std::string issueDate, const std::string returnDate) {
		auto newTicket = std::make_shared<Ticket>();
		newTicket->setIdReader(idReader);
		newTicket->setIdBook(idBook);
		newTicket->setIssueDate(issueDate);
		newTicket->setReturnDate(returnDate);
		tickets.insert(std::make_pair(idReader, newTicket));
		updateFile();
	}

	void TicketsCollection::updateFile() {
		std::ofstream ticketsFile;
		ticketsFile.open("data/tickets.txt");
		if (ticketsFile.is_open()) {
			for (auto el : tickets) {
				ticketsFile << "\nReader Id\n" << el.second->getIdReader() <<
					"\nBook Id\n" << el.second->getIdBook() << "\nIssue Date\n" <<
					el.second->getIssueDate() << "\nReturn Date\n" <<
					el.second->getReturnDate() << "\nend of record\n";
			}
			ticketsFile.close();
		}
	}

	void TicketsCollection::recieveTickets() {
		std::ifstream ticketsFile;
		ticketsFile.open("data/tickets.txt");
		if (ticketsFile.is_open()) {
			std::string current{};
			std::string prev{};
			std::string prevReaderId{};
			int currentBookId;
			int currentReaderId;
			std::string currentIssueDate;
			std::string currentReturnDate;
			while (!ticketsFile.eof()) {
				std::getline(ticketsFile, current);
				auto t = std::make_shared<Ticket>();
				if (prev == "Reader Id") {
					currentReaderId = std::stoi(current);
				}
				if (prev == "Book Id") {
					currentBookId = std::stoi(current);
				}
				if (prev == "Issue Date") {
					currentIssueDate = current;
				}
				if (prev == "Return Date") {
					currentReturnDate = current;
				}
				if (current == "end of record") {
					t->setIdReader(currentReaderId);
					t->setIdBook(currentBookId);
					t->setIssueDate(currentIssueDate);
					t->setReturnDate(currentReturnDate);
					tickets.insert(std::make_pair(t->getIdReader(), t));
				}
				prev = current;
			}
			ticketsFile.close();
		}
	}

	std::vector<sh_tickets> TicketsCollection::findTicket(const int idReader, 
		const int idBook)const {
		std::vector<sh_tickets> search;
		auto range = tickets.equal_range(idReader);
		if (idBook == -1) {
			for (auto i = range.first; i != range.second; i++) {
				search.push_back(i->second);
			}
			return search;
		}
		else {
			for (auto i = range.first; i != range.second; i++) {
				if (i->second->getIdBook() == idBook) {
					search.push_back(i->second);
					return search;
				}
			}
			return search;
		}
	}

	void TicketsCollection::delTicketRecord(const int idReader, const int idBook) {
		auto range = tickets.equal_range(idReader);
		for (auto i = range.first; i != range.second; i++) {
			if (i->second->getIdBook() == idBook) {
				i = tickets.erase(i);
				break;
			}
		}
		updateFile();
	}

	void TicketsCollection::delReader(int readerId) {
		tickets.erase(readerId);
		updateFile();
	}

	void TicketsCollection::changeReaderId(const int oldReaderId, const int newReaderId, 
		const int bookId) {
		auto range = tickets.equal_range(oldReaderId);
		for (auto i = range.first; i != range.second; i++) {
			if (i->second->getIdBook() == bookId) {
				auto newTicket = std::make_shared<Ticket>();
				newTicket->setIdReader(newReaderId);
				newTicket->setIdBook(bookId);
				newTicket->setIssueDate(i->second->getIssueDate());
				newTicket->setReturnDate(i->second->getReturnDate());
				i = tickets.erase(i);
				tickets.insert(std::make_pair(newReaderId, newTicket));
				updateFile();
				break;
			}
		}
	}

	void TicketsCollection::changeBookId(const int readerId, const int oldBookId, 
		const int newBookId) {
		auto range = tickets.equal_range(readerId);
		for (auto i = range.first; i != range.second; i++) {
			if (i->second->getIdBook() == oldBookId) {
				i->second->setIdBook(newBookId);
				updateFile();
			}
		}
	}

	void TicketsCollection::changeReturnDate(const int readerId, const int bookId,
		const std::string returnDate) {
		auto range = tickets.equal_range(readerId);
		for (auto i = range.first; i != range.second; i++) {
			if (i->second->getIdBook() == bookId) {
				i->second->setReturnDate(returnDate);
				updateFile();
			}
		}
	}

	
}