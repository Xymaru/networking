#include <Networking.h>

int main(int argc, char** argv) {
	EM::Window* window = EM::Window::GetInstance();

	window->Awake();

	EM::Input::Init();

	while (!EM::Input::WindowQuit()) {
		// Pre update
		window->PreUpdate();

		// Updates
		EM::Input::Update();

		// Main logic


		// Post update
		window->PostUpdate();
		EM::Time::PostUpdate();
	}

	window->Close();

	return 0;
}