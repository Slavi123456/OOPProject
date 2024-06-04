#include <iostream>
//#include "Library.h"
//#include "Book.h"
//#include "Account.h"
#include "ProgramManager.h"

void testCaseBook() {

	Book* books = new Book[3];
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
	
	books[2] = books[1];
	std::cout << "Is Book 1 same as Book 2: " << (books[2] == books[0]);

	outputDetailedBook(books[1]);
}
void testCaseAccount() {
	Account* accounts = new Account[3];
	std::cin >> accounts[0];

	std::cout << accounts[0];

	std::ofstream ofs("account.txt");
	if (ofs.is_open() == false)
	{
		return;
	}
	ofs << accounts[0];

	std::ifstream ifs("account.txt");
	if (ifs.is_open() == false)
	{
		return;
	}
	ifs >> accounts[1];

	ifs.close(); //unit tests ??

	ofs << accounts[1];
	ofs.close(); //unit tests ??

	accounts[2] = accounts[1];
	std::cout << "Is Account 1 same as Accounts 2: " << (accounts[2] == accounts[0]);

	std::cout << accounts[1] << std::endl;
	std::cout << "Account 2: " << std::endl;
	std::cout << accounts[2];
}
void testCaseLibraryForBook() {
	Library library;
	library.addBook();
	library.findBookInLibrary(0);

	library.addBook();

	library.viewAllBooksInLibrary();
	library.removeBook(1);

	library.viewAllBooksInLibrary();
}
void testCaseLibraryForAccount() {
	Library library;
	library.addUser();
	library.addUser();

	char userName [100];
	std::cout << "User Name to remove: ";
	std::cin.getline(userName, 99);
	library.removeUser(userName);

	//delete[]userName;
}
void testCaseProgramManager() {
	ProgramManager program;
	program.Open("library.txt");
	program.SetFilePath("library.txt");
	program.Save();
	program.SaveAs("library1.txt");
}

int main(){
	//testCaseLibraryForBook();
	//testCaseBook();
	//testCaseAccount();
	//testCaseLibraryForAccount();
	testCaseProgramManager();


	return 0;
}