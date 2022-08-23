#include "ConfirmTicketDeleting.h"

//no button
System::Void Library::ConfirmTicketDeleting::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

//yes button
System::Void Library::ConfirmTicketDeleting::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	tickets->delTicketRecord(readerId, bookId);
	MessageBox::Show(this, "Запись удалена");
	this->Close();
}
