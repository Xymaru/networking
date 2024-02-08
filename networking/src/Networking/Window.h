#pragma once

#include "Networking/Core.h"

#include "sdl2/sdl.h"
#include "glew/GL/glew.h"
#include "sdl2/sdl_opengl.h"

#include <Networking/SimpleTypes.h>
#include <Networking/utilities/json/JSONDocument.h>

#include <Networking/math/Math.h>

//#define FPS 240

struct SDL_SysWMinfo;

namespace EM {
	//-- Video class to handle window and fps control
	class EM_API Window
	{
	public:
		Window();
		~Window();

		static Window* GetInstance() {
			if (!pInstance) {
				pInstance = new Window();
			}

			return pInstance;
		}

		bool Awake();

		void PreUpdate();
		void PostUpdate();

		void Close();

		//-- Load settings function
		bool LoadSettings(JSONDocument* doc);

		//-- Save settings function
		bool SaveSettings(JSONDocument* doc);

		Math::Vector2f screenPosToGl(const Math::Vector2i& screen_position);
		Math::Size2f ScreenSizeToGl(const Math::Size2i& size);

		void ResizeWindow(int width, int height);

		void clearScreen();
		void updateScreen();
		void waitTime(int ms);

		int GetScreenWidth() const { return mScreenWidth; }
		int GetScreenHeight() const { return mScreenHeight; }
		float GetAspectRatio() const { return m_AspectRatio; }

		SDL_Window* GetWindow() const { return pWindow; }
		SDL_GLContext GetContext() const { return pGLContext; }
		void* GetNativeWindow();

		void setFullScreen(bool fscreen);
		bool getFullScreen() { return m_FullScreen; }

		void setVSync(bool vsync);
		bool getVSync() { return m_VSync; }
	private:
		static Window* pInstance;

		SDL_Window* pWindow = nullptr;
		SDL_GLContext pGLContext;
		SDL_SysWMinfo* pSysWMinfo = nullptr;

		u32 mScreenWidth, mScreenHeight;
		float m_AspectRatio;
		bool m_FullScreen;
		bool m_VSync;
	};
}