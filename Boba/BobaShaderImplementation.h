#pragma once

namespace Boba
{
	class BobaShaderImplementation 
	{
	public:
		virtual void Load(const std::string& vertexFile, const std::string& fragmentFile)=0;
		virtual void Use()=0;
	};
}