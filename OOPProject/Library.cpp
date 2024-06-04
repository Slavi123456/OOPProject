#include "Library.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////
//BIG 6
Library::~Library()
{
	delete[]_booksList;
	_booksList = nullptr;

	delete[]_accountsList;
	_accountsList = nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////
//GET/ SET FUNCTIONS

///////////////////////////////////////////////////////////////////////////////////////
//OTHER FUNCTIONS
void Library::addBook()
{
	//condition for _bookListFilled + 1 >= _bookListLenght so resize
	_bookListFilled++;
	std::cin >> _booksList[_bookListFilled];
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);

}

void Library::addBook(const Book& newBook)
{
	_bookListFilled++;
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
}

void Library::addBook(Book&& newBook)
{
	_bookListFilled++;
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
}

void Library::removeBook(int uniqueNumber)
{
	//try-catch for the uniqueNumber
	//what does the delete operator does ///////////// does it calls the Destructor]
	_booksList[uniqueNumber].ClearBook();
	_bookListFilled--;
	//needs rearenging the pointers
}

void Library::findBookInLibrary(int uniqueNumber) const
{
	//try-catch for the uniqueNumber
	outputDetailedBook(_booksList[uniqueNumber]);
}

void Library::viewAllBooksInLibrary() const
{
	for (size_t i = 0; i < _bookListFilled+1; i++)
	{
		std::cout << _booksList[i];
	}
}
