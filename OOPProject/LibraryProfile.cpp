#include "LibraryProfile.h"
#include <iostream>

void LibraryProfile::findBookInLibrary(int uniqueNumber) const
{
	//try-catch for the uniqueNumber
	outputDetailedBook(_booksList[uniqueNumber]);
}

void LibraryProfile::viewAllBooksInLibrary() const
{
	for (size_t i = 0; i < _bookListFilled; i++)
	{
		std::cout << _booksList[i];
	}
}
