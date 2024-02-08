#pragma once

#include <Networking/Core.h>
#include <Networking/SimpleTypes.h>

#include "utilities/ActionPack.h"

#include <Networking/math/Math.h>

union SDL_Event;

namespace EM {
	class EM_API Input
	{
	private:
		Input() = default;
		~Input() = default;
	public:
		enum KeyState {
			KS_KEYDOWN,
			KS_KEYUP,
			KS_KEYPRESS,
			KS_NONE
		};

		static void Init();

		static void Update();

		static void CleanUp();

		static bool WindowQuit(){ return m_WindowQuit; }

		static bool getKeyUp(u32 key);
		static bool getKeyDown(u32 key);
		static bool getKey(u32 key);
		static Math::Vector2i getMousePos() { return m_MousePositionScreen; }
		static Math::Vector2f getMousePosGl() { return m_MousePosition; }
		static bool getMousePress() { return m_MousePress; }

		static void setCustomInputProcessor(Action<SDL_Event*> cip) { m_CustomInputProcessor = cip; }
	private:
		static bool m_WindowQuit;
		static bool m_MousePress;

		static Math::Vector2i m_MousePositionScreen;
		static Math::Vector2f m_MousePosition;

		static const u8* mSDLKeyState;
		static KeyState* mKeyStates;
		static int mNumKeys;

		static Action<SDL_Event*> m_CustomInputProcessor;
	};
}