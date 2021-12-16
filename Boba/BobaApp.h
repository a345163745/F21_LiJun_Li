#pragma once

#include "BobaUtils.h"
#include "BobaWindow.h"

#define FRAMES_PER_SECOND 30
namespace Boba
{
	class BOBA_API BobaApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(BobaKeyPressedEvent &event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;

	protected:
		BobaApp();

	private:
		BobaWindow bGameWindow;

		std::chrono::steady_clock::time_point bTimeOfNextFrame;
		std::chrono::microseconds bFrameDuration{1000 / FRAMES_PER_SECOND};
	};
}