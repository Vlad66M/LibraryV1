#include "ConfirmBookDeleting.h"

//no button
System::Void Library::ConfirmBookDeleting::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

//yes button
System::Void Library::ConfirmBookDeleting::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string name = msclr::interop::marshal_as<std::string>(bookName->ToString());
	std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
	books->delFromAll(name, isbn);
	MessageBox::Show(this, "Книга удалена");
	this->Close();
}
