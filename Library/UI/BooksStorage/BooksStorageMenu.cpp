#include "BooksStorageMenu.h"

System::Void Library::BooksStorageMenu::clickAction()
{
	doAction = false;
	bool checked;
	int checksCount = 0;
	if (dataGridView1->Rows->Count > 0) {
		checked = (bool)dataGridView1->Rows[0]->Cells[3]->FormattedValue;
		if (checked) {
			id = (int)dataGridView1->Rows[0]->Cells[0]->Value;
			checksCount++;
		}
		if (checksCount == 1) {
			doAction = true;
		}
		else if (checksCount == 0) {
			MessageBox::Show(this, "Книга не выбрана");
		}
	}
}

//search button
System::Void Library::BooksStorageMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (isNumeric_(strId)) {
		int id = std::stoi(strId);
		Model::BookRecordsCollection::sh_book_records search = bookRecords->find(id);
		if (search->getBookId() == -1) {
			MessageBox::Show(this, "Книга не найдена");
		}
		else {
			dataGridView1->Rows->Clear();
			dataGridView1->Refresh();
			dataGridView1->Show();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[0]->Value = search->getBookId();
			dataGridView1->Rows[0]->Cells[1]->Value = search->getCount();
			System::String^ Location;
			std::string location = "стеллаж " +
				std::to_string(search->getLocation().getRack()) +
				",  полка " + std::to_string(search->getLocation().getShelf()) +
				", секция " + std::to_string(search->getLocation().getSection());
			Location = gcnew String(location.data());
			dataGridView1->Rows[0]->Cells[2]->Value = Location;
			dataGridView1->Rows[0]->Cells[3]->Value = false;
		}
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
		textBox1->Text = L"";
	}
}

//add button
System::Void Library::BooksStorageMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddBookRecord^ addBookRecord = gcnew AddBookRecord();
	addBookRecord->Show();
}

//change Id button
System::Void Library::BooksStorageMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeRecordId^ changeRecordId = gcnew ChangeRecordId(id);
		changeRecordId->Show();
	}
}

//change count button
System::Void Library::BooksStorageMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeRecordCount^ changeRecordCount = gcnew ChangeRecordCount(id);
		changeRecordCount->Show();
	}
}

//del button
System::Void Library::BooksStorageMenu::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmBookRecordDeleting^ confirmBookRecDeleting = gcnew ConfirmBookRecordDeleting(id);
		confirmBookRecDeleting->Show();
	}
}

//change location button
System::Void Library::BooksStorageMenu::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeBookLocation^ changeBookLocation = gcnew ChangeBookLocation(id);
		changeBookLocation->Show();
	}
}

//change location button
System::Void Library::BooksStorageMenu::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
}
