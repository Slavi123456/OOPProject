#pragma once
#include <fstream>

constexpr int CHAR_ARRAY_SIZE = 200;

///////////////////////////////////////////////////////////////////////////////////////
//ENUMS AND STRUCTS
enum class Ganre {
	undefined, 
	unknown,
	Horror,
	Romatic,
	Psyhologic
};

///////////////////////////////////////////////////////////////////////////////////////
//CLASSES
class Book {
public:
	//big Six / and the logic for the file system for the dynamic memory
	//there is linker problem if there is no function implementation 
	Book() = default;
	Book(const char* authorName, const char* bookName,const char* _description, int sizeDescription, const char** keywords, int countKeyWords, int publishedYear, double rating, Ganre ganre);
	Book(const Book& other);
	Book& operator=(const Book& other);
	Book& operator=(Book&& other);
	Book(Book&& other);
	~Book();

	void SetRaiting(double raiting);
	//Set for the keywords, description

	//if i want to make it private does that mean i need to inherite Book in Library
	void SetUniqueLibraryNum(int uniqueLibraryNum); //it may be better to be private/protected
	

	int GetPublishedYear() const;
	int GetUniqueLibraryNum() const;
	int GetSizeDescription() const;
	int GetCountKeyWords() const;
	double GetRaing() const;
	Ganre GetBookGanre() const;
	const char* GetAuthorName() const;  
	const char* GetBookName() const; //can it be const char* //the compiler wants it
	char* GetDescription() const;
	char** GetKeyWords() const;
	//Get for the keywords, description

	void InitializeBook(const char* authorName, const char* bookName, int publishedYear, double rating, int uniqueLibraryNum = 0, Ganre ganre = Ganre::unknown);
	void ClearBook();
private:
	//how was the consiquence of the type for better memory management
	char _authorName[200] = "";//will it be better to be dynamic memory //more memory -> better performance
	char _bookName[200] = ""; //why does this not work if its made in the constructor
	char* _description = nullptr;
	char** _keyWords = nullptr;
	Ganre _ganre = Ganre::undefined;
	int _publishedYear = 0;
	int _uniqueLibraryNum = -1;
	int _sizeDescription = 0; //you may clear it because you can use strlen()
	int _countKeyWords = 0;
	double _rating = 0.0;

	void free();
	void moveFrom(Book&& other);
	void copyFrom(const Book& other);
	void resizeForDescription(int sizeDescription);
	void resizeForKeyWords(int countKeyWords);

	void SetPublishedYear(int publishedYear);
	void SetBookGanre(Ganre ganre);
	void SetAuthorName(const char * authorName); 
	void SetBookName(const char* bookName); //is it better to have it also for right value 
	void SetDescription(const char* description, int sizeDescription);
	void SetKeyWords(char** keywords, int countKeyWords);//why can't be const char**

	friend std::istream& operator >>(std::istream& is, Book& book);
	friend std::ifstream& operator>>(std::ifstream& ifs, Book& book);
};

///////////////////////////////////////////////////////////////////////////////////////
//OUTPUT/INPUT FUNCTIONS
std::ostream& operator <<(std::ostream& os, const Book& book);
std::ofstream& operator<<(std::ofstream& os, const Book& book); //is it better to be in binary /////////
bool operator == (const Book& lhs, const Book& rhs);
bool operator != (const Book& lhs, const Book& rhs);
void outputDetailedBook(const Book& book); 
char** split(const char* str, int count);
//Всяка книга се характеризира със  следните данни :
//
//автор
//заглавие
//жанр
//кратко описание
//година на издаване
//ключови думи
//рейтинг
//уникален номер за библиотеката

