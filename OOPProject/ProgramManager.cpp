#include "ProgramManager.h"
#include <iostream>
#include <fstream>
ProgramManager::ProgramManager(const ProgramManager& other)
{
}
///////////////////////////////////////////////////////////////////////////////////////
//BIG 6
ProgramManager::ProgramManager(ProgramManager&& other)
{
}
ProgramManager::~ProgramManager()
{

}
ProgramManager& ProgramManager::operator=(const ProgramManager& other)
{
	return *this;
}
ProgramManager& ProgramManager::operator=(ProgramManager&& other)
{
	return *this;
}
void ProgramManager::SetFilePath(const char* filePath)
{
	int sizeOfFilePath = strlen(filePath) + 1;
	_filePath = new char[sizeOfFilePath];
	strcpy_s(_filePath, sizeOfFilePath, filePath);
}
///////////////////////////////////////////////////////////////////////////////////////
//GET/ SET FUNCTIONS

///////////////////////////////////////////////////////////////////////////////////////
//OTHER FUNCTIONS

void ProgramManager::Open(const char* filePath)
{
	std::ifstream ifs(filePath);
	if (ifs.is_open() == false)
	{
		std::cerr << "Couldn't open the file";
		return;
	}
	std::cout << "File with file path " << filePath << " is open" << std::endl;

	loadLibrary(_openedLibrary, ifs);
	
	ifs.close();
}

void ProgramManager::Save()
{
	std::ofstream ofs(_filePath);
	if (ofs.is_open() == false)
	{
		std::cerr << "Couldn't open the file";
		return;
	}
	std::cout << "File with file path " << _filePath << " is open" << std::endl;

	saveLibrary(_openedLibrary, ofs);

	ofs.close();
}

void ProgramManager::SaveAs(const char* filePath)
{
	std::ofstream ofs(filePath);
	if (ofs.is_open() == false)
	{
		std::cerr << "Couldn't open the file";
		return;
	}
	std::cout << "File with file path " << filePath << " is open" << std::endl;

	saveLibrary(_openedLibrary, ofs);

	ofs.close();
}
