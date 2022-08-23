#include "AddReader.h"

//ok button
System::Void Library::AddReader::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string surname = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string name = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::string patronymic = msclr::interop::marshal_as<std::string>(textBox3->Text);
	std::string strPhone = msclr::interop::marshal_as<std::string>(textBox4->Text);
	if (surname == "" || name == "" || patronymic == "" || strPhone == "") {
		MessageBox::Show(this, "Заполните поля");
	}
	else {
		if (!isPhoneNum(strPhone)) {
			MessageBox::Show(this, "Номер телефона введен неправильно");
		}
		else {
			readers->addReader(surname, name, patronymic, strPhone);
			MessageBox::Show(this, "Номер присвоенного читательского билета: "
				+ readers->getLastDocNumber().ToString());
		}
	}
}

//clear button
System::Void Library::AddReader::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
	textBox4->Text = L"";
}
