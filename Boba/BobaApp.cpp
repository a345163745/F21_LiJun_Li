#include "pch.h"
#include "BobaApp.h"
#include "BobaSprite.h"
#include "BobaShader.h"
#include "BobaRenderer.h"

#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"
namespace Boba
{
	void BobaApp::Run()
	{
		BOBA_LOG("Boba App is running...")

		bTimeOfNextFrame = std::chrono::steady_clock::now() + bFrameDuration;
		while (true)
		{
			BobaRenderer::ClearFrame();
			OnUpdate();

			std::this_thread::sleep_until(bTimeOfNextFrame);

			bGameWindow.SwapBuffers();
			bGameWindow.PollEvents();
	
			bTimeOfNextFrame += bFrameDuration;

		}
		BobaRenderer::ShutDown();
	}
	void BobaApp::OnUpdate(){}
	void BobaApp::OnKeyPressed(BobaKeyPressedEvent &event)
	{
		BOBA_LOG(event.GetKeyCode());
	}
	int BobaApp::GetGameWindowWidth() const
	{
		return bGameWindow.GetWindowWidth();
	}
	int BobaApp::GetGameWindowHeight() const
	{
		return bGameWindow.GetWindowHeight();
	}
	BobaApp::BobaApp()
	{
		bGameWindow.CreateWindow(800, 800, "BobaApp Game");

		bGameWindow.SetKeyPressedCallback([this](BobaKeyPressedEvent& event) {
			OnKeyPressed(event);
			});
		BobaRenderer::Init();
	}
}