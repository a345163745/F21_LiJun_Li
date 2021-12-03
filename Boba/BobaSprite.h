#pragma once
#include "pch.h"
#include "BobaUtils.h"
#include "BobaSpriteImplementation.h"
namespace Boba
{
	class BOBA_API BobaSprite
	{
	public:
		BobaSprite();
		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();
	private:
		std::unique_ptr<BobaSpriteImplementation> bSprite;
	};

}