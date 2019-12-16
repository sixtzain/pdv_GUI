#pragma once
#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "logger.h"
#include "defines.h"
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
	int  writeUsrData(int dDataType, string dDataContent, string pPassword);

private:
	int conStrToBin(string pStrData);
	string conBinToStr(int pBinData);

	string iMainFolder = "\\pdv_gui";
	string iBinFolder = "\\bin";
	string iFilesFolder = "\\data_files";
	string iRecoveryFolder = "\\recovery";
	string iDllFolder = "\\dll";
};

