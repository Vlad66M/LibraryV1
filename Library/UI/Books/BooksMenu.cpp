#include "BooksMenu.h"

System::Void Library::BooksMenu::ClickOnFind(findByAthour_ findByAuthor, 
	findBook_ findBook, findBookById_ findBookById)
{
std::string name = msclr::interop::marshal_as<std::string>(textBox1->Text);
std::string isbn = msclr::interop::marshal_as<std::string>(textBox2->Text);
std::string tmpYear = msclr::interop::marshal_as<std::string>(textBox3->Text);
std::string author = msclr::interop::marshal_as<std::string>(textBox4->Text);
std::string tmpAuthorId = msclr::interop::marshal_as<std::string>(textBox7->Text);
std::string tmpBookId = msclr::interop::marshal_as<std::string>(textBox5->Text);

if (((name == "") && (isbn == "") && (author == "") && (tmpAuthorId == "") &&(tmpBookId==""))) {
	MessageBox::Show(this, "Попробуйте еще раз");
		return;
}
if ((tmpYear != "") && (!isNumeric_(tmpYear)) ||
	(tmpAuthorId != "") && (!isNumeric_(tmpAuthorId)) ||
	(tmpBookId != "") && (!isNumeric_(tmpBookId))) {
	MessageBox::Show(this, "Попробуйте еще раз");
		return;
}

int year = -1;
int authorId = -1;
int bookId = -1;
if ((tmpYear != "") && (isNumeric_(tmpYear))) {
	year = std::stoi(tmpYear);
}
if ((tmpAuthorId != "") && (isNumeric_(tmpAuthorId))) {
	authorId = std::stoi(tmpAuthorId);
}
if ((tmpBookId != "") && (isNumeric_(tmpBookId))) {
	bookId = std::stoi(tmpBookId);
}
std::vector<Model::BooksCollection::sh_book> search;

if ((author == "") && (authorId == -1)) {
	if ((name != "") || (isbn != "")) {
		search = (books->*findBook)(name, isbn, year, authorId);
		if (search.size() > 0) {
			if (bookId != -1) {
				for (size_t i = 0; i < search.size();i++) {
					if (search[i]->getId() != bookId) {
						search.erase(search.begin() + i);
					}
				}
			}
			if (search.size() > 0) {
				fillTable(search);
			}
			else {
				MessageBox::Show(this, "Книга не найдена");
			}
		}
		else {
			MessageBox::Show(this, "Книга не найдена");
		}
	}
}

if ((name == "") && (isbn == "") && (author == "") && (authorId == -1) && (bookId != -1)) {
	search = (books->*findBookById)(bookId);
	if (search.size() > 0) {
		fillTable(search);
	}
	else {
		MessageBox::Show(this, "Книга не найдена");
	}
}

if ((name == "") && (isbn == "")) {
	if ((author != "") || (authorId != -1)) {
		if (authorId != -1) {
			auto searchByAuthors = (books->*findByAuthor)({ authorId });
			std::vector<Model::BooksCollection::sh_book> result;
			if (author != "") {
				auto authorName = splitToWords(author);
				auto searchAuthors = authors->findAuthor(authorId, authorName);
				std::vector<int> authorsIds;
				for (auto el : searchAuthors) {
					authorsIds.push_back(el->getId());
				}
				auto searchByAuthors_ = (books->*findByAuthor)(authorsIds);
				for (auto el : searchByAuthors) {
					for (auto e : searchByAuthors_) {
						if (el->getAuthorId() == e->getAuthorId()) {
							result.push_back(el);
							break;
						}
					}
				}
				if (result.size() > 0) {
					if (bookId != -1) {
						for (size_t i = 0; i < result.size(); i++) {
							if (result[i]->getId() != bookId) {
								result.erase(result.begin() + i);
							}
						}
					}
					if (result.size() > 0) {
						fillTable(result);
					}
					else {
						MessageBox::Show(this, "Книга не найдена");
					}
				}
				else {
					MessageBox::Show(this, "Книга не найдена");
				}
			}
			if (searchByAuthors.size() > 0) {
				fillTable(searchByAuthors);
				//showButtons();
			}
			else {
				MessageBox::Show(this, "Книга не найдена");
			}
		}
		else {//search only by author's name
			std::vector<Model::BooksCollection::sh_book> result;
			auto authorName = splitToWords(author);
			auto searchAuthors = authors->findAuthor(authorName);
			std::vector<int> authorsIds;
			for (auto el : searchAuthors) {
				authorsIds.push_back(el->getId());
			}
			auto searchByAuthors = (books->*findByAuthor)(authorsIds);
			if (searchByAuthors.size() > 0) {
				if (bookId != -1) {
					for (size_t i = 0; i < result.size(); i++) {
						if (searchByAuthors[i]->getId() != bookId) {
							searchByAuthors.erase(result.begin() + i);
						}
					}
				}
				if (searchByAuthors.size() > 0) {
					fillTable(searchByAuthors);
				}
				else {
					MessageBox::Show(this, "Книга не найдена");
				}
			}
			else {
				MessageBox::Show(this, "Книга не найдена");
			}
		}
	}
}

if (((name != "") || (isbn != "")) &&
	((author != "") || (authorId != -1))) {
	search = (books->*findBook)(name, isbn, year, authorId);

	auto authorName = splitToWords(author);
	auto searchAuthors = authors->findAuthor(authorId, authorName);
	std::vector<int> authorsIds;
	for (auto el : searchAuthors) {
		authorsIds.push_back(el->getId());
	}
	auto searchByAuthors = (books->*findByAuthor)(authorsIds);

	std::vector<Model::BooksCollection::sh_book> result;
	if (searchByAuthors.size() == 0) {
		if (search.size() > 0) {
			fillTable(search);
			//showButtons();
		}
		else {
			MessageBox::Show(this, "Книга не найдена");
		}
	}
	else {
		for (auto el : search) {
			for (auto e : searchByAuthors) {
				if (el->getId() == e->getId() &&
					el->getName() == e->getName()&&
					el->getAuthorId() == e->getAuthorId()&&
					el->getYear() == e->getYear()&&
					el->getIsbn() == e->getIsbn()) {
					result.push_back(el);
					break;
				}
			}
		}
		if (bookId != -1) {
			for (size_t i = 0; i < result.size(); i++) {
				if (result[i]->getId() != bookId) {
					result.erase(result.begin() + i);
				}
			}
		}
		if (result.size() > 0) {
			fillTable(result);
			//showButtons();
		}
		else {
			MessageBox::Show(this, "Книга не найдена");
		}
	}
}
}

