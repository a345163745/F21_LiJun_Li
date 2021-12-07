#pragma once

#include "BobaRendererImplementation.h"
#include "BobaShader.h"
#include "BobaSprite.h"
namespace Boba
{
	class OpenGLRenderer : public BobaRendererImplementation
	{
	public:
		OpenGLRenderer();
		virtual void Draw(BobaSprite& sprite,
			int xPos, int yPos,
			int width, int height,
			BobaShader& shader) override;
		virtual void ClearFrame() override;
	};
}