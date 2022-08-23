#include "ChangeRecordId.h"

//ok button
System::Void Library::ChangeRecordId::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strId = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (isNumeric_(strId)) {
		int newId = std::stoi(strId);
		bookRecords->changeId(id, newId);
		MessageBox::Show(this, "Изменения сохранены");
		this->Close();
	}
	else {
		MessageBox::Show(this, "Попробуйте еще раз");
	}
}