System::Void Library::BooksMenu::hide()
{
	dataGridView1->Hide();
	buttonChangeBookName->Hide();
	buttonChangeBookName->Enabled = false;
	buttonChangeIsbn->Hide();
	buttonChangeIsbn->Enabled = false;
	buttonChangeYear->Hide();
	buttonChangeYear->Enabled = false;
	buttonMakeAvailable->Hide();
	buttonMakeAvailable->Enabled = false;
	buttonDelete->Hide();
	buttonDelete->Enabled = false;
	buttonDeleteFromAvailable->Hide();
	buttonDeleteFromAvailable->Enabled = false;
}

System::Void Library::BooksMenu::showButtons()
{
	buttonChangeBookName->Enabled = true;
	buttonChangeBookName->Show();
	buttonChangeIsbn->Show();
	buttonChangeIsbn->Enabled = true;
	buttonChangeYear->Show();
	buttonChangeYear->Enabled = true;
	buttonMakeAvailable->Show();
	buttonMakeAvailable->Enabled = true;
	buttonDelete->Show();
	buttonDelete->Enabled = true;
	buttonDeleteFromAvailable->Show();
	buttonDeleteFromAvailable->Enabled = true;
}

System::Void Library::BooksMenu::fillTable(const std::vector<Model::sh_book> search)
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	dataGridView1->Show();
	for (int i = 0; i < search.size(); i++) {
		dataGridView1->Rows->Add();
		System::String^ Name = gcnew String(search[i]->getName().data());
		dataGridView1->Rows[i]->Cells[0]->Value = Name;
		dataGridView1->Rows[i]->Cells[1]->Value = search[i]->getId();
		//Find athor's name by Id
		System::String^ Author;
		std::vector<Model::AuthorsCollection::sh_author> booksAuthor = authors->findAuthor(search[i]->getAuthorId(), "", "", "");
		if (booksAuthor.size() == 0) {
			Author = "Id: " + System::Convert::ToString(search[i]->getAuthorId());
		}
		else {
			Author = gcnew String(((booksAuthor.back()->getSurname() + " " +
				booksAuthor.back()->getName() + " " +
				booksAuthor.back()->getPatronymic())).data());
		}
		System::String^ Isbn = gcnew String(search[i]->getIsbn().data());
		dataGridView1->Rows[i]->Cells[2]->Value = Isbn;
		dataGridView1->Rows[i]->Cells[3]->Value = Author;
		dataGridView1->Rows[i]->Cells[4]->Value = search[i]->getAuthorId();
		dataGridView1->Rows[i]->Cells[5]->Value = search[i]->getYear();
		dataGridView1->Rows[i]->Cells[6]->Value = false;

	}
}

