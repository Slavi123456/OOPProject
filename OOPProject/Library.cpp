#include "Library.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////
//BIG 6
Library::~Library()
{
	free();
}
Library::Library(const Library& other)
{
	copyFrom(other);
}
Library::Library(Library&& other)
{
	moveFrom(std::move(other));
}
Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Library& Library::operator=(Library&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Library::free()
{
	/*for (size_t i = 0; i < _bookListLenght; i++)
	{
		delete[]_booksList[i];
	}*/
	delete[]_booksList;

	delete[]_accountsList;
	_accountsList = nullptr;
}
void Library::moveFrom(Library&& other)
{
	_bookListFilled = other._bookListFilled;
	for (size_t i = 0; i < _bookListFilled; i++)
	{
		_booksList[i] = other._booksList[i];
	}

	_accountsListFilled = other._accountsListFilled;
	for (size_t i = 0; i < _accountsListFilled; i++)
	{
		_accountsList[i] = other._accountsList[i];
	}
}
void Library::copyFrom(const Library& other)
{
	_bookListFilled = other.getBookListFilled();
	Book* otherBookListPtr = other.getBookList();
	for (size_t i = 0; i < _bookListFilled; i++)
	{
		_booksList[i] = otherBookListPtr[i];
	}

	_accountsListFilled = other.getAccountListFilled();
	Account* otherAccountListPtr = other.getAccountList();
	for (size_t i = 0; i < _accountsListFilled; i++)
	{
		_accountsList[i] = otherAccountListPtr[i];
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//GET/ SET FUNCTIONS
void Library::setBookListFilled(int bookListFilled)
{
	_bookListFilled = bookListFilled;
}
void Library::setAccountListFilled(int accountListFilled)
{
	_accountsListFilled = accountListFilled;
}

int Library::getBookListFilled() const
{
	return _bookListFilled;
}
int Library::getAccountListFilled() const
{
	return _accountsListFilled;
}
Book* Library::getBookList() const
{
	return _booksList;
}
Account* Library::getAccountList() const
{
	return _accountsList;
}
///////////////////////////////////////////////////////////////////////////////////////
//OTHER FUNCTIONS

void saveLibrary(const Library& library, std::ofstream& ofs) {
	ofs << library.getBookListFilled() << " ";
	ofs << library.getAccountListFilled();

	std::ofstream ofsBooks("books.txt");
	if (ofsBooks.is_open() == false)
	{
		std::cerr << "Could't open books.txt";
		return;
	}
	Book* libraryBookListPtr = library.getBookList();
	int libraryBookListSize = library.getBookListFilled();
	for (size_t i = 0; i < libraryBookListSize; i++)
	{
		ofsBooks << libraryBookListPtr[i];
	}
	ofsBooks.close();

	std::ofstream ofsAccounts("accounts.txt");
	if (ofsAccounts.is_open() == false)
	{
		std::cerr << "Could't open accounts.txt";
		return;
	}
	Account* libraryAccountListPtr = library.getAccountList();
	int libraryAccountListSize = library.getAccountListFilled();
	for (size_t i = 0; i < libraryAccountListSize; i++)
	{
		ofsAccounts << libraryAccountListPtr[i];
	}
	ofsAccounts.close();
}
void loadLibrary(Library& library, std::ifstream& ifs)
{
	int helperVariable;
	ifs >> helperVariable;
	library.setBookListFilled(helperVariable);
	ifs >> helperVariable;
	library.setAccountListFilled(helperVariable);


	std::ifstream ifsBooks("books.txt");
	if (ifsBooks.is_open() == false)
	{
		std::cerr << "Could't open books.txt";
		return;
	}
	Book* libraryBookListPtr = library.getBookList();
	int libraryBookListSize = library.getBookListFilled();
	for (size_t i = 0; i < libraryBookListSize; i++)
	{
		ifsBooks >> libraryBookListPtr[i];
	}
	ifsBooks.close();

	std::ifstream ifsAccounts("accounts.txt");
	if (ifsAccounts.is_open() == false)
	{
		std::cerr << "Could't open accounts.txt";
		return;
	}
	Account* libraryAccountListPtr = library.getAccountList();
	int libraryAccountListSize = library.getAccountListFilled();
	for (size_t i = 0; i < libraryAccountListSize; i++)
	{
		ifsAccounts >> libraryAccountListPtr[i];
	}
	ifsAccounts.close();

}
