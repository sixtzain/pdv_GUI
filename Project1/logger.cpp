#include "logger.h"

namespace loggerino = boost::log;
namespace keywords = boost::log::keywords;

logger::logger()
{
	initial(1);
}

void logger::initial(int severity_level=1)
{
	loggerino::register_simple_formatter_factory<loggerino::trivial::severity_level, char>("Severity");
	loggerino::add_file_log
	(
		keywords::file_name = "main.log",
		keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%"
	);

	switch (severity_level)
	{
	case 3:
		loggerino::core::get()->set_filter
		(
			loggerino::trivial::severity >= loggerino::trivial::trace
		);
		break;
	case 2:
		loggerino::core::get()->set_filter
		(
			loggerino::trivial::severity >= loggerino::trivial::debug
		);
		break;
	case 1:
	default:
		loggerino::core::get()->set_filter
		(
			loggerino::trivial::severity >= loggerino::trivial::info
		);
		break;
	}

	loggerino::add_common_attributes();

}

void logger::infoLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(info) << message;
}

void logger::debugLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(debug) << message;
}

void logger::traceLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(trace) << message;
}

void logger::warningLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(warning) << message;
}

void logger::errorLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(error) << message;
}

void logger::fatalLog(std::string message)
{
	//logger::initial();
	BOOST_LOG_TRIVIAL(fatal) << message;
}