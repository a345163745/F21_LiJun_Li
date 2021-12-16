#include "pch.h"
#include "BobaEvents.h"
namespace Boba {


	Boba::BobaKeyPressedEvent::BobaKeyPressedEvent(int keyCode): bKeyCode(keyCode)
	{
	}

	int Boba::BobaKeyPressedEvent::GetKeyCode() const
	{
		return bKeyCode;
	}
}