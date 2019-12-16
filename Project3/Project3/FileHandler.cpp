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
				_logger.infoLog("Path found: "+ x.path().string());
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }

		if (exists(fDataFolder) && is_directory(fDataFolder))
		{
			for (directory_entry& x : directory_iterator(mFolder + iFilesFolder))
			{
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: " + x.path().string());
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }

		if (exists(fBin) && is_directory(fBin))
		{
			for (directory_entry& x : directory_iterator(getenv("USERPROFILE") + iMainFolder + iBinFolder))
			{
				pFiles.push_back(x.path());
				_logger.infoLog("Path found: " + x.path().string());
			}
		}
		else { _logger.fatalLog("Some of the folders doesnt exist :0"); throw 2; }
	}
	catch (exception &ec)
	{
		_logger.fatalLog("exception found: " + *ec.what());
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
			int cont = 0;
			for (directory_entry& f : directory_iterator(fBin))
			{
				cont++;
				pFiles.push_back(f.path().string());
				_logger.infoLog("File found: " + f.path().string());
				if (f.path().string() == USER_PASS_FILE) { up = pFiles[cont--]; break; }
			}
			_logger.infoLog("Vector file found: " + up);
			std::ofstream	fUsrPass;

			fUsrPass.open(up);
			_logger.infoLog("File opened successfully!!");
			user = conStrToBin(dDataContent);
			password = conStrToBin(pPassword);

			_logger.debugLog("User: " + user + "Password: " + password);
			_logger.infoLog("Writing data to opened file!");

			fUsrPass << user + ":";
			fUsrPass << password + "\n";

			fUsrPass.close();
			_logger.infoLog("File closed successfully, operation complete!!");
		}
		else { _logger.errorLog("unabler to find path/file :("); throw 1; }
	}
	catch (exception &ex)
	{
		_logger.fatalLog("Unable to find or open up100022.bin file!! error code: " + *ex.what());
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
		_logger.infoLog("ascii val: " + to_string(ascChar));
	}
	return ascChar*50;
}

//Conversor from binary to String for decode data
string FileHandler::conBinToStr(int pBinData)
{
	string lol;
	lol = (char)(pBinData/50);
	_logger.debugLog("Converting from: " + to_string(pBinData) + "to string: " + lol);

	return lol;
}