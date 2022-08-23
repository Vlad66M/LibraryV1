#include "AuthorsMenu.h"

System::Void Library::AuthorsMenu::fillTable(std::vector<Model::AuthorsCollection::sh_author> search)
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
		dataGridView1->Rows[i]->Cells[1]->Value = search[i]->getId();
		dataGridView1->Rows[i]->Cells[2]->Value = false;
	}
}

System::Void Library::AuthorsMenu::clickAction()
{
	doAction = false;
	bool checked;
	int checksCount = 0;
	for (int i = 0; i <= dataGridView1->Rows->Count - 1; i++) {
		checked = (bool)dataGridView1->Rows[i]->Cells[2]->FormattedValue;
		if (checked) {
			id = (int)dataGridView1->Rows[i]->Cells[1]->Value;
			checksCount++;
			if (checksCount > 1) {
				MessageBox::Show(this, "Выберите одного автора");
			}
		}
	}
	if (checksCount == 1) {
		doAction = true;
	}
	else if (checksCount == 0) {
		MessageBox::Show(this, "Автор не выбран");
	}
}

//search button
System::Void Library::AuthorsMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string name = msclr::interop::marshal_as<std::string>(textBox2->Text);
	if (strId.empty() && name.empty()) {
		MessageBox::Show(this, "Заполните поля");
		return;
	}
	if ((strId != "") && (!isNumeric_(strId))) {
		MessageBox::Show(this, "Попробуйте еще раз");
		return;
	}
	if (strId != "") {
		int id = std::stoi(strId);
		auto search = authors->findAuthor(id);
		if (search.size() > 0) {
			fillTable(search);
		}
		else {
			MessageBox::Show(this, "Автор не найден");
		}
	}
	else {
		std::vector<std::string> names = splitToWords(name);
		auto search = authors->findAuthor(names);
		if (search.size() > 0) {
			fillTable(search);
		}
		else {
			MessageBox::Show(this, "Автор не найден");
		}
	}
}

//clear button
System::Void Library::AuthorsMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
}

//add author button
System::Void Library::AuthorsMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddAuthor^ addAuthor = gcnew AddAuthor;
	addAuthor->Show();
}

//change name button
System::Void Library::AuthorsMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeAuthorsName^ changeName = gcnew ChangeAuthorsName(id);
		changeName->Show();
	}
}

//del button
System::Void Library::AuthorsMenu::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmDeletingAuthor^ confirmDeletingAuthor = gcnew ConfirmDeletingAuthor(id);
		confirmDeletingAuthor->Show();
	}
}
