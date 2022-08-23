#include "ConfirmDeletingReader.h"

//yes button
System::Void Library::ConfirmDeletingReader::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	readers->delReader(docNum);
	MessageBox::Show(this, "Читатель удален");
	this->Close();
}

//no button
System::Void Library::ConfirmDeletingReader::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
