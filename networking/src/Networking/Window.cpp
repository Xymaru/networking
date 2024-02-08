#include "Window.h"
#include "Debug.h"

#include <sdl2/SDL_syswm.h>

#include <Networking/Time.h>

namespace EM
{
	Window* Window::pInstance = nullptr;

	using namespace Math;

	Window::Window() :
		m_FullScreen(false),
		m_VSync(false),
		mScreenWidth(1280),
		mScreenHeight(720),
		m_AspectRatio(0.0f),
		pGLContext(nullptr),
		pWindow(nullptr)
	{
		pSysWMinfo = new SDL_SysWMinfo();
	}

	Window::~Window()
	{
		delete pSysWMinfo;
	}

	

	Vector2f Window::screenPosToGl(const Vector2i& screen_position)
	{
		Vector2f gl_position = {
			screen_position.x / static_cast<float>(mScreenWidth),
			screen_position.y / static_cast<float>(mScreenHeight)
		};

		gl_position *= 2;
		gl_position -= 1;

		return gl_position;
	}

	Size2f Window::ScreenSizeToGl(const Size2i& size) {
		return {
			size.x / static_cast<float>(mScreenWidth),
			size.y / static_cast<float>(mScreenHeight)
		};
	}

	void Window::ResizeWindow(int width, int height)
	{
		SDL_SetWindowSize(pWindow, width, height);
		mScreenWidth = width;
		mScreenHeight = height;
	}

	void Window::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::updateScreen()
	{
		u64 dt = Time::deltaTimeMS();

		std::string title = "Networking - ";
		if (dt == 0) {
			title += "infinite";
		}
		else {
			title += std::to_string((int)(1.0f / dt * 1000));
		}
		title += " FPS";
		SDL_SetWindowTitle(pWindow, title.c_str());
		SDL_GL_SwapWindow(pWindow);
	}

	void Window::waitTime(int ms)
	{
		SDL_Delay(ms);
	}

	void* Window::GetNativeWindow()
	{
		return pSysWMinfo->info.win.window;
	}

	void Window::setFullScreen(bool fscreen) {
		m_FullScreen = fscreen;

		SDL_SetWindowFullscreen(pWindow, m_FullScreen ? SDL_WINDOW_FULLSCREEN : 0);
	}

	void Window::setVSync(bool vsync) {
		m_VSync = vsync;

		if (SDL_GL_SetSwapInterval(m_VSync ? 1 : 0) == -1) {
			EM_ERROR("Swap interval setting not supported");
		}
	}

	

	bool Window::Awake()
	{
		m_AspectRatio = mScreenWidth / (float)mScreenHeight;

		pWindow = NULL;

		if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3)) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1)) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE)) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;
		pWindow = SDL_CreateWindow("Empathy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, flags);

		if (!pWindow) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		SDL_VERSION(&pSysWMinfo->version);

		SDL_GetWindowWMInfo(pWindow, pSysWMinfo);

		pGLContext = SDL_GL_CreateContext(pWindow);

		if (!pGLContext) {
			EM_ERROR(SDL_GetError());
			return false;
		}

		glewExperimental = GL_TRUE;
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			const unsigned char* errorMessage = glewGetErrorString(error);
			EM_ERROR((const char*)errorMessage);
			return false;
		}

		if (SDL_GL_SetSwapInterval(1)) {
			EM_ERROR("Swap interval not supported");
			return false;
		}

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		Debug::Log("Video", "Awaken successfully");

		setVSync(m_VSync);

		return true;
	}

	void Window::PreUpdate()
	{
		clearScreen();
	}

	void Window::PostUpdate()
	{
		updateScreen();
	}

	void Window::Close()
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
		SDL_GL_DeleteContext(pGLContext);
		SDL_DestroyWindow(pWindow);
	}

	bool Window::LoadSettings(JSONDocument* doc)
	{
		JSONDocument& d = *doc;

		if (d.HasMember("vsync"))
			m_VSync = d["vsync"].as_bool();
		if (d.HasMember("fullscreen"))
			m_FullScreen = d["fullscreen"].as_bool();

		if (d.HasMember("width"))
			mScreenWidth = d["width"].as_uint();
		if (d.HasMember("height"))
			mScreenHeight = d["height"].as_uint();

		return true;
	}

	bool Window::SaveSettings(JSONDocument* doc)
	{
		doc->AddMember("vsync", m_VSync);
		doc->AddMember("width", mScreenWidth);
		doc->AddMember("height", mScreenHeight);
		doc->AddMember("fullscreen", m_FullScreen);


		return true;
	}
}