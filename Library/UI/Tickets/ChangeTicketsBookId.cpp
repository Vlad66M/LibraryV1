#include "ChangeTicketsBookId.h"

//ok button
System::Void Library::ChangeTicketsBookId::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strReaderId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (isNumeric_(strReaderId)) {
		int newBookId = std::stoi(strReaderId);
		tickets->changeBookId(readerId, bookId, newBookId);
		MessageBox::Show(this, "Изменения сохранены");
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
	}
}
