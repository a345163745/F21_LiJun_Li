#include "pch.h"

#include "GLFW_implementation.h"

namespace Boba
{
		void GLFW_implementation::Init()
		{
			glfwInit();
		}
		void GLFW_implementation::CreateWindow(int width, int height, const std::string& name)
		{
			bWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		}

		void GLFW_implementation::SwapBuffers() 
		{
			glfwSwapBuffers(bWindow);
		}

		void GLFW_implementation::PollEvents() 
		{
			glfwPollEvents();
		}

		int GLFW_implementation::GetWindowWidth() const 
		{
			int width{ 0 };
			int height{ 0 };

			glfwGetWindowSize(bWindow, &width, &height);
			return width;
		}

		int GLFW_implementation::GetWindowHeight() const 
		{
			int width{ 0 };
			int height{ 0 };

			glfwGetWindowSize(bWindow, &width, &height);
			return height;
		}
	
}