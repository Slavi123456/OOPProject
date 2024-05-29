#pragma once

enum class Ganre {

};

class Book {
public:

private:
	char _authorName[200]; //will it be better for 
	char _name[200];
	//char** _description;
	//char** _keyWords;
	Ganre _ganre;
	int _publishedYear;
	int _uniqueLibraryNum;
	double _rating;

};


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

