#include "pch.h"
#include "BobaApp.h"
#include "GLFW/glfw3.h"
namespace Boba
{
	void BobaApp::Run()
	{
		std::cout << "Boba running..." << std::endl;
		GLFWwindow* window;
		glfwInit();
		//mGameWindow.CreateWindow(800,600,"Test");
		window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
		while (true)
		{
			OnUpdate();
			//mGameWindow.SwapBuffers();
			glfwSwapBuffers(window);
			//mGameWindow.PollEvents();
			glfwPollEvents();
		}
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}