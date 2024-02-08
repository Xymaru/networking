#include "Input.h"
#include "Window.h"
#include "sdl2/sdl.h"

namespace EM {
	bool Input::m_WindowQuit = false;
	bool Input::m_MousePress = false;

	Math::Vector2i Input::m_MousePositionScreen = { 0, 0 };
	Math::Vector2f Input::m_MousePosition = { 0.0f, 0.0f };

	const u8* Input::mSDLKeyState = nullptr;
	Input::KeyState* Input::mKeyStates = nullptr;
	int Input::mNumKeys = 0;

	Action<SDL_Event*> Input::m_CustomInputProcessor;

	void Input::Init()
	{
		mSDLKeyState = SDL_GetKeyboardState(&mNumKeys);

		mKeyStates = new KeyState[mNumKeys];
	}

	void Input::Update()
	{
		memset(mKeyStates, KS_NONE, mNumKeys);

		SDL_Event event_poll;

		while (SDL_PollEvent(&event_poll)) {
			switch (event_poll.type) {
			case SDL_QUIT:
				m_WindowQuit = true;
				break;
			case SDL_KEYDOWN:
				if (event_poll.key.repeat) {
					mKeyStates[event_poll.key.keysym.scancode] = KS_KEYPRESS;
				}
				else {
					mKeyStates[event_poll.key.keysym.scancode] = KS_KEYDOWN;
				}
				break;
			case SDL_KEYUP:
				mKeyStates[event_poll.key.keysym.scancode] = KS_KEYUP;
				break;
			case SDL_MOUSEMOTION:
				m_MousePositionScreen.x = event_poll.motion.x;
				m_MousePositionScreen.y = event_poll.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_MousePress = true;
				break;
			case SDL_MOUSEBUTTONUP:
				m_MousePress = false;
				break;
			case SDL_WINDOWEVENT:
				switch (event_poll.window.event) {
				case SDL_WINDOWEVENT_RESIZED:

					break;
				}
				break;
			default:
				break;
			}

			m_CustomInputProcessor(&event_poll);
		}
	}

	void Input::CleanUp()
	{
		delete[] mKeyStates;
	}

	bool Input::getKeyUp(u32 key)
	{
		return mKeyStates[key] == KS_KEYUP;
	}

	bool Input::getKeyDown(u32 key)
	{
		return mKeyStates[key] == KS_KEYDOWN;
	}

	bool Input::getKey(u32 key)
	{
		return mSDLKeyState[key];
	}
}