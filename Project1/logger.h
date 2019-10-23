#pragma once
#include "boost\log\core.hpp"
#include "boost\log\trivial.hpp"
#include "boost\log\expressions.hpp"
#include "boost\log\utility\setup\file.hpp"
#include "boost\log\utility\setup\common_attributes.hpp"

namespace loggerino = boost::log;
namespace keywords = boost::log::keywords;

ref class logger
{
public:
	logger();
	void init();
};

