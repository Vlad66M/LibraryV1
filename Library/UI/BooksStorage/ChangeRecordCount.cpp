#include "ChangeRecordCount.h"

//ok button
System::Void Library::ChangeRecordCount::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string strCount = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (isNumeric_(strCount)) {
		int count = std::stoi(strCount);
		bookRecords->changeCount(id, count);
		MessageBox::Show(this, "��������� ���������");
		this->Close();
	}
	else {
		MessageBox::Show(this, "���������� ��� ���");
	}
}
