#pragma once

#include <Networking/Core.h>
#include <Networking/SimpleTypes.h>

#include <Networking/math/Math.h>

namespace EM 
{
	class EM_API Image
	{
	private:
		u32 m_TextureId;
		Math::Size2i m_ImageSize;
	public:
		Image();
		~Image();
		
		bool Init(const char* path);
		constexpr  u32 TextureId() const { return m_TextureId; }
		const Math::Size2i& Size() const { return m_ImageSize; }
	};
}