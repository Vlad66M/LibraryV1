#pragma once
#include"Model/BooksCollection.h"
#include "UI/Books/BooksMenu.h"
#include"UI/Authors/AuthorsMenu.h"
#include"UI/Tickets/TicketsMenu.h"
#include"UI/BooksStorage/BooksStorageMenu.h"
#include "View/View.h"
#include"UI/Readers/ReadersMenu.h"

namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class LibraryMenu : public System::Windows::Forms::Form
	{
	public:
		LibraryMenu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LibraryMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(155, 32);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Книги";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LibraryMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(155, 132);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(267, 70);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Авторы";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LibraryMenu::button2_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(155, 445);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(267, 72);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Выдача книг";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &LibraryMenu::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(155, 231);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(267, 72);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Читатели";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &LibraryMenu::button5_Click_1);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(155, 334);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(267, 77);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Хранение книг";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &LibraryMenu::button6_Click);
			// 
			// LibraryMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(601, 556);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"LibraryMenu";
			this->Text = L"Главное меню";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		BooksMenu^ booksMenu = gcnew BooksMenu();
		booksMenu->Show();
		/*BooksMenu^ booksMenu = gcnew BooksMenu;
		booksMenu->Show();*/
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		AuthorsMenu^ authorsMenu = gcnew AuthorsMenu();
		authorsMenu->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		/*BooksStorageMenu^ booksStorageMenu = gcnew BooksStorageMenu;
		booksStorageMenu->Show();*/
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		TicketsMenu^ ticketsMenu = gcnew TicketsMenu;
		ticketsMenu->Show();
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
	ReadersMenu^ readersMenu = gcnew ReadersMenu();
	readersMenu->Show();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	BooksStorageMenu^ booksStorageNenu = gcnew BooksStorageMenu();
	booksStorageNenu->Show();
}
};
}
