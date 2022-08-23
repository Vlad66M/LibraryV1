#include "ReadersMenu.h"

System::Void Library::ReadersMenu::clickAction()
{
	doAction = false;
	bool checked;
	int checksCount = 0;
	for (int i = 0; i <= dataGridView1->Rows->Count - 1; i++) {
		checked = (bool)dataGridView1->Rows[i]->Cells[3]->FormattedValue;
		if (checked) {
			docNum = (int)dataGridView1->Rows[i]->Cells[1]->Value;
			checksCount++;
			if (checksCount > 1) {
				MessageBox::Show(this, "Выберите одного читателя");
			}
		}
	}
	if (checksCount == 1) {
		doAction = true;
	}
	else if (checksCount == 0) {
		MessageBox::Show(this, "Читатель не выбран");
	}
}

System::Void Library::ReadersMenu::fillTable(const std::vector<Model::ReadersCollection::sh_reader> search)
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	for (int i = 0; i < search.size(); i++) {
		dataGridView1->Rows->Add();
		std::string name = search[i]->getSurname() + " " +
			search[i]->getName() + " " +
			search[i]->getPatronymic();
		System::String^ Name = gcnew String(name.data());
		dataGridView1->Rows[i]->Cells[0]->Value = Name;
		dataGridView1->Rows[i]->Cells[1]->Value = search[i]->getDocNumber();
		System::String^ Phone = gcnew String(search[i]->getPhone().data());
		dataGridView1->Rows[i]->Cells[2]->Value = Phone;
		dataGridView1->Rows[i]->Cells[3]->Value = false;
	}
}

//add reader button
System::Void Library::ReadersMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddReader^ addReader = gcnew AddReader();
	addReader->Show();
}

//clear button
System::Void Library::ReadersMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
	textBox4->Text = L"";
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
}

//search button
System::Void Library::ReadersMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string surname = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string name = msclr::interop::marshal_as<std::string>(textBox2->Text);
	std::string patronymic = msclr::interop::marshal_as<std::string>(textBox3->Text);
	std::string strDocNum = msclr::interop::marshal_as<std::string>(textBox4->Text);

	if ((surname == "") && (strDocNum == "")) {
		MessageBox::Show(this, "Заполните поля");
		return;
	}
	if ((strDocNum != "") && (!isNumeric_(strDocNum))) {
		MessageBox::Show(this, "Попробуйте еще раз");
		return;
	}
	std::vector<Model::ReadersCollection::sh_reader> search;
	if ((strDocNum != "") && (isNumeric_(strDocNum))) {
		int docNum = std::stoi(strDocNum);
		search = readers->findReader(docNum);
		if (search.size() > 0) {
			if ((search.back()->getSurname() != surname) && (surname != "") ||
				(search.back()->getName() != name) && (name != "") ||
				(search.back()->getPatronymic() != patronymic) && (patronymic != "")) {
				search.pop_back();
			}
		}
		if (search.size() > 0) {
			fillTable(search);
		}
		else {
			MessageBox::Show(this, "Читатель не найден");
		}
	}
	else {
		search = readers->findReader(surname, name, patronymic);
		if (search.size() > 0) {
			fillTable(search);
		}
		else {
			MessageBox::Show(this, "Читатель не найден");
		}
	}
}

//change name button
System::Void Library::ReadersMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeReadersName^ changeReadersName = gcnew ChangeReadersName(docNum);
		changeReadersName->Show();
	}
}

//confirm deleting
System::Void Library::ReadersMenu::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmDeletingReader^ confirmDeleting = gcnew ConfirmDeletingReader(docNum);
		confirmDeleting->Show();
	}
}

//change phone number button
System::Void Library::ReadersMenu::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangePhoneNumber^ changePhoneNumber = gcnew ChangePhoneNumber(docNum);
		changePhoneNumber->Show();
	}
}
