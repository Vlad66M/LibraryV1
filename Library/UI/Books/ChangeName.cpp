#include "ChangeName.h"

//ok button
System::Void Library::ChangeName::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "") {
		std::string newName = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string name = msclr::interop::marshal_as<std::string>(BookName->ToString());
		std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
		books->changeName(name, newName, isbn);
		MessageBox::Show(this, "Изменения были сохранены");
		this->Close();
	}
	else {
		MessageBox::Show(this, "Введите название книги");
	}
}

//clear button
System::Void Library::ChangeName::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
}
