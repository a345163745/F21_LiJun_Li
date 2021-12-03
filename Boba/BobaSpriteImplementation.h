#pragma once
#include "pch.h"

namespace Boba
{
	class BobaSpriteImplementation
	{
	public:
		virtual void LoadImage(const std::string& pictureFile) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void Bind() = 0;
	};

}