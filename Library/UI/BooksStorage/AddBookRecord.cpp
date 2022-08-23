#include "AddBookRecord.h"

//ok button
System::Void Library::AddBookRecord::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string strCount = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::string strRack = msclr::interop::marshal_as<std::string>(textBox3->Text);
	std::string strShelf = msclr::interop::marshal_as<std::string>(textBox4->Text);
	std::string strSection = msclr::interop::marshal_as<std::string>(textBox5->Text);
	if (isNumeric_(strId) &&
		isNumeric_(strCount) &&
		isNumeric_(strRack) &&
		isNumeric_(strShelf) &&
		isNumeric_(strSection)) {
		int id = std::stoi(strId);
		if (books->isAvailable(id)) {
			int count = std::stoi(strCount);
			int rack = std::stoi(strRack);
			int shelf = std::stoi(strShelf);
			int section = std::stoi(strSection);
			bookRecords->addRecord(id, count, { rack,shelf,section });
			MessageBox::Show(this, "������ ���������");
			textBox1->Text = L"";
			textBox2->Text = L"";
			textBox3->Text = L"";
			textBox4->Text = L"";
			textBox5->Text = L"";
		}
		else {
			MessageBox::Show(this, "����� � ����� Id ��� � ������� ���������");
			textBox1->Text = L"";
			textBox2->Text = L"";
			textBox3->Text = L"";
			textBox4->Text = L"";
			textBox5->Text = L"";
		}

	}
	else {
		MessageBox::Show(this, "���������� ��� ���");
		textBox1->Text = L"";
		textBox2->Text = L"";
		textBox3->Text = L"";
		textBox4->Text = L"";
		textBox5->Text = L"";
	}
}
