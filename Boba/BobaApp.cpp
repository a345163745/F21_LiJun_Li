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
		window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
		while (true)
		{
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}