#pragma once
#include"../../Model/Global.h"

namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� ConfirmDeletingReader
	/// </summary>
	public ref class ConfirmDeletingReader : public System::Windows::Forms::Form
	{
	public:
		ConfirmDeletingReader(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		ConfirmDeletingReader(int docNum_)
		{
			docNum = docNum_;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ConfirmDeletingReader()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		int docNum;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(25, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 61);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�� ������������� ������ ������� ��������\?";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(52, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConfirmDeletingReader::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(150, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"���";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ConfirmDeletingReader::button2_Click);
			// 
			// ConfirmDeletingReader
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 183);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"ConfirmDeletingReader";
			this->ResumeLayout(false);

		}
#pragma endregion
		//yes button
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

		//no button
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
