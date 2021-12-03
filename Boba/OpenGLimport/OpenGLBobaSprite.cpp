#include "pch.h"
#include "OpenGLBobaSprite.h"
#include "stb_image.h"

namespace Boba {
	OpenGLBobaSprite::OpenGLBobaSprite(){}
	OpenGLBobaSprite::OpenGLBobaSprite(const std::string& pictureFile)
	{
		LoadImage(pictureFile);
	}
	OpenGLBobaSprite::~OpenGLBobaSprite()
	{
		
	}
	void OpenGLBobaSprite::LoadImage(const std::string& pictureFile)
	{
		unsigned char* image{ nullptr };
		int numChannels{ 0 };
		stbi_set_flip_vertically_on_load(true);
		image = stbi_load(pictureFile.c_str(), &bWidth, &bHeight, &numChannels, 0);

		assert(image != nullptr);

		glGenTextures(1, &bTexture);
		glBindTexture(GL_TEXTURE_2D, bTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bWidth, bHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(image);

	}
	unsigned char* OpenGLBobaSprite::GetDataPointer() const
	{ 
		return bImage;
	}
	int OpenGLBobaSprite::GetWidth() const
	{ 
		return bWidth;
	}
	int OpenGLBobaSprite::GetHeight() const
	{
		return bHeight;
	}
	void OpenGLBobaSprite::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, bTexture);
	}
}