#pragma once

#include "BubbleUtils.h"

namespace Bubble
{
	class BUBBLE_API BubbleApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	protected:
		BubbleApp();

	private:

	};
}
