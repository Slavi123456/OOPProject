#pragma once
#include "Book.h"
#include "Account.h"

class Library
{
public: 
	void sortAllBooks();
	void addBook(const Book& newBook);
	void removeBook(const Book& removedBook);

	void addUser(const Account& account);
	void removeUser(const Account& account);

private:
	char* _libraryName;
	int _libraryUniqueNumber;
	Book* booksList;
	Account* accountsList;
};

void listAllBooks(const Library& library);
void findBook(const Library& library);
void viewAllBooks(const Library& library);


//books all
//books find
//books sort
//books view
//books add
//books remove
//users add
//users remove

