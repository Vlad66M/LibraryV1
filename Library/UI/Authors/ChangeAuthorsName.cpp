#include "ChangeAuthorsName.h"

//ok button
System::Void Library::ChangeAuthorsName::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((textBox1->Text != "") && (textBox2->Text != "") && (textBox3->Text != "")) {
		std::string newSurname = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string newName = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string newPatronymic = msclr::interop::marshal_as<std::string>(textBox3->Text);
		authors->changeName(id, newSurname, newName, newPatronymic);
		MessageBox::Show(this, "Изменения сохранены");
	}
	else {
		MessageBox::Show(this, "Введите фамилию автора");
	}
	this->Close();
}

//clear button
System::Void Library::ChangeAuthorsName::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
}
