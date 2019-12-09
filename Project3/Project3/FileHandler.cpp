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
	string mFolder = getenv("ProgramFiles") + iMainFolder;
	path fInstallFolder(mFolder);
	path fDataFolder(mFolder + iFilesFolder);
	path fBin(getenv("USERPROFILE") + iMainFolder + iBinFolder);

	_logger.infoLog("Checking install files.....");

	try
	{
		if (exists(fInstallFolder) && is_directory(fInstallFolder))
		{
			for (directory_entry& x : directory_iterator(mFolder))
			{ 
				std::vector<path> pFiles;
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: "+ x.path().c_str);
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }

		if (exists(fDataFolder) && is_directory(fDataFolder))
		{
			for (directory_entry& x : directory_iterator(mFolder + iFilesFolder))
			{
				std::vector<path> pFiles;
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: " + x.path().c_str);
			}
		}
	}
	catch (exception &ec)
	{
		_logger.fatalLog("exception found: " + ec.what);
	}
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