#include "ChangeTicketsReaderId.h"

//ok button
System::Void Library::ChangeTicketsReaderId::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strReaderId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (isNumeric_(strReaderId)) {
		int newReaderId = std::stoi(strReaderId);
		tickets->changeReaderId(readerId, newReaderId, bookId);
		MessageBox::Show(this, "Изменения сохранены");
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
	}
}
