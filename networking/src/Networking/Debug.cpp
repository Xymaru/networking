#include "Debug.h"

#include <iostream>
#include <cstdarg>
#include <filesystem>
#include <sstream>

#include "filesystem/FileSystem.h"

namespace EM::Debug
{
	namespace 
	{
		std::vector<EString> Logs; // Used to dump into a file can't be cleared
		std::vector<LogMessage> Messages; // Usage for a console can be cleared
		EString LastLog;
		bool DumpLog = true;

		struct DebugStats
		{
			u32 InfoCount = 0;
			u32 WarningCount = 0;
			u32 ErrorCount = 0;
			u32 TotalCount() const
			{
				return InfoCount + WarningCount + ErrorCount;
			}
			~DebugStats()
			{
				if(DumpLog)
				{
					if(!FileSystem::Exists("Logs"))
						FileSystem::CreateDir("Logs");

					EM::File dumpLog = FileSystem::OpenO("Logs/log-dump.txt");
					for(const auto& log : Logs)
					{
						dumpLog.Write(log.data(), log.size());
					}
					dumpLog.Close();
				}
			}
		} DebugStats{};

	}
	
	std::string GetLastLog()
	{
		return LastLog;
	}

	void ClearLogMessages()
	{
		Messages.clear();
		DebugStats = {};
	}

	LogMessage GetLastLogMessage()
	{
		return Messages[Messages.size() - 1];
	}
	void Log(const std::string& title, const std::string& message)
	{
		std::stringstream buffer;
		buffer << "[Info] " << title << " - " << message << std::endl;
		LogMessage log { buffer.str(), INFO };
		LastLog = buffer.str();

		Messages.emplace_back(log);
		Logs.emplace_back(buffer.str());
	}

	void LogWarning(const std::string& title, const std::string& message)
	{
		std::stringstream buffer;
		buffer << "[Warning] " << title << " - " << message << std::endl;
		LogMessage log { buffer.str(), WARNING };
		LastLog = buffer.str();

		Messages.emplace_back(log);
		Logs.emplace_back(buffer.str());
	}

	void LogError(const std::string& title, const std::string& message)
	{
		std::stringstream buffer;
		buffer << "[Error] " << title << " - " << message << std::endl;
		LogMessage log { buffer.str(), ERROR };
		LastLog = buffer.str();
		
		Messages.emplace_back(log);
		Logs.emplace_back(buffer.str());
	}

	const std::vector<LogMessage>& GetLogs()
	{
		return Messages;
	}

	std::string GetLastLogInfo()
	{
		return Logs[Logs.size() - 1];
	}
}
