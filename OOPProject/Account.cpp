#include "Account.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTORS
Account::Account(const char* userName, const char* password, unsigned int levelOfAccess)
{
	strcpy_s(_userName, strlen(userName), userName);
	strcpy_s(_password, strlen(password), password);
	_levelOfAccess = levelOfAccess;
}
///////////////////////////////////////////////////////////////////////////////////////
//GET/SET FUNCTION
const char* Account::GetUserName() const
{
	return _userName;
}
int Account::GetLevelOfAccess() const
{
	return _levelOfAccess;
}
const char* Account::GetPassword() const
{
	return _password;
}

void Account::SetPassword(const char* password)
{
	//strcpy_s(_password, strlen(password), password); //why it doesn't work with "" or " " or anything
	strcpy_s(_password, 100, password);
}
void Account::SetLevelOfAccess(unsigned int levelOfAccess)
{
	_levelOfAccess = levelOfAccess;
}
void Account::SetUserName(const char* userName)
{
	//strcpy_s(_userName, strlen(userName), userName);
	strcpy_s(_userName, 100, userName);
}

///////////////////////////////////////////////////////////////////////////////////////
//OTHER MEMBER FUNCTIONS
void Account::CreateAccount(const char* userName, const char* password, unsigned int levelOfAccess)
{
	this->SetUserName(userName);
	this->SetPassword(password);
	_levelOfAccess = levelOfAccess;
}

void Account::ClearAccount()
{
	//delete[]this;
	SetUserName(" ");
	SetPassword(" ");
	_levelOfAccess = -1;
}

///////////////////////////////////////////////////////////////////////////////////////
//INPUT/ OUTPUT FOR STREAMS
std::ifstream& operator>>(std::ifstream& ifs, Account& account)
{
	char buffer[200];
	//ifs >> buffer;
	ifs.getline(buffer, 99);
	strcpy_s((char *)account.GetUserName(),99, buffer);


	ifs >> buffer;
	strcpy_s((char*)account.GetPassword(),99, buffer);

	int helperVariable;
	ifs >> helperVariable;
	account.SetLevelOfAccess(helperVariable);
	ifs.ignore();

	return ifs;
}
std::istream& operator>>(std::istream& is, Account& account)
{
	std::cout << std::endl << "-----------------------------------------" << std::endl;
	char buffer[200];
	//ifs >> buffer;
	std::cout << "Account user name {spaces are allowed}: ";
	is.getline(buffer, 99);
	//strcpy_s((char*)account.GetUserName(), strlen(buffer), buffer); //why does not work that way
	strcpy_s((char*)account.GetUserName(), 99, buffer);

	std::cout << "Account user password {spaces are not allowed}: ";
	is >> buffer;
	strcpy_s((char*)account.GetPassword(),99, buffer);

	std::cout << "Account level of access: ";
	int helperVariable;
	is >> helperVariable;
	account.SetLevelOfAccess(helperVariable);

	is.ignore();

	return is;
}

std::ofstream& operator<<(std::ofstream& ofs, Account& account)
{
	ofs << account.GetUserName() << std::endl;
	ofs << account.GetPassword() << " " << account.GetLevelOfAccess() << std::endl; 
	
	return ofs;
}
std::ostream& operator<<(std::ostream& os, Account& account)
{
	os << std::endl << "-----------------------------------------" << std::endl;
	os << std::endl << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	os << "Account user name: " << account.GetUserName() << std::endl;
	//os << "Account user password: " << account.GetPassword() << std::endl;
	os << "Acount level of access " << account.GetLevelOfAccess() << std::endl;
	os << std::endl << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;

	return os;
}

///////////////////////////////////////////////////////////////////////////////////////
//OTHER FUNCTIONS

bool operator==(const Account& lhs, const Account& rhs)
{
	return strcmp(lhs.GetUserName(), rhs.GetUserName()) == 0
		&& strcmp(lhs.GetPassword(), rhs.GetPassword()) == 0
		&& lhs.GetLevelOfAccess() == rhs.GetLevelOfAccess();
}
bool operator!=(const Account& lhs, const Account& rhs)
{
	return !(lhs == rhs);
}
