#pragma once
#if 0
#include "Empathy/Core.h"

#include "Empathy/Resources.h"
#include "Empathy/SimpleTypes"

#include "Empathy/utilities/Color.h"
#include <Empathy/Renderer2D.h>


namespace EM
{
	class EM_API Text {
	private:
		ResourceId mFont;
		Color mColor;

		u32 mTexture;

		Renderer2D* mRenderer2D;
	public:
		Text();
		~Text();

		void setFont(const char* font);
		void setFont(ResourceId font);
		void setText(const char* text);

		void setColor(int red, int green, int blue);
		void setColor(Color color);

		void render();
	};
}
#endif