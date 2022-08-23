#include "ChangeReturnDate.h"

//ok button
System::Void Library::ChangeReturnDate::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ ReturnDate = dateTimePicker1->Value.ToShortDateString()->ToString();
	std::string returnDate = msclr::interop::marshal_as<std::string>(ReturnDate);
	tickets->changeReturnDate(readerId, bookId, returnDate);
	MessageBox::Show(this, "Изменения сохранены");
}
