#include "pch.h"
#include "BobaRenderer.h"
#include "OpenGLimport/OpenGLRenderer.h"


namespace Boba
{
	BobaRenderer::BobaRenderer()
	{
#ifdef BOBA_OPENGL
		bImp = std::unique_ptr<BobaRendererImplementation>{ new OpenGLRenderer };
#else
	#only_OpenGL_is_supported_so_far
#endif
	}
	void BobaRenderer::Init()
	{
		if (bInstance == nullptr) {
			bInstance = new BobaRenderer;
		}
	}
	void BobaRenderer::Draw( BobaSprite& sprite,
		int xPos, int yPos,
		int width, int height,
		BobaShader& shader)
	{
		bImp->Draw(sprite, xPos, yPos,width,height,shader);
	}
	void BobaRenderer::ClearFrame() {
		bImp->ClearFrame();
	}
	void BobaRenderer::ShutDown()
	{
		if (bInstance != nullptr) {
			delete bInstance;
			bInstance = nullptr;
		}
	}
}