#pragma once
#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#ifdef FILE_HANDLER_EXPORTS
#define FILE_HANDLER_API __declspec(dllexport)
#else
#define FILE_HANDLER_API __declspec(dllimport)
#endif

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "defines.h"
#include "boost\filesystem.hpp"
#include "boost\filesystem\path.hpp"
#include "..\..\logger\logger\logger.h"
#include "boost\filesystem\operations.hpp"

using namespace std;
using namespace boost::filesystem;

class FILE_HANDLER_API FileHandler
{
public:
	FileHandler();
	~FileHandler();

	bool rootDirectory();
	bool checkInstallIntegrity();
	int  writeUsrData(int dDataType, std::string dDataContent, std::string pPassword);

private:
	int conStrToBin(string pStrData);
	std::string conBinToStr(int pBinData);

	std::string iMainFolder = "\\pdv_gui";
	std::string iBinFolder = "\\bin";
	std::string iFilesFolder = "\\data_files";
	std::string iRecoveryFolder = "\\recovery";
	std::string iDllFolder = "\\dll";
};

