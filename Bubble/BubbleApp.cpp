#include "pch.h"
#include "BubbleApp.h"


namespace Bubble
{
	void BubbleApp::Run()
	{
		std::cout << "Bubble running..." << std::endl;
		while (true)
		{
			OnUpdate();
		}
	}
	void BubbleApp::OnUpdate()
	{

	}

	BubbleApp::BubbleApp()
	{}
}