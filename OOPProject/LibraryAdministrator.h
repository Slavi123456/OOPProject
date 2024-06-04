#pragma once
#include "LibraryProfile.h"

class LibraryAdministrato : public LibraryProfile {
public:
	void addBook();
	void addBook(const Book& newBook); //in Book copyContructor &/&&
	void addBook(Book&& newBook); //in Book copyContructor &/&&
	void removeBook(int uniqueNumber); //it needs sorting of pointers

	void addUser();
	void addUser(const Account& account);
	void removeUser(const char* userName);
};