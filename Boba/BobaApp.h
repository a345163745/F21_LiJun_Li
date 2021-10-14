#pragma once

#include "BobaUtils.h"
#include "BobaWindow.h"

namespace Boba
{
	class BUBBLE_API BobaApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	protected:
		BobaApp();

	private:
		BobaWindow mGameWindow;
	};
}