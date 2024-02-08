#pragma once

#include <Networking/Core.h>
#include <Networking/SimpleTypes.h>

namespace EM
{
	class EM_API FrameBuffer
	{
	public:
		FrameBuffer();
		~FrameBuffer();

		void Init(int width, int height);
		void Bind();
		void Unbind();

		EM_NODISCARD constexpr u32 ColorBufferTexture() const { return m_ColorBufferTexture; }
		EM_NODISCARD constexpr i32 Width() const { return m_Width; }
		EM_NODISCARD constexpr i32 Height() const { return m_Height; }

	private:
		bool m_Inited;

		u32 m_FBO;
		u32 m_ColorBufferTexture;

		// Future render buffer object for depth
		u32 m_RBO;

		i32 m_Width;
		i32 m_Height;
	};
}