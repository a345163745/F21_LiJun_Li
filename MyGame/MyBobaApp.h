#pragma once
#include "Boba.h"
#include "BobaUnit.h"
#include <vector>
class MyBobaApp : public Boba::BobaApp
{
public:
	MyBobaApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Boba::BobaKeyPressedEvent& event) override;
private:
	BobaUnit bHero;
	std::vector<BobaUnit> bStar;
	int bFrameCounter;
	Boba::BobaShader bShader;
};