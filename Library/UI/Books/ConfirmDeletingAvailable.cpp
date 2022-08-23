#include "ConfirmDeletingAvailable.h"

//yes button
System::Void Library::ConfirmDeletingAvailable::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string name = msclr::interop::marshal_as<std::string>(BookName->ToString());
	std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
	books->delFromAvailable(name, isbn);
	MessageBox::Show(this, "Книга удалена");
	this->Close();
}

//no button
System::Void Library::ConfirmDeletingAvailable::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
