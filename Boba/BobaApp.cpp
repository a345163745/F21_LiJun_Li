#include "pch.h"
#include "BobaApp.h"
namespace Boba
{
	void BobaApp::Run()
	{
		std::cout << "Boba running..." << std::endl;
		while (true)
		{
			OnUpdate();
		}
	}
	void BobaApp::OnUpdate(){}
	BobaApp::BobaApp(){}
}