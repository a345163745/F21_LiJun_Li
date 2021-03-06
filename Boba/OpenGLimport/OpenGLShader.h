#pragma once
#include "BobaShaderImplementation.h"
namespace Boba
{
	class OpenGLShader : public BobaShaderImplementation
	{
	public:
		virtual void Load(const std::string& vertexFile, const std::string& fragmentFile) override;
		virtual void SetVec2InitUniform(const std::string& unifName, int first, int second) override;
		virtual void Use() override;
	private:
		unsigned int bShaderProgram{ 0 };
	};
}