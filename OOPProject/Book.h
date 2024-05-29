#pragma once
#include <fstream>

enum class Ganre {
	undefined, 
	unknown,
	Horror,
	Romatic,
	Psyhologic
};

class Book {
public:
	//big Six
	Book(const char* authorName, const char* bookName, int publishedYear, double rating, Ganre ganre = Ganre::unknown);

	void SetRaiting(double raiting);
	//Set for the keywords, description

	//if i want to make it private does that mean i need to inherite Book in Library
	void SetUniqueLibraryNum(int uniqueLibraryNum); //it may be better to be private/protected
	

	int GetPublishedYear() const;
	int GetUniqueLibraryNum() const;
	double GetRaing() const;
	Ganre GetBookGanre() const;
	char* GetAuthorName() const; //can it be const char*
	char* GetBookName() const; //can it be const char*
	//Get for the keywords, description

private:
	//how was the consiquence of the type for better memory management
	char _authorName[200];//will it be better to be dynamic memory //more memory -> better performance
	char _bookName[200];
	//char** _description;
	//char** _keyWords;
	Ganre _ganre;
	int _publishedYear;
	int _uniqueLibraryNum;
	double _rating;

	void SetPublishedYear(int publishedYear);
	Ganre SetBookGanre(Ganre ganre);
	void SetAuthorName(const char * authorName);
	void SetBookName(const char* bookName);

	friend std::istream& operator >>(std::istream& is, Book& book);
};

std::ostream& operator <<(std::ostream& os, const Book& book);


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

