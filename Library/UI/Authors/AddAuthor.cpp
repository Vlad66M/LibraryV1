#include "AddAuthor.h"

//ok button
System::Void Library::AddAuthor::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "") {
		MessageBox::Show(this, "¬ведите фамилию автора");
	}
	else {
		std::string surname = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string name = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string patronymic = msclr::interop::marshal_as<std::string>(textBox3->Text);
		authors->addAuthor(surname, name, patronymic);
		textBox1->Text = L"";
		textBox2->Text = L"";
		textBox3->Text = L"";
		MessageBox::Show(this, "јвтор добавлен");
	}
}

//clear button
System::Void Library::AddAuthor::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
}
