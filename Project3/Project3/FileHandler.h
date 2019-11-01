#pragma once
#include "logger.h"
#include "boost\filesystem\path.hpp"
#include "boost\filesystem\operations.hpp"

class FileHandler :
	public logger
{
public:
	FileHandler();
	~FileHandler();
};

