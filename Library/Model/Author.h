#pragma once
#ifndef AUTHOR_H
#define AUTHOR_H
#include "Human.h"


namespace Model {

	class Author :public Human {
	public:
		int getId() const { return idAuthor; }

	private:
		void setId(const int id) { idAuthor = id; }
		int idAuthor;

		friend class AuthorsCollection;
	};

}

#endif // !AUTHOR_H
