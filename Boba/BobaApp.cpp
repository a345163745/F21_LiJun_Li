#include "pch.h"
#include "BobaApp.h"
#include "GLFW/glfw3.h"
namespace Boba
{
	void BobaApp::Run()
	{
		std::cout << "Boba running..." << std::endl;

		mGameWindow.CreateWindow(800,600,"TEST");

		while (true)
		{
			OnUpdate();
			mGameWindow.SwapBuffers();
	
			mGameWindow.PollEvents();

		}
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}