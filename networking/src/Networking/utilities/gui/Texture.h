#pragma once

//#include <Empathy/Core.h>
//#include <Empathy/SimpleTypes.h>
//
//#include "glew/gl/glew.h"
//
//#include <sdl2/SDL.h>
//#include <sdl2/SDL_image.h>
//#include <sdl2/SDL_opengl.h>
//
//#include "../Color.h"
//
//namespace EM {
//
//	class EM_API Texture {
//		private:
//			u32 m_TextureId;
//
//			SDL_Surface* m_TexturePixels;
//
//			void createOpenGLTexture();
//			void updateOpenGLTexture();
//		public:
//			Texture();
//			~Texture();
//
//			void Load(const char* texture_file);
//			void Create(int width, int height, int depth);
//
//			void Update();
//
//			void SetPixel(int x, int y, Color4i color);
//			void SetPixel(int point, Color4i color);
//
//			u32 getId() { return m_TextureId; }
//	};
//}