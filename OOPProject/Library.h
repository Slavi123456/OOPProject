#pragma once
#include "Book.h"
#include "Account.h"

class Library 
{			  
public: 
	Library() = default;
	~Library();
	Library(const Library& other);
	Library(Library&& other);
	Library& operator=(const Library& other);
	Library& operator=(Library&& other);

	void setBookListFilled(int bookListFilled);
	void setAccountListFilled(int accountListFilled);

	int getBookListFilled() const;
	int getAccountListFilled() const;
	Book* getBookList() const;
	Account* getAccountList() const;
	
protected:

	//char* _libraryName;
	//int _libraryUniqueNumber; //later on for database of multiple libraries
	int _bookListLenght = 8;
	int _bookListFilled = 0;
	int _accountsListLenght = 8;
	int _accountsListFilled = 0;
						
	Book* _booksList = new Book[_bookListLenght]; 												  
	Account* _accountsList = new Account[_accountsListLenght];

	void free();
	void moveFrom(Library&& other);
	void copyFrom(const Library& other);

	//int powerOfTwo(int previousSize);
};

void saveLibrary(const Library& library, std::ofstream& ofs);
void loadLibrary(Library& library, std::ifstream& ifs);