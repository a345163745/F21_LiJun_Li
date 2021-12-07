#include "pch.h"
#include "BobaApp.h"
#include "BobaSprite.h"
#include "BobaShader.h"
#include "BobaRenderer.h"

#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace Boba
{
	void BobaApp::Run()
	{
		std::cout << "Boba running..." << std::endl;

		bGameWindow.CreateWindow(800,600,"TEST");
		Boba::BobaShader mshader;
		mshader.Load("Assets/Shader/myVertexShader.glsl",
			"Assets/Shader/myFragmentShader.glsl");
		mshader.SetVec2InitUniform("screenSize",
			bGameWindow.GetWindowWidth(),
			bGameWindow.GetWindowHeight());

		Boba::BobaSprite fish;
		fish.LoadImage("Assets/Textures/test.png");

		while (true)
		{
			BobaRenderer::ClearFrame();
			OnUpdate();

			BobaRenderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), mshader);
			bGameWindow.SwapBuffers();
	
			bGameWindow.PollEvents();

		}
		BobaRenderer::ShutDown();
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}