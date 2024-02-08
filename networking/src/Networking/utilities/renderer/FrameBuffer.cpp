#include "FrameBuffer.h"

#include <Networking/Debug.h>

#include "glew/GL/glew.h"

namespace EM {
	FrameBuffer::FrameBuffer() : 
		m_FBO(0),
		m_RBO(0),
		m_ColorBufferTexture(0),
		m_Width(0),
		m_Height(0),
		m_Inited(false)
	{
	}

	FrameBuffer::~FrameBuffer()
	{
		if (m_Inited) {
			glDeleteTextures(1, &m_ColorBufferTexture);
			glDeleteRenderbuffers(1, &m_RBO);
			glDeleteFramebuffers(1, &m_FBO);
		}
	}

	void FrameBuffer::Init(int width, int height)
	{
		m_Width = width;
		m_Height = height;

		// FRAMEBUFFER
		glGenFramebuffers(1, &m_FBO);
		glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

		// Color texture
		glGenTextures(1, &m_ColorBufferTexture);
		glBindTexture(GL_TEXTURE_2D, m_ColorBufferTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorBufferTexture, 0);
		
		// Depth texture
		glGenRenderbuffers(1, &m_RBO);
		glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			EM_ERROR("Framebuffer not completed");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		m_Inited = true;
	}

	void FrameBuffer::Bind()
	{
		glViewport(0, 0, m_Width, m_Height);
		glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void FrameBuffer::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}