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
	/// Сводка для ConfirmTicketDeleting
	/// </summary>
	public ref class ConfirmTicketDeleting : public System::Windows::Forms::Form
	{
	public:
		ConfirmTicketDeleting(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		ConfirmTicketDeleting(int readerId_, int bookId_)
		{
			readerId = readerId_;
			bookId = bookId_;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ConfirmTicketDeleting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		int readerId, bookId;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->label1->Location = System::Drawing::Point(27, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 64);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вы действительно хотите удалить запись\?";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(45, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Да";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConfirmTicketDeleting::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(144, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 34);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Нет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ConfirmTicketDeleting::button2_Click);
			// 
			// ConfirmTicketDeleting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 167);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"ConfirmTicketDeleting";
			this->ResumeLayout(false);

		}
#pragma endregion
		   //no button
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

		   //yes button
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

};
}
