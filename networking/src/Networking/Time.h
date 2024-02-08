#pragma once

#include <Networking/Core.h>
#include <Networking/SimpleTypes.h>

namespace EM {
	class EM_API Time {
	private:
		Time() = default;
		~Time() = default;
		
		static u64 m_CurrentTime;
		static u64 m_LastTime;
		static u64 m_DeltaTime;
	public:
		// Post-update app time
		static void PostUpdate();

		// Returns time in milliseconds since last frame
		static u64 deltaTimeMS();

		// Returns time in seconds since last frame
		static float deltaTime();

		// Returns time in milliseconds since the app started executing
		static u64 timeMS();

		// Returns time in seconds since the app started executing
		static float time();
	};
}