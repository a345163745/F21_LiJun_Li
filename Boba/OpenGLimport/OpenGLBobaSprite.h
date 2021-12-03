#pragma once
#include "pch.h"
#include "BobaUtils.h"
#include "BobaSpriteImplementation.h"
#include "glad/glad.h"
namespace Boba
{
	class OpenGLBobaSprite: public BobaSpriteImplementation
	{
	public:
		OpenGLBobaSprite();
		OpenGLBobaSprite(const std::string& pictureFile);
		~OpenGLBobaSprite();
		virtual void LoadImage(const std::string& pictureFile) override; 
		unsigned char* GetDataPointer() const;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
	private:
		unsigned int bTexture{0};
		unsigned char* bImage{ nullptr };
		int bWidth{ 0 };
		int bHeight{ 0 };
	};
}


