#pragma once
#include <fstream>

constexpr int CHAR_ARRAY_SIZE = 200;
enum class Ganre {
	undefined, 
	unknown,
	Horror,
	Romatic,
	Psyhologic
};

class Book {
public:
	//big Six / and the logic for the file system for the dynamic memory
	//there is linker problem if there is no function implementation 
	Book() = default;
	Book(const char* authorName, const char* bookName, int publishedYear, double rating, int uniqueLibraryNum);// Ganre ganre = Ganre::unknown);
	~Book();

	void SetRaiting(double raiting);
	//Set for the keywords, description

	//if i want to make it private does that mean i need to inherite Book in Library
	void SetUniqueLibraryNum(int uniqueLibraryNum); //it may be better to be private/protected
	

	int GetPublishedYear() const;
	int GetUniqueLibraryNum() const;
	double GetRaing() const;
	Ganre GetBookGanre() const;
	const char* GetAuthorName() const; 
	const char* GetBookName() const; //can it be const char* //the compiler wants it
	//Get for the keywords, description

private:
	//how was the consiquence of the type for better memory management
	char _authorName[200] = "";//will it be better to be dynamic memory //more memory -> better performance
	char _bookName[200] = ""; //why does this not work if its made in the constructor
	//char** _description;
	//char** _keyWords;
	Ganre _ganre = Ganre::undefined;
	int _publishedYear = 0;
	int _uniqueLibraryNum = 0;
	double _rating = 0.0;

	void SetPublishedYear(int publishedYear);
	void SetBookGanre(Ganre ganre);
	void SetAuthorName(const char * authorName); 
	void SetBookName(const char* bookName); //is it better to have it also for right value 

	friend std::istream& operator >>(std::istream& is, Book& book);
	friend std::ifstream& operator>>(std::ifstream& ifs, Book& book);
};

std::ostream& operator <<(std::ostream& os, const Book& book);
std::ofstream& operator<<(std::ofstream& os, const Book& book); //is it better to be in binary /////////
void outputDetailedBook(const Book& book); 

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

