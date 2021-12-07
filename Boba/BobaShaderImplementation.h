#pragma once

namespace Boba
{
	class BobaShaderImplementation 
	{
	public:
		virtual void Load(const std::string& vertexFile, const std::string& fragmentFile)=0;
		virtual void SetVec2InitUniform(const std::string& unifName, int first, int second)=0;
		virtual void Use()=0;
	};
}