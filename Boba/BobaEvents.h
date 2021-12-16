#pragma once

#include "BobaUtils.h"
namespace Boba {
	class BOBA_API BobaKeyPressedEvent
	{
	public:
		BobaKeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int bKeyCode{ -1 };
	};
}