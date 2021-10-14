#pragma once

#include "BobaUtils.h"

namespace Boba
{
	class BUBBLE_API BobaWindow
	{
	public:
		BobaWindow();
		void CreateWindow(int width, int height, std::string name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowWidth() const;
	private:
		WindowImplementation* window;
	};
}
