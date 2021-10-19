#pragma once

#include "BobaUtils.h"
#include "BobaWindow.h"

namespace Boba
{
	class BOBA_API BobaApp
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