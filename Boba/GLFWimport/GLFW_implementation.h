#pragma once
#include "BobaWindowImplementation.h"
#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace Boba
{
	class GLFW_implementation :public BobaWindowImplementation
	{
	public:
		virtual void Init() override;
		virtual void CreateWindow(int width, int height, const std::string& name) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWindowWidth() const override;
		virtual int GetWindowHeight() const override;
		virtual void SetKeyPressedCallback(std::function<void(BobaKeyPressedEvent&)> func) override;
	private:
		struct CallbackFunctions
		{
			std::function<void(BobaKeyPressedEvent &)> KeyPressedCallback;
		} bCallbacks;
		GLFWwindow* bWindow;
	};
}