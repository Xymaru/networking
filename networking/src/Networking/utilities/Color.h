#pragma once

#include <Networking/math/Math.h>

namespace EM
{
	namespace Color
	{
		const Math::Color4f WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
		const Math::Color4f BLACK = { 0.0f, 0.0f, 0.0f, 0.0f };

		const Math::Color4f RED = { 1.0f, 0.0f, 0.0f, 1.0f };
		const Math::Color4f GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
		const Math::Color4f BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };

		const Math::Color4f YELLOW = { 1.0f, 1.0f, 0.0f, 1.0f };

		inline int ToRGBA(const Math::Color4i& color) {
			return (color.r << 24) + (color.g << 16) + (color.b << 8) + color.a;
		}
	}
}