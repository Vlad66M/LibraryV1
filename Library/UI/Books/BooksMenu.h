#pragma once
#include "../../Model/BooksCollection.h"
#include"../../Model/AuthorsCollection.h"
#include <msclr\marshal_cppstd.h>
#include"../../Model/Global.h"
#include"../../Model/SplitToWords.h"
#include "../../View/View.h"
#include "ChangeName.h"
#include "ConfirmBookDeleting.h"
#include"ChangeIsbn.h"
#include"ChangeYear.h"
#include"ConfirmDeletingAvailable.h"
#include"AddBook.h"
#include"ChangeBookAuthorsId.h"



namespace Library {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Find
	/// </summary>
	public ref class BooksMenu : public System::Windows::Forms::Form
	{
	public:
		BooksMenu(void)
		{
			InitializeComponent();
			//hide();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BooksMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox3;


	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::DataGridView^ dataGridView1;







	private: System::Windows::Forms::Button^ buttonDelete;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::String^ BookName;
		System::String^ Isbn;
	private: System::Windows::Forms::Button^ buttonChangeIsbn;
	private: System::Windows::Forms::Button^ buttonChangeYear;
	private: System::Windows::Forms::Button^ buttonDeleteFromAvailable;



	private: System::Windows::Forms::Button^ buttonMakeAvailable;
	private: System::Windows::Forms::Button^ buttonChangeBookName;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label4;






	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Column4;
	private: System::Windows::Forms::Button^ button5;























		   bool doAction;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonChangeIsbn = (gcnew System::Windows::Forms::Button());
			this->buttonChangeYear = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteFromAvailable = (gcnew System::Windows::Forms::Button());
			this->buttonMakeAvailable = (gcnew System::Windows::Forms::Button());
			this->buttonChangeBookName = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(139, 335);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(296, 65);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Искать по всем зарегистрированным книгам";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BooksMenu::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(161, 78);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(296, 27);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(45, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Название:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(82, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"ISBN:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(161, 38);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(296, 27);
			this->textBox1->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(11, 255);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Год издания:";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(139, 488);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 48);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BooksMenu::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(161, 253);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(296, 27);
			this->textBox3->TabIndex = 12;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(139, 404);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(296, 66);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Искать только по доступным в библиотеке";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &BooksMenu::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(161, 118);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(296, 27);
			this->textBox4->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(71, 117);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 25);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Автор:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(43, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(103, 25);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Id автора:";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(161, 209);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(296, 27);
			this->textBox7->TabIndex = 24;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->name, this->Column5,
					this->Column1, this->Column2, this->Column6, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(470, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1025, 258);
			this->dataGridView1->TabIndex = 25;
			// 
			// name
			// 
			this->name->HeaderText = L"Название";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 200;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Id книги";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 60;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ISBN";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Автор";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 200;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Id автора";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 60;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Год издания";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 50;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 20;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(1072, 336);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(118, 89);
			this->buttonDelete->TabIndex = 28;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &BooksMenu::button6_Click);
			// 
			// buttonChangeIsbn
			// 
			this->buttonChangeIsbn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonChangeIsbn->Location = System::Drawing::Point(621, 335);
			this->buttonChangeIsbn->Name = L"buttonChangeIsbn";
			this->buttonChangeIsbn->Size = System::Drawing::Size(129, 89);
			this->buttonChangeIsbn->TabIndex = 29;
			this->buttonChangeIsbn->Text = L"Изменить ISBN";
			this->buttonChangeIsbn->UseVisualStyleBackColor = true;
			this->buttonChangeIsbn->Click += gcnew System::EventHandler(this, &BooksMenu::button5_Click_1);
			// 
			// buttonChangeYear
			// 
			this->buttonChangeYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonChangeYear->Location = System::Drawing::Point(767, 335);
			this->buttonChangeYear->Name = L"buttonChangeYear";
			this->buttonChangeYear->Size = System::Drawing::Size(136, 89);
			this->buttonChangeYear->TabIndex = 30;
			this->buttonChangeYear->Text = L"Изменить год издания";
			this->buttonChangeYear->UseVisualStyleBackColor = true;
			this->buttonChangeYear->Click += gcnew System::EventHandler(this, &BooksMenu::button3_Click_1);
			// 
			// buttonDeleteFromAvailable
			// 
			this->buttonDeleteFromAvailable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonDeleteFromAvailable->Location = System::Drawing::Point(1206, 335);
			this->buttonDeleteFromAvailable->Name = L"buttonDeleteFromAvailable";
			this->buttonDeleteFromAvailable->Size = System::Drawing::Size(130, 89);
			this->buttonDeleteFromAvailable->TabIndex = 31;
			this->buttonDeleteFromAvailable->Text = L"Удалить только из доступных";
			this->buttonDeleteFromAvailable->UseVisualStyleBackColor = true;
			this->buttonDeleteFromAvailable->Click += gcnew System::EventHandler(this, &BooksMenu::button_deleteFromAvailable_Click);
			// 
			// buttonMakeAvailable
			// 
			this->buttonMakeAvailable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonMakeAvailable->Location = System::Drawing::Point(919, 335);
			this->buttonMakeAvailable->Name = L"buttonMakeAvailable";
			this->buttonMakeAvailable->Size = System::Drawing::Size(137, 89);
			this->buttonMakeAvailable->TabIndex = 32;
			this->buttonMakeAvailable->Text = L"Отметить книгу как доступную";
			this->buttonMakeAvailable->UseVisualStyleBackColor = true;
			this->buttonMakeAvailable->Click += gcnew System::EventHandler(this, &BooksMenu::button7_Click);
			// 
			// buttonChangeBookName
			// 
			this->buttonChangeBookName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonChangeBookName->Location = System::Drawing::Point(470, 335);
			this->buttonChangeBookName->Name = L"buttonChangeBookName";
			this->buttonChangeBookName->Size = System::Drawing::Size(136, 90);
			this->buttonChangeBookName->TabIndex = 33;
			this->buttonChangeBookName->Text = L"Изменить название";
			this->buttonChangeBookName->UseVisualStyleBackColor = true;
			this->buttonChangeBookName->Click += gcnew System::EventHandler(this, &BooksMenu::button3_Click_2);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(470, 448);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(312, 88);
			this->button3->TabIndex = 34;
			this->button3->Text = L"Добавить новую книгу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &BooksMenu::button3_Click_3);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(259, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 25);
			this->label4->TabIndex = 35;
			this->label4->Text = L"Поиск:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(56, 169);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 25);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Id книги:";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(161, 170);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(296, 27);
			this->textBox5->TabIndex = 37;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1359, 335);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(136, 88);
			this->button5->TabIndex = 38;
			this->button5->Text = L"Изменить Id автора";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &BooksMenu::button5_Click_2);
			// 
			// BooksMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 656);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->buttonChangeBookName);
			this->Controls->Add(this->buttonMakeAvailable);
			this->Controls->Add(this->buttonDeleteFromAvailable);
			this->Controls->Add(this->buttonChangeYear);
			this->Controls->Add(this->buttonChangeIsbn);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"BooksMenu";
			this->Text = L"Книги";
			this->Click += gcnew System::EventHandler(this, &BooksMenu::button5_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/*std::vector<std::string> splitToWords(const std::string& str);*/

	typedef std::vector<Model::BooksCollection::sh_book>(Model::BooksCollection::* findByAthour_)(const std::vector<int>)const;
	typedef std::vector<Model::BooksCollection::sh_book>(Model::BooksCollection::* findBook_)(const std::string, const std::string, 
		const int, const int)const;
	typedef std::vector<Model::BooksCollection::sh_book>(Model::BooksCollection::* findBookById_)(const int)const;
	private: System::Void ClickOnFind(findByAthour_ findByAuthor, findBook_ findBook, 
		findBookById_ findBookById);
	private: System::Void clickAction();
	private: System::Void hide();

	private: System::Void showButtons();


	private: System::Void fillTable(const std::vector<Model::BooksCollection::sh_book> search);

		   //search in all books button
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ClickOnFind(&Model::BooksCollection::findByAuthorAll, &Model::BooksCollection::findInAll, &Model::BooksCollection::findByIdAll);
	}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	   //clear button
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

	   //search in available books button
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	ClickOnFind(&Model::BooksCollection::findByAuthorAvailable, &Model::BooksCollection::findInAvailable, &Model::BooksCollection::findByIdAvailable);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	/*std::vector<Model::BooksCollection::sh_book> search_;
	fillTable(search_);*/
}

//deleted button
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //delete from all button
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);

	   //change ISBN button
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e);

	   //change year button
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e);

	   //delete from available button
private: System::Void button_deleteFromAvailable_Click(System::Object^ sender, System::EventArgs^ e);

	   //make available button
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void buttonChangeName_Click(System::Object^ sender, System::EventArgs^ e) {
	/*clickAction();
	if (doAction) {
		ChangeName^ changeName = gcnew ChangeName(BookName, Isbn);
		changeName->Show();
	}*/
}
	   //change name button
private: System::Void button3_Click_2(System::Object^ sender, System::EventArgs^ e);

	   //add book button
private: System::Void button3_Click_3(System::Object^ sender, System::EventArgs^ e);

	   //change author's Id button
private: System::Void button5_Click_2(System::Object^ sender, System::EventArgs^ e);
};
}
