#include "ChangeBookLocation.h"

//ok button
System::Void Library::ChangeBookLocation::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((textBox1->Text != "") && (textBox2->Text != "") && (textBox3->Text != "")) {
		std::string strRack = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string strShelf = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string strSection = msclr::interop::marshal_as<std::string>(textBox3->Text);

		if (isNumeric_(strRack) && isNumeric_(strShelf) && isNumeric_(strSection)) {
			int rack = std::stoi(strRack);
			int shelf = std::stoi(strShelf);
			int section = std::stoi(strSection);
			bookRecords->changeLocation(id, { rack,shelf,section });
			MessageBox::Show(this, "Изменения сохранены");
			this->Close();
		}
		else {
			MessageBox::Show(this, "Попробуйте еще раз");
			textBox1->Text = L"";
			textBox2->Text = L"";
			textBox3->Text = L"";
		}
	}
	else {
		MessageBox::Show(this, "Заполните поля");
	}
}
