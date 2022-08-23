#include "Library.h"
#include <Windows.h>

using namespace Library; // Название проекта


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	/*for (int i = 0; i < 100; i++) {
		std::string name = "book";
		name = name + std::to_string(i);
		books->addBook(0, i, 1000 + i, name , "1");
	}*/

	books->recieveBooks();
	books->recieveAvailableIds();
	authors->recieveAuthors();
	bookRecords->recieveRecords();
	tickets->recieveTickets();
	readers->recieveReaders();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LibraryMenu);



	return 0;
}