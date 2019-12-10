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
	std::vector<path> pFiles;

	_logger.infoLog("Checking install files.....");

	try
	{
		if (exists(fInstallFolder) && is_directory(fInstallFolder))
		{
			for (directory_entry& x : directory_iterator(mFolder))
			{ 
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: "+ x.path().c_str);
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }

		if (exists(fDataFolder) && is_directory(fDataFolder))
		{
			for (directory_entry& x : directory_iterator(mFolder + iFilesFolder))
			{
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: " + x.path().c_str);
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }

		if (exists(fBin) && is_directory(fBin))
		{
			for (directory_entry& x : directory_iterator(getenv("USERPROFILE") + iMainFolder + iBinFolder))
			{
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: " + x.path().c_str);
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }
	}
	catch (exception &ec)
	{
		_logger.fatalLog("exception found: " + ec.what);
		return false;
	}
	return true;
}

//During first install this function will help to set the admin user and password as well, also implemented when creating users
int FileHandler::writeUsrData(int dDataType, string dDataContent, string pPassword)
{
	string	up, user, password;
	path	fBin(getenv("USERPROFILE") + iMainFolder + iBinFolder);

	_logger.infoLog("Opening bin file for writing data");

	try
	{
		if (exists(fBin) && is_directory(fBin))
		{
			std::vector<string> pFiles;
			for (directory_entry& f : directory_iterator(fBin))
			{
				pFiles.push_back(f.path().c_str);
				_logger.infoLog("File found: " + f.path().c_str);
				if (f.path().c_str == USER_PASS_FILE) { up = pFiles[f.path().c_str]; break; }
			}
			_logger.infoLog("Vector file found: ");
			std::ofstream	fUsrPass;

			fUsrPass.open(up);
			user = conStrToBin(dDataContent);
			password = conStrToBin(pPassword);

			fUsrPass << user + ":";
			fUsrPass << password + "\n";
		}
		else { _logger.errorLog("unabler to find path/file :("); throw 1; }
	}
	catch (exception &ex)
	{
		_logger.fatalLog("Unable to find or open up100022.bin file!! error code: " + ex.what);
		return 1;
	}

	return 0;
}

//Conversor from string to binary to encode data
int FileHandler::conStrToBin(string pStrData)
{
	string user = pStrData;
	int ascChar;

	_logger.debugLog("Data inserted: " + user);

	for (int i = 0; i<user.length(); i++)
	{
		ascChar = user[i];
		cout << ascChar << endl;
	}
	return ascChar*50;
}

//Conversor from binary to String for decode data
string FileHandler::conBinToStr(int pBinData)
{
	string lol;
	return lol;
}