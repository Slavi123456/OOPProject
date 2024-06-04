#pragma once
//#include <iostream>
#include "Library.h"

class LibraryProfile: public Library {
	//void findBookInLibrary(const Book& book) const; //in Book operator ==/!=
	void findBookInLibrary(int uniqueNumber) const;
	void viewAllBooksInLibrary() const;
};