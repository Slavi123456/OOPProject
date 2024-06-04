#pragma once

#include <fstream>


class Account { //try to inherit the class from library
public:
	Account() = default;
	Account(const char* userName, const char* password, unsigned int levelOfAccess = 0);

	const char* GetUserName() const;
	int GetLevelOfAccess() const;

//protected: //maybe later for inheritance of this class
	const char* GetPassword() const;
	void SetPassword(const char* password);
	void SetLevelOfAccess(unsigned int levelOfAccess);
public:
	void SetUserName(const char* userName);

	void CreateAccount(const char* userName, const char* password, unsigned int levelOfAccess);

	void ClearAccount();
private: 
	char _userName[100] = "";
	char _password[100] = "";
	unsigned int _levelOfAccess = -1;
};

std::ifstream&  operator >>(std::ifstream& ifs, Account& account);
std::istream& operator >>(std::istream& is, Account& account);
			  
std::ofstream& operator <<(std::ofstream& ofs, Account& account);
std::ostream& operator <<(std::ostream& os, Account& account);

bool operator ==(const Account& lhs, const Account& rhs);
bool operator !=(const Account& lhs, const Account& rhs);