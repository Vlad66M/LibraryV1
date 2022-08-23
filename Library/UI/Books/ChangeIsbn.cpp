#include "ChangeIsbn.h"

//ok button
System::Void Library::ChangeIsbn::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "") {
		std::string newIsbn = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string name = msclr::interop::marshal_as<std::string>(BookName->ToString());
		std::string oldIsbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
		books->changeIsbn(name, oldIsbn, newIsbn);
		MessageBox::Show(this, "Изменения были сохранены");
		this->Close();
	}
	else {
		MessageBox::Show(this, "Введите ISBN книги");
	}
}
