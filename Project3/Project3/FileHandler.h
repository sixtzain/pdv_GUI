#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>

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

	logger	_logger;

	bool rootDirectory();
	bool checkInstallIntegrity();
	int  writeUsrData(int dDataType, string dDataContent);

private:
	int conStrToBin(string pStrData);
	string conBinToStr(int pBinData);

	string iMainFolder = "\\pdv_gui";
	string iBinFolder = "\\bin";
	string iFilesFolder = "\\data_files";
	string iRecoveryFolder = "\\recovery";
	string iDllFolder = "\\dll";
};

