#include "AddTicket.h"

//ok button
System::Void Library::AddTicket::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strReaderId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string strBookId = msclr::interop::marshal_as<std::string>(textBox2->Text);
	if (isNumeric_(strReaderId) && isNumeric_(strBookId)) {
		int idReader = std::stoi(strReaderId);
		int idBook = std::stoi(strBookId);
		if (readers->isRegistered(idReader)) {
			if (bookRecords->getBookCount(idBook) > 0) {
				System::String^ ReturnDate = dateTimePicker1->Value.ToShortDateString()->ToString();
				System::DateTime now = System::DateTime::Now;
				System::String^ IssueDate = now.ToShortDateString()->ToString();
				std::string issueDate = msclr::interop::marshal_as<std::string>(IssueDate);
				std::string returnDate = msclr::interop::marshal_as<std::string>(ReturnDate);
				tickets->addTicket(idReader, idBook, issueDate, returnDate);
				MessageBox::Show(this, "Запись сохранена");
				textBox1->Text = L"";
				textBox2->Text = L"";
				bookRecords->decreaseBookCount(idBook);
			}
			else {
				MessageBox::Show(this, "В библиотеке нет свободных экземпляров книги");
			}
		}
		else {
			MessageBox::Show(this, "Читатель с таким Id не зарегистрирован");
		}

	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
		textBox1->Text = L"";
		textBox2->Text = L"";
	}
}
