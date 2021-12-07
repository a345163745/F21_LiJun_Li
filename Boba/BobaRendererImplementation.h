#pragma once
#include "BobaSprite.h"
#include "BobaShader.h"
namespace Boba
{
	class BobaRendererImplementation
	{
	public:
		virtual void Draw(BobaSprite& sprite,
		int xPos, int yPos,
		int width, int height,
		BobaShader& shader)=0;
		virtual void ClearFrame()=0;
		virtual ~BobaRendererImplementation() {};
	};
}