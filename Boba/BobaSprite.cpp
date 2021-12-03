#include "pch.h"
#include "BobaSprite.h"
#include "OpenGLimport/OpenGLBobaSprite.h"
namespace Boba
{
	BobaSprite::BobaSprite()
	{
#ifdef  BOBA_OPENGL
		bSprite = std::unique_ptr<BobaSpriteImplementation>{ new OpenGLBobaSprite };
#else
		#only_OpenGL_is_supported_so_far
#endif //  BOBA_OPENGL

	}
	void BobaSprite::LoadImage(const std::string& pictureFile)
	{
		bSprite->LoadImage(pictureFile);
	}

	int BobaSprite::GetWidth() const
	{
		return bSprite->GetWidth();
	}

	int BobaSprite::GetHeight() const
	{
		return bSprite->GetHeight();
	}

	void BobaSprite::Bind()
	{
		bSprite->Bind();
	}
}