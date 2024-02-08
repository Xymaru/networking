#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../vendor/stb/stb_image.h"

#include <sdl2/SDL.h>
#include "sdl2/sdl_image.h"
#include "glew/gl/glew.h"
#include "sdl2/SDL_opengl.h"

#include <Networking/filesystem/FileSystem.h>

#include <iostream>

namespace EM {
	Image::Image() : 
		m_TextureId(-1),
		m_ImageSize({0, 0})
	{

	}

	Image::~Image()
	{
		glDeleteTextures(1, &m_TextureId);
	}

	bool Image::Init(const char* path)
	{
		Memory img_mem = EM::FileSystem::ReadAll(path);

		int w, h, ch;

		unsigned char* image = stbi_load_from_memory((stbi_uc*)img_mem.getBlock(), (int)img_mem.Size(), &w, &h, &ch, STBI_rgb_alpha);

		if (!image) {
			return false;
		}

		glGenTextures(1, &m_TextureId);
		glBindTexture(GL_TEXTURE_2D, m_TextureId);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image);

		m_ImageSize.x = w;
		m_ImageSize.y = h;

		return true;
	}
}