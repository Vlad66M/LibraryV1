#include "ConfirmBookRecordDeleting.h"

//no button
System::Void Library::ConfirmBookRecordDeleting::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

//yes button
System::Void Library::ConfirmBookRecordDeleting::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	bookRecords->delRecord(id);
	MessageBox::Show(this, "Запись удалена");
	this->Close();
}
