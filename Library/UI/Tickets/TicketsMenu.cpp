#include "TicketsMenu.h"

System::Void Library::TicketsMenu::fillTable(const std::vector<Model::TicketsCollection::sh_tickets> search)
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	dataGridView1->Show();
	for (int i = 0; i < search.size(); i++) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = search[i]->getIdReader();
		dataGridView1->Rows[i]->Cells[1]->Value = search[i]->getIdBook();
		System::String^ IssueDate = gcnew String(search[i]->getIssueDate().data());
		System::String^ ReturnDate = gcnew String(search[i]->getReturnDate().data());
		dataGridView1->Rows[i]->Cells[2]->Value = IssueDate;
		dataGridView1->Rows[i]->Cells[3]->Value = ReturnDate;
		dataGridView1->Rows[i]->Cells[4]->Value = false;
	}
}

System::Void Library::TicketsMenu::clickAction()
{
	doAction = false;
	bool checked;
	int checksCount = 0;
	for (int i = 0; i <= dataGridView1->Rows->Count - 1; i++) {
		checked = (bool)dataGridView1->Rows[i]->Cells[4]->FormattedValue;
		if (checked) {
			readerId = (int)dataGridView1->Rows[i]->Cells[0]->Value;
			bookId = (int)dataGridView1->Rows[i]->Cells[1]->Value;
			checksCount++;
			if (checksCount > 1) {
				MessageBox::Show(this, "Выберите одну запись");
			}
		}
	}
	if (checksCount == 1) {
		doAction = true;
	}
	else if (checksCount == 0) {
		MessageBox::Show(this, "Запись не выбрана");
	}
}

//search button
System::Void Library::TicketsMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strReaderId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string strBookId = msclr::interop::marshal_as<std::string>(textBox2->Text);
	if (isNumeric_(strReaderId)) {
		int readerId = std::stoi(strReaderId);
		int bookId = -1;
		if (!strBookId.empty()) {
			if (!isNumeric_(strBookId)) {
				MessageBox::Show(this, "Попробуйте еще раз");
			}
			else {
				bookId = std::stoi(strBookId);
			}
		}
		auto search = tickets->findTicket(readerId, bookId);
		if (search.empty()) {
			MessageBox::Show(this, "Запись не найдена");
		}
		else {
			fillTable(search);
		}
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
	}
}

//add ticket button
System::Void Library::TicketsMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddTicket^ addTicket = gcnew AddTicket();
	addTicket->Show();
}

//clear button
System::Void Library::TicketsMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
}

//change reader's Id button
System::Void Library::TicketsMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeTicketsReaderId^ changeTicketsReaderId = gcnew ChangeTicketsReaderId(readerId,
			bookId);
		changeTicketsReaderId->Show();
	}
}

//change book's Id button
System::Void Library::TicketsMenu::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeTicketsBookId^ changeTicketsBookId = gcnew ChangeTicketsBookId(readerId,
			bookId);
		changeTicketsBookId->Show();
	}
}

//change return date button
System::Void Library::TicketsMenu::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeReturnDate^ changeReturnDate = gcnew ChangeReturnDate(readerId, bookId);
		changeReturnDate->Show();
	}
}

//del button
System::Void Library::TicketsMenu::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmTicketDeleting^ confirmTicketDeleting = gcnew ConfirmTicketDeleting(readerId,
			bookId);
		confirmTicketDeleting->Show();
	}
}

//return book button
System::Void Library::TicketsMenu::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		bookRecords->increaseBookCount(bookId);
		tickets->delTicketRecord(readerId, bookId);
		MessageBox::Show(this, "Книга возвращена");
	}
}
