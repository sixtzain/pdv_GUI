#pragma once

#include <iostream>
#include <stdlib.h>

#include "logger.h"
#include "boost\filesystem.hpp"
#include "boost\filesystem\path.hpp"
#include "boost\filesystem\operations.hpp"

using namespace std;
using namespace boost::filesystem;

class FileHandler :
	public logger
{
public:
	FileHandler();
	~FileHandler();

	bool rootDirectory();
	bool checkInstallIntegrity();
	int  writeUsrData(int dDataType, string dDataContent);

private:
	int conStrToBin(string pStrData);
	string conBinToStr(int pBinData);

	string iMainFolder = "\\pdv\\";
	string iBinFolder = "\\Bin\\";
	string iFilesFolder = "\\Files\\";
	string iRecoveryFolder = "\\Recovery\\";
	string iDllFolder = "\\dll\\";
};

