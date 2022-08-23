#pragma once
#include <string>

#ifndef HUMAN_H
#define HUMAN_H

namespace Model {

	class Human {
	public:
		Human(std::string surname, std::string name, std::string patrinomic) :
			surname(surname), name(name), patronymic(patrinomic) {}
		Human() : surname(""), name(""), patronymic("") {}

		std::string getName()const { return name; }
		std::string getSurname()const { return surname; }
		std::string getPatronymic()const { return patronymic; }

		void setName(const std::string name) {
			this->name = name;
		}
		void setSurname(const std::string surname) {
			this->surname = surname;
		}
		void setPatronymic(const std::string patrinomic) {
			this->patronymic = patrinomic;
		}

	private:
		std::string surname;
		std::string name;
		std::string  patronymic;
	};
}

#endif // !HUMAN_H
