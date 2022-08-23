#include "ConfirmDeletingAuthor.h"

//yes button
System::Void Library::ConfirmDeletingAuthor::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	authors->delAuthor(id);
	MessageBox::Show(this, "Автор удален");
	this->Close();
}

//no button
System::Void Library::ConfirmDeletingAuthor::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
