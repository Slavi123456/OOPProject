#include "Book.h"

Book::Book(const char* authorName, const char* bookName, int publishedYear, double rating, Ganre ganre = Ganre::unknown) {
	//try-catch for the lenght of the authorName and bookName
	strcpy(_authorName, authorName);
	strcpy(_bookName, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
	_ganre = ganre;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.GetAuthorName();
	os << book.GetBookName();
	os << (int)book.GetBookGanre();
	os << book.GetPublishedYear();
	os << book.GetRaing();
	os << book.GetUniqueLibraryNum();
}
//that's friendly to have acces to the SetFunctions
std::istream& operator>>(std::istream& is, Book& book)
{
	//try-catch for the size of the AuthorName, BookName
	char buffer[1024];
	is >> buff
	is >> book.GetBookName();

	int helperVariable;
	is >> helperVariable;
	book.SetBookGanre((Ganre)helperVariable);
	
	is >> helperVariable;
	book.SetPublishedYear(helperVariable);
	
	double helperVariableDouble;
	is >> helperVariableDouble;
	book.SetPublishedYear(helperVariableDouble);

	is >> helperVariable;
	book.SetUniqueLibraryNum(helperVariable);

}
