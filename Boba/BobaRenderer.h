#pragma once
#include "BobaSprite.h"
#include "BobaShader.h"
#include "BobaRendererImplementation.h"
#include "BobaUtils.h"

namespace Boba
{
	class BOBA_API BobaRenderer
	{
	public:
		static void Init();
		static void Draw(BobaSprite& sprite,
			int xPos, int yPos,
			int width, int height,
			BobaShader& shader);
		static void ClearFrame();
		static void ShutDown();

	private:
		BobaRenderer();
		inline static BobaRenderer* bInstance{ nullptr };
		inline static std::unique_ptr<BobaRendererImplementation> bImp;
	};
}
