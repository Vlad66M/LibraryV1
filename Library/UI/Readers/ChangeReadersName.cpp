#include "ChangeReadersName.h"

//ok button
System::Void Library::ChangeReadersName::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string surname = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string name = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::string patronymic = msclr::interop::marshal_as<std::string>(textBox3->Text);
	if (surname == "" || name == "" || patronymic == "") {
		MessageBox::Show(this, "Заполните поля");
	}
	else {
		readers->changeName(docNum, surname, name, patronymic);
		MessageBox::Show(this, "Изменения сохранены");
		this->Close();
	}
}
