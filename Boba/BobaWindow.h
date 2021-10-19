#pragma once

#include "BobaUtils.h"
#include "BobaWindowImplementation.h"
namespace Boba
{
	class BOBA_API BobaWindow
	{
	public:
		BobaWindow();
		void CreateWindow(int width, int height,const std::string & name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
	private:
		BobaWindowImplementation* bWindow;
	};
}
