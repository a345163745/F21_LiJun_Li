#include "pch.h"
#include "BobaWindow.h"
namespace Boba
{
	BobaWindow::BobaWindow()
	{
		window->Init();
	}


	void BobaWindow::CreateWindow(int width, int height, std::string name)
	{
		window->CreateWindow(width, height, name);
	}
	void BobaWindow::SwapBuffers()
	{
		window->SwapBuffers();
	}
	void BobaWindow::PollEvents()
	{
		window->PollEvents();
	}
	int BobaWindow::GetWindowWidth() const
	{
		return window->GetWindowWidth();
	}
	int BobaWindow::GetWindowWidth() const
	{
		return window->GetWindowHeight();
	}

}