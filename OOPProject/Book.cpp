#include "Book.h"
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////////////
//BIG SIX
Book::Book(const char* authorName, const char* bookName, int publishedYear, double rating, int uniqueLibraryNum) //Ganre ganre = Ganre::unknown)
{
	//try-catch for the lenght of the authorName and bookName
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName); //How to fix "strcpy" may be unsafe
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
	//_ganre = ganre;
	_uniqueLibraryNum = uniqueLibraryNum;
}

Book::~Book()
{
	delete[] _authorName;
	delete[] _bookName;
}
///////////////////////////////////////////////////////////////////////////////////////
//GET, SET FUNCTIONS
int Book::GetPublishedYear() const
{
	return _publishedYear;
}
int Book::GetUniqueLibraryNum() const
{
	return _uniqueLibraryNum;
}
double Book::GetRaing() const
{
	return _rating;
}
Ganre Book::GetBookGanre() const
{
	return _ganre;
}
const char* Book::GetAuthorName() const
{
	return _authorName;
}
const char* Book::GetBookName() const
{
	return _bookName;
}

void Book::SetRaiting(double raiting)
{
	_rating = raiting;
}
void Book::SetUniqueLibraryNum(int uniqueLibraryNum)
{
	_uniqueLibraryNum = uniqueLibraryNum;
}
void Book::SetPublishedYear(int publishedYear)
{
	_publishedYear = publishedYear;
}
void Book::SetBookGanre(Ganre ganre)
{
	_ganre = ganre;
}
void Book::SetAuthorName(const char* authorName)
{
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName);
}
void Book::SetBookName(const char* bookName)
{
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
}

///////////////////////////////////////////////////////////////////////////////////////
//OUTPUT/INPUT IN STREAMS
std::ostream& operator<<(std::ostream& os, const Book& book) 
{
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	os  << "Book information: " << std::endl; //does this fuckes the generitic things ?////////// 

	os << "Author name: " << book.GetBookName() << std::endl;
	os << "Book name: " << book.GetAuthorName() << std::endl;
	os << "Integer for the Ganre {1:unknown, 2:Horror, "
		<< "3:Romantic, 4:Phyhologic}: " << (int)book.GetBookGanre() << std::endl;
	os << "Library's unique number for the book: " << book.GetUniqueLibraryNum() << std::endl;
	
	std::cout << std::endl << std::endl;
	return os;
}
void outputDetailedBook(const Book& book)
{
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	std::cout << "Book detailed information: " << std::endl;

	std::cout << "Author name: " << book.GetBookName() << std::endl;
	std::cout << "Book name: " << book.GetAuthorName() << std::endl;
	std::cout << "Integer for the Ganre {1:unknown, 2:Horror, "
			  << "3:Romantic, 4:Phyhologic}: " << (int)book.GetBookGanre() << std::endl;
	std::cout << "Published year: " << book.GetPublishedYear() << std::endl;
	std::cout << "Book's rating: " << book.GetRaing() << std::endl;
	std::cout << "Library's unique number for the book: " << book.GetUniqueLibraryNum() << std::endl;

	std::cout << std::endl << std::endl;
}
std::ofstream& operator<<(std::ofstream& os, const Book& book) 
{
	//maybe some Jayson inspired saving 
	os << book.GetAuthorName() << std::endl;
	os << book.GetBookName() << std::endl;
	os << (int)book.GetBookGanre() << " ";
	os << book.GetPublishedYear() << " ";
	os << book.GetRaing() << " ";
	os << book.GetUniqueLibraryNum();

	os << std::endl;
	return os;
}


//that's friendly to have acces to the SetFunctions
std::istream& operator>>(std::istream& is, Book& book) //maybe switch std::cout to is //////////
{
	//try-catch for the size of the AuthorName, BookName
	//there could be problem with multiple book creation
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	char buffer[1024];
	std::cout << "Author name: ";
	is >> buffer;
	
	strcpy_s((char *)book.GetAuthorName(), CHAR_ARRAY_SIZE, buffer);

	//because book name is const char*, i casted it for (char *)
	std::cout << "Book name: ";
	is >> buffer;
	strcpy_s((char *)book.GetBookName(), CHAR_ARRAY_SIZE, buffer);

	int helperVariable;
	std::cout << "Integer for the Ganre {1:unknown, 2:Horror, 3:Romantic, 4:Phyhologic}: ";
	is >> helperVariable;
	book.SetBookGanre((Ganre)helperVariable);
	
	std::cout << "Published year: ";
	is >> helperVariable;
	book.SetPublishedYear(helperVariable);
	
	double helperVariableDouble;
	std::cout << "Book's rating: ";
	is >> helperVariableDouble;
	book.SetRaiting(helperVariableDouble);

	std::cout << "Library Unique number: "; //isn't better to be only in the contructor 
	is >> helperVariable;
	book.SetUniqueLibraryNum(helperVariable);

	std::cout << std::endl << std::endl;

	return is;
}
std::ifstream& operator>>(std::ifstream& ifs, Book& book) {
	//try-catch for the size of the AuthorName, BookName
	char buffer[1024];
	ifs >> buffer;
		
	strcpy_s((char*)book.GetAuthorName(), CHAR_ARRAY_SIZE, buffer);

	//because book name is const char*, i casted it for (char *)
	ifs >> buffer;
	strcpy_s((char*)book.GetBookName(),CHAR_ARRAY_SIZE, buffer);

	int helperVariable;
	ifs >> helperVariable;
	book.SetBookGanre((Ganre)helperVariable);

	ifs >> helperVariable;
	book.SetPublishedYear(helperVariable);

	double helperVariableDouble;
	ifs >> helperVariableDouble;
	book.SetRaiting(helperVariableDouble);

	ifs >> helperVariable;
	book.SetUniqueLibraryNum(helperVariable);
	
	return ifs;
}
///////////////////////////////////////////////////////////////////////////////////////