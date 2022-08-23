#pragma once
#include <msclr\marshal_cppstd.h>
#include"../../Model/Global.h"
#include "../../View/View.h"

namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� ChangeBookAuthorsId
	/// </summary>
	public ref class ChangeBookAuthorsId : public System::Windows::Forms::Form
	{
	public:
		ChangeBookAuthorsId(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		ChangeBookAuthorsId(System::String^ name, System::String^ Isbn_)
		{
			bookName = name;
			Isbn = Isbn_;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ChangeBookAuthorsId()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::String^ bookName;
		System::String^ Isbn;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(68, 120);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(73, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChangeBookAuthorsId::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(65, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Id ������ �����:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(68, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 27);
			this->textBox1->TabIndex = 2;
			// 
			// ChangeBookAuthorsId
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(317, 204);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ChangeBookAuthorsId";
			this->Text = L"��������� Id ������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//ok button
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
