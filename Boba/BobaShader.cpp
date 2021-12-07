#include "pch.h"
#include "BobaShader.h"
#include "OpenGLimport/OpenGLShader.h"

namespace Boba
{
	BobaShader::BobaShader()
	{
#ifdef  BOBA_OPENGL
		bShader = std::unique_ptr<BobaShaderImplementation>{ new OpenGLShader };
#else
		#only_OpenGL_is_implemented_at_the_moment
#endif //  BOBA_OPENGL

	}
	void BobaShader::Load(const std::string& vertexFile, const std::string& fragmentFile) 
	{
		bShader->Load(vertexFile, fragmentFile);
	}
	void BobaShader::SetVec2InitUniform(const std::string& unifName, int first, int second)
	{
		bShader->SetVec2InitUniform(unifName, first, second);
	}
	void BobaShader::Use()
	{
		bShader->Use();
	}
}