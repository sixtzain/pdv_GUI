#pragma once
#include "boost\log\core.hpp"
#include "boost\log\trivial.hpp"
#include "boost\log\expressions.hpp"
#include "boost\log\utility\setup\file.hpp"
#include "boost\log\utility\setup\common_attributes.hpp"

class logger
{
public:
	logger();
	void initial(int severity_level);
	void infoLog(std::string message);
	void debugLog(std::string message);
	void traceLog(std::string message);
	void warningLog(std::string message);
	void errorLog(std::string message);
	void fatalLog(std::string message);
};

