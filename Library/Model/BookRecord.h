#pragma once
#ifndef BOOKRECORD_H
#define BOOKRECORD_H



namespace Model {

	class BookRecord {
	public:
		struct BookLocation {
		public:
			BookLocation(int rack, int shelf, int section) :
				rack(rack), shelf(shelf), section(section) {}
			BookLocation() :BookLocation(0, 0, 0) {}

			int getRack()const { return rack; }
			void setRack(const int rack) { this->rack = rack; }
			int getShelf()const { return shelf; }
			void setShelf(const int shelf) { this->shelf = shelf; }
			int getSection()const { return section; }
			void setSection(const int section) { this->section = section; }
		private:
			int rack;
			int shelf;
			int section;
		};

	public:
		int getBookId()const { return idBook; }
		void setBookId(const int idBook) { this->idBook = idBook; }
		int getCount()const { return count; }
		void setCount(const int count) { this->count = count; }
		void setLocation(const BookLocation location) { this->location = location; }
		BookLocation getLocation()const { return location; }

	private:
		int idBook;
		int count;
		BookLocation location;
	};
}
#endif // !BOOKRECORD
