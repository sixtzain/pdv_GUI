#include "FileHandler.h"

logger _logger;

std::string iMainFolder = "\\pdv_gui";
std::string iBinFolder = "\\bin";
std::string iFilesFolder = "\\data_files";
std::string iRecoveryFolder = "\\recovery";
std::string iDllFolder = "\\dll";

/*FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}*/

//Not sure what to do with this function, don't delete could be useful in the future
bool rootDirectory()
{
	return true;
}

//Check all install folders previously created by the WinRar install tool
bool checkInstallIntegrity()
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
int writeUsrData(int dDataType, string dDataContent, string pPassword)
{
	string	up, user, password, file_the_shit = "\\up100022.txt";
	path	fBin(getenv("USERPROFILE") + iMainFolder + iBinFolder);
	path	fileS(fBin.string() + file_the_shit);

	_logger.infoLog("Opening bin file for writing data");

	if (exists(fBin) && is_directory(fBin))
	{
		int	shitVar = 0;
		for (boost::filesystem::directory_entry &x : directory_iterator(fBin))
		{
			if (x.path().string() == fileS.string()) { _logger.infoLog("hasta aqui we" + x.path().string()); break; }
			//else { continue; }
			shitVar = 0;
			shitVar++;
			_logger.infoLog("mi pichula: " + fileS.string());
		}
		if (shitVar == 1) 
		{ 
			boost::filesystem::ofstream pUFile(fileS);
			pUFile.close();
		}
	}

	try
	{
		if (exists(fBin) && is_directory(fBin))
		{
			std::vector<string> pFiles;
			int cont = 0;
			for (boost::filesystem::directory_entry &f : boost::filesystem::directory_iterator(fBin))
			{
				cont++;
				pFiles.push_back(f.path().string());
				_logger.infoLog("actual path: " + fBin.string());
				_logger.infoLog("File found: " + f.path().string());
				if (f.path().string() == fileS.string()) { up = pFiles[cont]; break; _logger.infoLog("wtf is that!!: " + up + " " + pFiles[cont] + "sin el - " + pFiles[cont]); }
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
		else { _logger.errorLog("unabler to find path/file :("); return 1; }
	}
	catch (exception &ex)
	{
		_logger.fatalLog("Unable to find or open up100022.bin file!! error code: " + *ex.what());
		return 1;
	}

	return 0;
}

//Conversor from string to binary to encode data
int conStrToBin(string pStrData)
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
char* conBinToStr(int pBinData)
{
	int nDigit = 1;
	while (pBinData / 20 > 0)
	{
		pBinData = pBinData / 20;
		nDigit++;
	}

	char* lol = (char *) malloc(sizeof(char) * nDigit);
	*lol = (char)(pBinData/50);
	_logger.debugLog("Converting from: " + to_string(pBinData) + "to string: " + lol);

	return lol;
}