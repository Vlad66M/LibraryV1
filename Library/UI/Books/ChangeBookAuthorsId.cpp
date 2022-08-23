#include "ChangeBookAuthorsId.h"

//ok button
System::Void Library::ChangeBookAuthorsId::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "") {
		std::string strAuthorId = msclr::interop::marshal_as<std::string>(textBox1->Text);
		if (isNumeric_(strAuthorId)) {
			std::string name = msclr::interop::marshal_as<std::string>(bookName->ToString());
			std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
			int authorId = std::stoi(strAuthorId);
			books->changeAuthorId(name, isbn, authorId);
			MessageBox::Show(this, "Изменения сохранены");
			this->Hide();
		}
		else {
			MessageBox::Show(this, "Попробуйте еще раз");
			textBox1->Text = L"";
		}
	}
	else {
		MessageBox::Show(this, "Введите Id автора");
	}
}
