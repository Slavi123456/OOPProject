#include "LibraryAdministrator.h"
#include <iostream>

void LibraryAdministrato::addBook()
{
	if (_bookListFilled + 1 > _bookListLenght) //later it needs to be fixed
	{
		std::cout << "Cannot add any more books";
		return;
	}
	_bookListFilled++;
	std::cin >> _booksList[_bookListFilled];
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
}

void LibraryAdministrato::addBook(const Book& newBook)
{
	if (_bookListFilled + 1 > _bookListLenght) //later it needs to be fixed
	{
		std::cout << "Cannot add any more books";
		return;
	}
	_bookListFilled++;
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
}

void LibraryAdministrato::addBook(Book&& newBook)
{
	if (_bookListFilled + 1 > _bookListLenght) //later it needs to be fixed
	{
		std::cout << "Cannot add any more books";
		return;
	}
	_bookListFilled++;
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
}

void LibraryAdministrato::removeBook(int uniqueNumber)
{
	//try-catch for the uniqueNumber
	_booksList[uniqueNumber].ClearBook();
	_bookListFilled--;
	
}

void LibraryAdministrato::addUser()
{
	if (_accountsListFilled + 1 > _accountsListLenght) //later it needs to be fixed
	{
		std::cout << "Cannot add any more accounts";
		return;
	}
	_accountsListFilled++;
	std::cin >> _accountsList[_accountsListFilled];
}

void LibraryAdministrato::addUser(const Account& account)
{
	if (_accountsListFilled + 1 > _accountsListLenght) //later it needs to be fixed
	{
		std::cout << "Cannot add any more accounts";
		return;
	}
	_accountsListFilled++;
	_accountsList[_accountsListFilled] = account;
}

void LibraryAdministrato::removeUser(const char* userName)
{
	int indexOfAccount = -1;
	for (size_t i = 0; i < _accountsListFilled; i++)
	{
		if (strcmp(_accountsList[i].GetUserName(), userName) == 0) indexOfAccount = i;

	}
	//throw for indx = - 1;
	_accountsList[indexOfAccount].ClearAccount();
}
