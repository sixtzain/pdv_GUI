#pragma once

#ifdef LOGGER_API_EXPORTS
#define LOGGER_API __declspec(dllexport)
#else
#define LOGGER_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

#include "boost\log\core.hpp"
#include "boost\log\trivial.hpp"
#include "boost\log\expressions.hpp"
#include "boost\log\utility\setup\file.hpp"
#include "boost\log\utility\setup\common_attributes.hpp"

class LOGGER_API logger
{
public:
	logger();
	void initial(int severity_level, std::string file_name);
	void infoLog(std::string message);
	void debugLog(std::string message);
	void traceLog(std::string message);
	void warningLog(std::string message);
	void errorLog(std::string message);
	void fatalLog(std::string message);
};

//extern "C" LOGGER_API logger* trgClass();