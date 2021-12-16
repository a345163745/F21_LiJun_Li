#include "MyBobaApp.h"



MyBobaApp::MyBobaApp():bHero("Assets/Textures/Hero.png",0,0,5),bFrameCounter(0)
{
	bShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	bShader.SetVec2InitUniform("screenSize", 800, 800);
	
}

void MyBobaApp::OnUpdate()
{
	bHero.UpdatePosition();
	
	for (auto& star : bStar)
	{
		star.UpdatePosition();
	}
	if (bFrameCounter % FRAMES_PER_SECOND == 0) {
		int newX{ rand() % 700 };
		int newY{ rand() % 750};

		BobaUnit::Direction newDir;

		int dirVal{ rand() % 4 };
		if (dirVal == 0)
			newDir = BobaUnit::Direction::Down;
		else if (dirVal == 1)
			newDir = BobaUnit::Direction::Up;
		else if (dirVal == 2)
			newDir = BobaUnit::Direction::Left;
		else
			newDir = BobaUnit::Direction::Right;


		bStar.push_back(BobaUnit{ "Assets/Textures/Star.png" ,newX,newY,1 });
		bStar.back().SetDirection(BobaUnit::Direction::Down);

	}
	auto it = bStar.begin();
	while( it != bStar.end())
	{
		if (bHero.CollideWith(*it) || it->GetPosY()==0)
			it = bStar.erase(it);

		else
			it++;
	}
	for (auto& star : bStar)
		star.Draw(bShader);

	bHero.Draw(bShader);
}

void MyBobaApp::OnKeyPressed(Boba::BobaKeyPressedEvent& event)
{
	switch (event.GetKeyCode())
	{
	case BOBA_KEY_LEFT:
		//bHero.SetPosX(bHero.GetPosX() - bHero.GetSpeed());
		bHero.SetDirection(BobaUnit::Direction::Left);
		break;
	case BOBA_KEY_RIGHT:
		//bHero.SetPosX(bHero.GetPosX() + bHero.GetSpeed());
		bHero.SetDirection(BobaUnit::Direction::Right);
		break;
	case BOBA_KEY_DOWN:
		//bHero.SetPosY(bHero.GetPosY() - bHero.GetSpeed());
		bHero.SetDirection(BobaUnit::Direction::Down);
		break;
	case BOBA_KEY_UP:
		//bHero.SetPosY(bHero.GetPosY() + bHero.GetSpeed());
		bHero.SetDirection(BobaUnit::Direction::Up);
		break;

	}

}