//clear button
System::Void Library::BooksMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = L"";
	textBox2->Text = L"";
	textBox3->Text = L"";
	textBox4->Text = L"";
	textBox5->Text = L"";
	textBox7->Text = L"";
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	//hide();
}

//del from all button
System::Void Library::BooksMenu::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmBookDeleting^ cinfirmDeleting = gcnew ConfirmBookDeleting(BookName, Isbn);
		cinfirmDeleting->Show();
	}
}

//change ISBN button
System::Void Library::BooksMenu::button5_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeIsbn^ changeIsbn = gcnew ChangeIsbn(BookName, Isbn);
		changeIsbn->Show();
	}
}

//change year button
System::Void Library::BooksMenu::button3_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeYear^ changeYear = gcnew ChangeYear(BookName, Isbn);
		changeYear->Show();
	}
}

//del from available button
System::Void Library::BooksMenu::button_deleteFromAvailable_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ConfirmDeletingAvailable^ confirmDeleting = gcnew ConfirmDeletingAvailable(BookName, Isbn);
		confirmDeleting->Show();
	}
}

//make available button
System::Void Library::BooksMenu::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		std::string name = msclr::interop::marshal_as<std::string>(BookName->ToString());
		std::string isbn = msclr::interop::marshal_as<std::string>(Isbn->ToString());
		if (!books->isAvailable(name, isbn)) {
			books->makeAvailable(name, isbn);
			MessageBox::Show(this, "Изменения сохранены");
		}
		else {
			MessageBox::Show(this, "Книга уже является доступной");
		}
	}
}

//change name button
System::Void Library::BooksMenu::button3_Click_2(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeName^ changeName = gcnew ChangeName(BookName, Isbn);
		changeName->Show();
	}
}

//add book button
System::Void Library::BooksMenu::button3_Click_3(System::Object^ sender, System::EventArgs^ e)
{
	AddBook^ addBook = gcnew AddBook;
	addBook->Show();
}

//change author's Id button
System::Void Library::BooksMenu::button5_Click_2(System::Object^ sender, System::EventArgs^ e)
{
	clickAction();
	if (doAction) {
		ChangeBookAuthorsId^ changeBookAuthorsId = gcnew ChangeBookAuthorsId(BookName, Isbn);
		changeBookAuthorsId->Show();
	}
}

System::Void Library::BooksMenu::clickAction()
{
	doAction = false;
	bool checked;
	int checksCount = 0;
	for (int i = 0; i <= dataGridView1->Rows->Count - 1; i++) {
		checked = (bool)dataGridView1->Rows[i]->Cells[6]->FormattedValue;
		if (checked) {
			BookName = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
			Isbn = dataGridView1->Rows[i]->Cells[2]->Value->ToString();
			checksCount++;
			if (checksCount > 1) {
				MessageBox::Show(this, "Выберите одну книгу");
			}
		}
	}
	if (checksCount == 1) {
		doAction = true;
	}
	else if (checksCount == 0) {
		MessageBox::Show(this, "Книга не выбрана");
	}
}
