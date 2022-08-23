#include "ChangeYear.h"

//ok button
System::Void Library::ChangeYear::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "") {
		std::string strYear = msclr::interop::marshal_as<std::string>(textBox1->Text);
		if (isNumeric_(strYear)) {
			std::string name = msclr::interop::marshal_as<std::string>(BookName->ToString());
			std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
			int newYear = std::stoi(strYear);
			books->changeYear(name, isbn, newYear);
			MessageBox::Show(this, "��������� ���������");
			this->Close();
		}
		else {
			MessageBox::Show(this, "������� ���");
			textBox1->Text = L"";
		}
	}
	else {
		MessageBox::Show(this, "������� ��� �������");
	}
}
