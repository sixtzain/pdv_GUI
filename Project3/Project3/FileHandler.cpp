#include "FileHandler.h"



FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

//Not sure what to do with this function, don't delete could be useful in the future
bool FileHandler::rootDirectory()
{
	return true;
}

//Check all install folders previously created by the WinRar install tool
bool FileHandler::checkInstallIntegrity()
{
	return true;
}

//During first install this function will help to set the admin user and password as well, also implemented when creating users
int FileHandler::writeUsrData(int dDataType, string dDataContent)
{
	return 0;
}

//Conversor from string to binary to encode data
int FileHandler::conStrToBin(string pStrData)
{
	return 0;
}

//Conversor from binary to String for decode data
string FileHandler::conBinToStr(int pBinData)
{
	string lol;
	return lol;
}