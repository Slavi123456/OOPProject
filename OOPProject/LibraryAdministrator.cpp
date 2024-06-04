#include "LibraryAdministrator.h"
#include <iostream>

void LibraryAdministrato::addBook()
{
	if (_bookListFilled + 1 > _bookListLenght)
	{
		std::cout << "Cannot add any more books";
		return;
	}
	std::cin >> _booksList[_bookListFilled];
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
	_bookListFilled++;
}

void LibraryAdministrato::addBook(const Book& newBook)
{
	if (_bookListFilled + 1 > _bookListLenght)
	{
		std::cout << "Cannot add any more books";
		return;
	}
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
	_bookListFilled++;
}

void LibraryAdministrato::addBook(Book&& newBook)
{
	if (_bookListFilled + 1 > _bookListLenght)
	{
		std::cout << "Cannot add any more books";
		return;
	}
	_booksList[_bookListFilled] = newBook;
	_booksList[_bookListFilled].SetUniqueLibraryNum(_bookListFilled);
	_bookListFilled++;
}

void LibraryAdministrato::removeBook(int uniqueNumber)
{
	//try-catch for the uniqueNumber
	_booksList[uniqueNumber].ClearBook();
	if (uniqueNumber < _bookListFilled)
	{
		for (size_t i = uniqueNumber; i < _bookListFilled - 1; i++)
		{
			_booksList[i] = _booksList[i + 1];
		}
	}
	_bookListFilled--;
}

void LibraryAdministrato::addUser()
{
	if (_accountsListFilled + 1 > _accountsListLenght)
	{
		std::cout << "Cannot add any more accounts";
		return;
	}
	_accountsListFilled++;
	std::cin >> _accountsList[_accountsListFilled];
}

void LibraryAdministrato::addUser(const Account& account)
{
	if (_accountsListFilled + 1 > _accountsListLenght)
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

	if (indexOfAccount < _accountsListFilled)
	{
		for (size_t i = indexOfAccount; i < _accountsListFilled - 1; i++)
		{
			_accountsList[i] = _accountsList[i + 1];
		}
	}
	_accountsListFilled--;
}
