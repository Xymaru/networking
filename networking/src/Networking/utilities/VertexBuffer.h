#pragma once

#include <Networking/math/Math.h>

namespace EM {
	struct Vertex
	{
		Math::Vector3f position;
	};

	struct TextureClip
	{
		Math::Vector2f bottomRight;
		Math::Vector2f topRight;
		Math::Vector2f topLeft;
		Math::Vector2f bottomLeft;
	};

	struct VertexTexture
	{
		Math::Vector3f position;
		Math::Vector2f texCoord;
	};

	struct VertexInstance
	{
		Math::Vector2f position;
		Math::Vector2f scale;
		Math::Color4f color;
	};

	struct VertexInstanceTexture
	{
		Math::Vector2f position;
		Math::Vector2f scale;
		Math::Color4f color;

		// Texture data
		float textureId;
		TextureClip textureClip;

		// render
		float active;

		float rotation;

		float priority;
	};

	struct Quad 
	{
		Vertex vertices[4];
	};
}