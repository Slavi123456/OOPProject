#include <iostream>
#include "Library.h"

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

int main(){
	/*Library library;
	library.addBook();*/

	return 0;
}