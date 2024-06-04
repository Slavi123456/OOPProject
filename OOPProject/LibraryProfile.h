#pragma once
//#include <iostream>
#include "Library.h"

class LibraryProfile: public Library {

public:	//void findBookInLibrary(const Book& book) const; //in Book operator ==/!=
	void findBookInLibrary(int uniqueNumber) const;
	void viewAllBooksInLibrary() const;
};