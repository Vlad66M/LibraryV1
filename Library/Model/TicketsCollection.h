#pragma once
#ifndef TICKETS_COLLECTION_H
#define TICKETS_COLLECTION_H
#include "Ticket.h"
#include <vector>
#include <map>
#include <memory>
#include <fstream>

namespace Model {

	class TicketsCollection {
	public:
		using sh_tickets = std::shared_ptr<Ticket>;

		void addTicket(const int idReader, const int idBook,
			const std::string issueDate, const std::string returnDate);
		void recieveTickets();
		std::vector<sh_tickets> findTicket(const int idReader, const int idBook)const;
		void delTicketRecord(const int idReader, const int idBook);
		void changeReaderId(const int oldReaderId, const int newReaderId, const int bookId);
		void delReader(const int readerId);
		void changeBookId(const int readerId, const int oldBookId, const int newBookId);
		void changeReturnDate(const int readerId, const int bookId, const std::string returnDate);

	private:
		void updateFile();
		std::multimap<int, sh_tickets> tickets;
	};
}
#endif // !TICKETS_COLLECTION_H
