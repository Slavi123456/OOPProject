#pragma once
#include "Book.h"
#include "Account.h"

class Library // will be made inheritance for the type of profiles 
{			  // for the system of take and give shared list 
public: 
	//Big 6
	Library();
	~Library();
	Library(const Library& other);
	Library(Library&& other);
	Library& operator=(const Library& other);
	Library& operator=(Library&& other);

	void sortAllBooks();
	void addBook();
	void addBook(const Book& newBook); //in Book copyContructor &/&&
	void removeBook(const Book& removedBook);

	void addUser(const Account& account);
	void removeUser(const Account& account);
	//void findBookInLibrary(const Book& book) const; //in Book operator ==/!=
	void findBookInLibrary(int uniqueNumber) const;
	void viewAllBooksInLibrary() const;
private:
	//char* _libraryName;
	//int _libraryUniqueNumber; //later on for database of multiple libraries
	int _bookListLenght;
	int _bookListFilled;
	int _accountsListLenght;
	int _accountsListFilled;
						
	Book* _booksList; //there could be static list for the copies of one book
					//because i have instance of the book does that mean i can use it's private functions//maybe
	Account* _accountsList; //isn't better to have other class handling this 

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

