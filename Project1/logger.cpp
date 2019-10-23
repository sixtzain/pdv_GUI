#include "logger.h"

logger::logger()
{
}

void logger::init()
{
	loggerino::register_simple_formatter_factory<loggerino::trivial::severity_level, char>("Severity");
	loggerino::add_file_log
	{
		keywords::file_name = "logged.log";
		keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%";
	};
	loggerino::core::get()->set_filter
	{
		loggerino::trivial::severity >= loggerino::trivial::info
	};

	loggerino::add_common_attributes();
}
