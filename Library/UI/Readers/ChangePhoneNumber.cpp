#include "ChangePhoneNumber.h"

//ok button
System::Void Library::ChangePhoneNumber::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strPhone = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (!isPhoneNum(strPhone)) {
		MessageBox::Show(this, "Номер телефона введен неправильно");
	}
	else {
		readers->changePhoneNum(id, strPhone);
		MessageBox::Show(this, "Изменения сохранены");
		this->Close();
	}
}
