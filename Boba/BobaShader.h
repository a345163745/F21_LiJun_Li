#pragma once
#include "BobaUtils.h"
#include "BobaShaderImplementation.h"
namespace Boba
{
	class BOBA_API BobaShader
	{
	public:
		BobaShader();
		void Load(const std::string& vertexFile, const std::string& fragmentFile);
		void Use();

	private:
		std::unique_ptr<BobaShaderImplementation> bShader;
	};
}

