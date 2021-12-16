#include "pch.h"
#include "BobaWindow.h"
#include "GLFWimport/GLFW_implementation.h"
namespace Boba
{
	BobaWindow::BobaWindow()
	{
#ifdef BOBA_WINDOWS
		bWindow = std::unique_ptr<BobaWindowImplementation>{ new GLFW_implementation() };
#elif BOBA_MAC
		bWindow = std::unique_ptr<BobaWindowImplementation>{ new GLFW_implementation() };
#elif BOBA_LINUX
		bWindow = std::unique_ptr<BobaWindowImplementation>{ new GLFW_implementation() };
#else
		#only_Windows_Linux_Mac_are_supported
#endif

		bWindow->Init();
	}

	void BobaWindow::CreateWindow(int width, int height, const std::string& name)
	{
		bWindow->CreateWindow(width, height, name);
	}

	void BobaWindow::SwapBuffers()
	{
		bWindow->SwapBuffers();
	}
	void BobaWindow::PollEvents()
	{
		bWindow->PollEvents();
	}
	int BobaWindow::GetWindowWidth() const
	{
		return bWindow->GetWindowWidth();
	}
	int BobaWindow::GetWindowHeight() const
	{
		return bWindow->GetWindowHeight();
	}

	void BobaWindow::SetKeyPressedCallback(std::function<void(BobaKeyPressedEvent&)> func)
	{
		bWindow->SetKeyPressedCallback(func);
	}

}