#pragma once

#include <Networking/Core.h>
#include <Networking/SimpleTypes.h>
#define FMT_HEADER_ONLY
#include <vector>

#include "../vendor/fmt/format.h"

namespace EM::Debug
{
	enum LogSeverity
	{
		INFO	= BIT(0),
		WARNING = BIT(1),
		ERROR	= BIT(2),
		MAX		= BIT(3)
	};
	inline LogSeverity operator|(LogSeverity a, LogSeverity b)
	{
		return static_cast<LogSeverity>(static_cast<int>(a) | static_cast<int>(b));
	}
	inline LogSeverity operator&(LogSeverity a, LogSeverity b)
	{
		return static_cast<LogSeverity>(static_cast<int>(a) & static_cast<int>(b));
	}
	inline LogSeverity operator|=(LogSeverity& a, LogSeverity b)
	{
		return a = a | b;
	}

	struct LogMessage
	{
		EString Message;
		LogSeverity Severity;
	};
	
	void EM_API Log(const std::string& title, const std::string& message);
	void EM_API LogWarning(const std::string& title, const std::string& message);
	void EM_API LogError(const std::string& title, const std::string& message);
	
	EM_API const std::vector<LogMessage>&  GetLogs();
	EM_API LogMessage GetLastLogMessage();
	EM_API void ClearLogMessages();
}

#define EM_FMT(...) fmt::format(__VA_ARGS__)

#define EM_INFO(...) EM::Debug::Log(__FUNCTION__, EM_FMT(__VA_ARGS__))
#define EM_WARN(...) EM::Debug::LogWarning(__FUNCTION__, EM_FMT(__VA_ARGS__))
#define EM_ERROR(...) EM::Debug::LogError(__FUNCTION__, EM_FMT(__VA_ARGS__))