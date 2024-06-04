#include "Book.h"
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////////////
//BIG SIX
Book::Book(const char* authorName, const char* bookName,const char* description, int sizeDescription, const char** keywords, int countKeyWords , int publishedYear, double rating, Ganre ganre)
{
	//try-catch for the lenght of the authorName and bookName
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName); //How to fix "strcpy" may be unsafe //because writing in vs studio
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
	_ganre = ganre;

	_sizeDescription = sizeDescription + 1;
	_description = new char[_sizeDescription];
	strcpy_s(_description, _sizeDescription, description);

	_countKeyWords = countKeyWords;
	_keyWords = new char* [_countKeyWords];
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		_keyWords[i] = new char[strlen(keywords[i]) + 1];
		strcpy_s(_keyWords[i], strlen(keywords[i]) + 1, keywords[i]);
	}
	//add keywords
}
Book::Book(const Book& other)
{
	copyFrom(other);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Book& Book::operator=(Book&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Book::Book(Book&& other)
{
	moveFrom(std::move(other));
}
Book::~Book()
{
	//you can delete only pointers
	//delete[] _authorName;
	//delete[] _bookName;
	free();
}

void Book::free()
{
	delete[]_description;
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		delete[]_keyWords[i];
	}
	delete[]_keyWords;
}
void Book::moveFrom(Book&& other)
{
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, other._authorName); 
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, other._bookName);
	_publishedYear = other._publishedYear;
	_rating = other._rating;
	_ganre = other._ganre;
	_sizeDescription = other._sizeDescription;

	_description = new char[other._sizeDescription];
	strcpy_s(_description, _sizeDescription, other._description);

	_countKeyWords = other._countKeyWords;
	_keyWords = new char* [_countKeyWords];
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		_keyWords[i] = new char[strlen(other._keyWords[i]) + 1];
		strcpy_s(_keyWords[i], strlen(other._keyWords[i]) + 1, other._keyWords[i]);
	}
}
void Book::copyFrom(const Book& other)
{
	//if i start calling Set functions for all of them the callstack will be bigger so this is faster//I think
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, other.GetAuthorName()); 
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, other.GetBookName());
	_publishedYear = other.GetPublishedYear();
	_rating = other.GetRaing();
	_ganre = other.GetBookGanre();
	_sizeDescription = other.GetSizeDescription() + 1;

	_description = new char[_sizeDescription];
	strcpy_s(_description, _sizeDescription, other._description);

	_countKeyWords = other.GetCountKeyWords();
	_keyWords = new char* [_countKeyWords];
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		_keyWords[i] = new char[strlen(other.GetKeyWords()[i]) + 1];
		strcpy_s(_keyWords[i], strlen(other.GetKeyWords()[i]) + 1, other.GetKeyWords()[i]);
	}
}
void Book::resizeForDescription(int sizeDescription)
{
	char* newDescription = new char[sizeDescription + 1]; 
	
	_sizeDescription = sizeDescription + 1;//more general function for copying because SetDescription it's same
	newDescription = new char[_sizeDescription]; 
	strcpy_s(_description, _sizeDescription, newDescription);

	delete[]_description;
	_description = newDescription;

	delete[]newDescription;
}
void Book::resizeForKeyWords(int countKeyWords)
{
	char** newKeyWords = new char* [countKeyWords];
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		int keyWordLen = strlen(_keyWords[i]) + 1;
		newKeyWords[i] = new char[keyWordLen];//do i need to check every word lenght of the incoming **
		strcpy_s(newKeyWords[i], keyWordLen, _keyWords[i]);
	}

	for (size_t i = 0; i < _countKeyWords; i++)
	{
		delete[]_keyWords[i];
	}
	delete[]_keyWords;
	_keyWords = newKeyWords;
	_countKeyWords = countKeyWords;
	for (size_t i = 0; i < countKeyWords; i++)
	{
		delete[]newKeyWords[i];
	}
	delete[]newKeyWords;
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
int Book::GetSizeDescription() const
{
	return _sizeDescription;
}
int Book::GetCountKeyWords() const
{
	return _countKeyWords;
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

char* Book::GetDescription() const
{
	return _description;
}
char** Book::GetKeyWords() const
{
	return _keyWords;
}


//why doesn't work with default paramaters ///
//why doesn't work with default paramaters /// because default parameters are only in the header file 
void Book::InitializeBook(const char* authorName, const char* bookName, int publishedYear, double rating) // int uniqueLibraryNum = 0, Ganre ganre = Ganre::unknown)
{
	//try-catch for the lenght of the authorName and bookName
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName); //How to fix "strcpy" may be unsafe ///
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
}
void Book::InitializeBook(const char* authorName, const char* bookName, int publishedYear, double rating, int uniqueLibraryNum)
{
	//try-catch for the lenght of the authorName and bookName
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName); 
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
	_uniqueLibraryNum = uniqueLibraryNum;
}
>>>>>>> a29b9e99ec954c5935ebc424a776f3f53826fa20
void Book::InitializeBook(const char* authorName, const char* bookName, int publishedYear, double rating, int uniqueLibraryNum, Ganre ganre)
{
	//try-catch for the lenght of the authorName and bookName
	strcpy_s(_authorName, CHAR_ARRAY_SIZE, authorName);
	strcpy_s(_bookName, CHAR_ARRAY_SIZE, bookName);
	_publishedYear = publishedYear;
	_rating = rating;
	_uniqueLibraryNum = uniqueLibraryNum;
	_ganre = ganre;
}
void Book::ClearBook()
{
	delete[]this;
	//strcpy_s(_authorName, 1, "");
	//strcpy_s(_bookName, 1, "");
	//
	////char** _description;
	////char** _keyWords;
	//_ganre = Ganre::undefined;
	//_publishedYear = 0;
	//_uniqueLibraryNum = 0;
	//_rating = 0.0;
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

void Book::SetDescription(const char* description,int sizeDescription)
{
	_sizeDescription = sizeDescription + 1;

	_description = new char[_sizeDescription];
	strcpy_s(_description, _sizeDescription, description);
}
void Book::SetKeyWords(char** keywords, int countKeyWords)
{
	_countKeyWords = countKeyWords;
	_keyWords = new char* [_countKeyWords];
	for (size_t i = 0; i < _countKeyWords; i++)
	{
		_keyWords[i] = new char[strlen(keywords[i]) + 1];
		strcpy_s(_keyWords[i], strlen(keywords[i]) + 1, keywords[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//OUTPUT/INPUT IN STREAMS
std::ostream& operator<<(std::ostream& os, const Book& book) 
{
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	os  << "Book information: " << std::endl; //does this fuckes the generitic things ?////////// 

	os << "Author name: " << book.GetAuthorName() << std::endl;
	os << "Book name: " << book.GetBookName() << std::endl;
	os << "Integer for the Ganre {1:unknown, 2:Horror, "
		<< "3:Romantic, 4:Phyhologic}: " << (int)book.GetBookGanre() << std::endl;
	os << "Library's unique number for the book: " << book.GetUniqueLibraryNum() << std::endl;
	
	std::cout << std::endl << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	return os;
}
void outputDetailedBook(const Book& book)
{
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	std::cout << std::endl << "*****************************************" << std::endl;
	std::cout << "Book detailed information: " << std::endl;

	std::cout << "Author name: " << book.GetAuthorName() << std::endl;
	std::cout << "Book name: " << book.GetBookName() << std::endl;
	std::cout << "Integer for the Ganre {1:unknown, 2:Horror, "
			  << "3:Romantic, 4:Phyhologic}: " << (int)book.GetBookGanre() << std::endl;
	std::cout << "Published year: " << book.GetPublishedYear() << std::endl;
	std::cout << "Book's rating: " << book.GetRaing() << std::endl;
	std::cout << "Library's unique number for the book: " << book.GetUniqueLibraryNum() << std::endl;
	
	std::cout << "Books description: " << book.GetDescription() << std::endl;
	std::cout << "Books keywords: ";
	char** keyWordsptr = book.GetKeyWords();
	for (size_t i = 0; i < book.GetCountKeyWords(); i++)
	{
		std::cout << book.GetKeyWords()[i] << " ";
	}
	keyWordsptr = nullptr;//does it need to be somethin bigger like a loop

	std::cout << std::endl << "*****************************************" << std::endl;
}
std::ofstream& operator<<(std::ofstream& os, const Book& book) 
{
	//maybe some Jayson inspired saving 
	os << book.GetAuthorName() << std::endl;
	os << book.GetBookName() << std::endl;
	os << (int)book.GetBookGanre() << " ";
	os << book.GetPublishedYear() << " ";
	os << book.GetRaing() << " ";
	os << book.GetUniqueLibraryNum() << std::endl;

	os << book.GetSizeDescription() << " " << book.GetDescription() << std::endl;
	os << book.GetCountKeyWords() << " ";

	char** keyWordsptr = book.GetKeyWords();
	for (size_t i = 0; i < book.GetCountKeyWords(); i++)
	{
		os << book.GetKeyWords()[i] << " ";
	}
	keyWordsptr = nullptr;

	os << std::endl;
	return os;
}

//that's friendly to have acces to the SetFunctions
std::istream& operator>>(std::istream& is, Book& book) //maybe switch std::cout to is ////////// more generelized
{
	//try-catch for the size of the AuthorName, BookName
	//there could be problem with multiple book creation with getline

	std::cout << std::endl << "-----------------------------------------" << std::endl;
	char buffer[1024];
	std::cout << "Author name: ";
	//is >> buffer;
	is.getline(buffer, 200); 
	strcpy_s((char *)book.GetAuthorName(), CHAR_ARRAY_SIZE, buffer);

	//because book name is const char*, i casted it for (char *)
	std::cout << "Book name: ";
	//is >> buffer;
	is.getline(buffer, 200);
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

	is.ignore();

	//library sets that unique number
	//std::cout << "Library Unique number: "; //isn't better to be only in the contructor 
	//is >> helperVariable;
	//book.SetUniqueLibraryNum(helperVariable);

	std::cout << "Book's description: ";
	is.getline(buffer, 1024);
	book.SetDescription(buffer, strlen(buffer));
	
	std::cout << "Book's keywords count: ";
	is >> helperVariable;
	is.ignore();

	char** keyWordsPtr = new char* [helperVariable];//can it evadated this new ///
	std::cout << "Book's keywords (with " "): ";
	is.getline(buffer, 1024);
	//function to split the buffer in spaces
	keyWordsPtr = split(buffer, helperVariable);
	book.SetKeyWords(keyWordsPtr, helperVariable);
	
	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < helperVariable; i++)
	{
		delete[]keyWordsPtr[i];
	}
	delete[]keyWordsPtr;

	return is;
}
std::ifstream& operator>>(std::ifstream& ifs, Book& book) {
	//try-catch for the size of the AuthorName, BookName
	char buffer[1024];
	//ifs >> buffer;
	ifs.getline(buffer, 200);
	strcpy_s((char*)book.GetAuthorName(), CHAR_ARRAY_SIZE, buffer);

	//because book name is const char*, i casted it for (char *)
	//ifs >> buffer;
	ifs.getline(buffer, 200);
	strcpy_s((char*)book.GetBookName(),CHAR_ARRAY_SIZE, buffer);

	int helperVariable;
	ifs >> helperVariable;
	book.SetBookGanre((Ganre)helperVariable);

	ifs >> helperVariable;
	book.SetPublishedYear(helperVariable);

	double helperVariableDouble;
	ifs >> helperVariableDouble;
	book.SetRaiting(helperVariableDouble);

	//library sets that unique number
	ifs >> helperVariable;
	book.SetUniqueLibraryNum(helperVariable);
	
	ifs >> helperVariable;
	ifs.ignore();

	ifs.getline(buffer, 1024);
	book.SetDescription(buffer, strlen(buffer));

	ifs >> helperVariable;
	ifs.ignore();

	char** keyWordsPtr = new char* [helperVariable];
	for (size_t i = 0; i < helperVariable; i++)
	{
		ifs >> buffer;
		keyWordsPtr[i] = new char[strlen(buffer) + 1];
		strcpy_s(keyWordsPtr[i], strlen(buffer) + 1, buffer);
	}
	book.SetKeyWords(keyWordsPtr, helperVariable);

	for (size_t i = 0; i < helperVariable; i++)
	{
		delete[]keyWordsPtr[i];
	}
	delete[]keyWordsPtr;
	return ifs;
}
///////////////////////////////////////////////////////////////////////////////////////


bool operator==(const Book& lhs, const Book& rhs)
{
	bool isSame = lhs.GetBookGanre() == rhs.GetBookGanre()
		&& lhs.GetPublishedYear() == rhs.GetPublishedYear()
		&& lhs.GetUniqueLibraryNum() == rhs.GetUniqueLibraryNum()
		&& lhs.GetRaing() == rhs.GetRaing();
	if (isSame == false)
	{
		return false;
	}
	isSame = strcmp(lhs.GetAuthorName(), rhs.GetAuthorName()) == 0
		&& strcmp(lhs.GetBookName(), rhs.GetBookName()) == 0
		&& strcmp(lhs.GetDescription(), rhs.GetDescription()) == 0;
	if (isSame == false)
	{
		return false;
	}
	isSame = lhs.GetCountKeyWords() == rhs.GetCountKeyWords();
	if (isSame == false)
	{
		return false;
	}
	char** lhsKeyWords = lhs.GetKeyWords();
	char** rhsKeyWords = rhs.GetKeyWords();
	for (size_t i = 0; i < lhs.GetCountKeyWords(); i++)
	{
		isSame = strcmp(lhsKeyWords[i], rhsKeyWords[i]) == 0;
		if (isSame == false)
		{
			return false;
		}
	}
	return isSame;
}
bool operator!=(const Book& lhs, const Book& rhs)
{
	return !(lhs == rhs);
}

char** split(const char* str, int count) {
	// Êîïèðàíå íà îðèãèíàëíèÿ íèç, çà äà íå ãî ìîäèôèöèðàìå äèðåêòíî
	char* strCopy = new char[strlen(str) + 1];
	strcpy_s(strCopy, strlen(str) + 1, str);

	// Ïðåáðîÿâàíå íà äóìèòå
	count = 0;
	char* context = nullptr;
	char* token = strtok_s(strCopy, " ", &context);
	while (token) {
		count++;
		token = strtok_s(nullptr, " ", &context);
	}

	// Ñúçäàâàíå íà ìàñèâ îò óêàçàòåëè êúì íèçîâå
	char** result = new char* [count];

	// Êîïèðàíå íà îðèãèíàëíèÿ íèç îòíîâî, çà äà ãî èçïîëçâàìå ñ strtok_s
	strcpy_s(strCopy, strlen(str) + 1, str);
	int index = 0;
	token = strtok_s(strCopy, " ", &context);
	while (token) {
		result[index] = new char[strlen(token) + 1];
		strcpy_s(result[index], strlen(token) + 1, token);
		index++;
		token = strtok_s(nullptr, " ", &context);
	}

	delete[] strCopy; // Îñâîáîæäàâàíå íà âðåìåííî êîïèå

	return result;
}
