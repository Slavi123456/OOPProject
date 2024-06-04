#pragma once
#include "Book.h"
#include "Account.h"

class Library // will be made inheritance for the type of profiles 
{			  // for the system of take and give shared list 
public: 
	//Big 6
	Library() = default;
	~Library();
	Library(const Library& other);
	Library(Library&& other);
	Library& operator=(const Library& other);
	Library& operator=(Library&& other);

	void sortAllBooks();
	void addBook();
	void addBook(const Book& newBook); //in Book copyContructor &/&&
	void addBook(Book&& newBook); //in Book copyContructor &/&&
	void removeBook(int uniqueNumber); //it needs sorting of pointers

	void addUser(const Account& account);
	void removeUser(const Account& account);
	//void findBookInLibrary(const Book& book) const; //in Book operator ==/!=
	void findBookInLibrary(int uniqueNumber) const;
	void viewAllBooksInLibrary() const;
protected:

private:
	//char* _libraryName;
	//int _libraryUniqueNumber; //later on for database of multiple libraries
	int _bookListLenght = 8;
	int _bookListFilled = -1;
	int _accountsListLenght = 8;
	int _accountsListFilled =-1;
						
	Book* _booksList = new Book[_bookListLenght]; //in the late game it will be bad to use it like that
												  //maybe in the book default i make the ptr with nullptr it wont be
	Account* _accountsList = new Account[_accountsListLenght]; //isn't better to have other class handling this 

	int powerOfTwo(int previousSize);
};

void findBook(const Library& library, const Book& book);
void viewAllBooks(const Library& library);


//books all
//books find
//books sort
//books view
//books add
//books remove
//users add
//users remove

