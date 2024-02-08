#include "Time.h"

#include <sdl2/SDL.h>

namespace EM {
	u64 Time::m_CurrentTime = 0;
	u64 Time::m_DeltaTime = 0;
	u64 Time::m_LastTime = 0;

	void Time::PostUpdate()
	{
		m_CurrentTime = SDL_GetTicks64();

		m_DeltaTime = m_CurrentTime - m_LastTime;

		m_LastTime = SDL_GetTicks64();
	}

	u64 Time::deltaTimeMS()
	{
		return m_DeltaTime;
	}

	float Time::deltaTime()
	{
		return static_cast<float>(m_DeltaTime / 1000.0f);
	}

	u64 Time::timeMS()
	{
		return m_CurrentTime;
	}

	float Time::time()
	{
		return static_cast<float>(m_CurrentTime / 1000.0f);;
	}
}