#pragma once
#include "Library.h"

class ProgramManager {
public:
	ProgramManager() = default;
	ProgramManager(const ProgramManager& other);
	ProgramManager(ProgramManager&& other);
	~ProgramManager();
	ProgramManager& operator=(const ProgramManager& other);
	ProgramManager& operator=(ProgramManager&& other);

	void SetFilePath(const char* filePath);
	
	//void TakeCommand(const char* command);

	void Open(const char* filePath);
	void Save();
	void SaveAs(const char* filePath);
	//void Help();
	//void Exit();//how to do the exit one

private:
	char* _filePath = nullptr;
	Library _openedLibrary;//does it need to be pointer

	void free();
	void moveFrom(ProgramManager&& other);
	void copyFrom(const ProgramManager& other);
};