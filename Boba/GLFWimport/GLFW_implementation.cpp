#include "pch.h"

#include "GLFW_implementation.h"

namespace Boba
{
		void GLFW_implementation::Init()
		{
			if(glfwInit() == GL_FALSE)
				std::cout<<"ERROR:GLFW failed to init";
		}
		void GLFW_implementation::CreateWindow(int width, int height, const std::string& name)
		{
			bWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
			glfwMakeContextCurrent(bWindow);

			glfwSetWindowUserPointer(bWindow, &bCallbacks);
			glfwSetKeyCallback(bWindow, [](
				GLFWwindow* window, int key, int scancode, int action, int mods) {
					if (action == GLFW_PRESS || action == GLFW_REPEAT) {
						CallbackFunctions* callbacks{ (CallbackFunctions *)glfwGetWindowUserPointer(window) };
						BobaKeyPressedEvent event{ key };
						callbacks->KeyPressedCallback(event);
					}
				});
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

		void GLFW_implementation::SetKeyPressedCallback(std::function<void(BobaKeyPressedEvent&)> func)
		{
			bCallbacks.KeyPressedCallback = func;
		}
	
}