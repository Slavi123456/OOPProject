#include <iostream>
#include "Library.h"
#include "Book.h"

//INPUT/OUTPUT TEST //Wants #include "Book.h"//
void testCaseBook() {

	Book* books = new Book[2];
	std::cin >> books[0];

	std::cout << books[0];
	
	std::ofstream ofs("library.txt");
	if (ofs.is_open() == false)
	{
		return;
	}
	ofs << books[0];

	std::ifstream ifs("library.txt");
	if (ifs.is_open() == false)
	{
		return;
	}
	ifs >> books[1];

	ifs.close(); //unit tests ??

	ofs << books[1];
	ofs.close(); //unit tests ??

	outputDetailedBook(books[1]);
}
//ADD/FIND/OUTPUT ALL 
void testCaseLibrary() {
	Library library;
	library.addBook();
	library.findBookInLibrary(0);

	library.addBook();

	library.viewAllBooksInLibrary();
}
//REMOVE
void testCaseLibraryRemove() {
	Library library;
	library.addBook();

	library.addBook();
	library.viewAllBooksInLibrary();
	library.removeBook(1);

	library.viewAllBooksInLibrary();
}
int main(){
	//testCaseLibraryRemove();
	testCaseBook();
	
	
	return 0;
}