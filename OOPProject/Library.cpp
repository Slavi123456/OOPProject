#include "Library.h"
#include <iostream>

Library::Library()
{
	_bookListLenght = 8;
	_bookListFilled = 0;
	_accountsListLenght = 8;
	_accountsListFilled = 0;

	_booksList = new Book[_bookListLenght];
	_accountsList = new Account[_accountsListLenght];
}

Library::~Library()
{
	delete[]_booksList;
	_booksList = nullptr;

	delete[]_accountsList;
	_accountsList = nullptr;
}

void Library::addBook()
{
	//condition for _bookListFilled + 1 >= _bookListLenght so resize
	std::cin >> _booksList[_bookListFilled + 1];
}

void Library::findBookInLibrary(int uniqueNumber) const
{
	//try-catch for the uniqueNumber
	outputDetailedBook(_booksList[uniqueNumber]);
}

void Library::viewAllBooksInLibrary() const
{
	for (size_t i = 0; i < _bookListFilled; i++)
	{
		std::cout << _booksList[i];
	}
}
