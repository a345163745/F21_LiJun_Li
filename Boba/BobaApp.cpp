#include "pch.h"
#include "BobaApp.h"
#include "GLFW/glfw3.h"
namespace Boba
{
	void BobaApp::Run()
	{
		std::cout << "Boba running..." << std::endl;

		bGameWindow.CreateWindow(800,600,"TEST");

		while (true)
		{
			OnUpdate();
			bGameWindow.SwapBuffers();
	
			bGameWindow.PollEvents();

		}
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}