#include "AddBook.h"

//ok button
System::Void Library::AddBook::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string name = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string tmpIdAuthor = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::string tmpYear = msclr::interop::marshal_as<std::string>(textBox3->Text);
	std::string isbn = msclr::interop::marshal_as<std::string>(textBox4->Text);
	int idAuthor;
	int year;
	if (isNumeric_(tmpIdAuthor) &&
		isNumeric_(tmpYear) &&
		(textBox1->Text != L"") &&
		(textBox4->Text != L"")) {

		idAuthor = System::Convert::ToInt32(textBox2->Text);
		year = System::Convert::ToInt32(textBox3->Text);
		int param = 1;
		if (checkBox1->Checked) {
			param = 0;
		}
		books->addBook(param, idAuthor, year, name, isbn);
		MessageBox::Show(this, "Книга добавлена");
		textBox1->Text = L"";
		textBox2->Text = L"";
		textBox3->Text = L"";
		textBox4->Text = L"";
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
		textBox1->Text = L"";
		textBox2->Text = L"";
		textBox3->Text = L"";
		textBox4->Text = L"";
	}
}

//clear button
System::Void Library::AddBook::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
	textBox4->Text = L"";
}
