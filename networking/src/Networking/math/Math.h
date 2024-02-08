#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace EM::Math
{
	// Vectors
	using Vector2f = glm::vec2;
	using Vector2i = glm::ivec2;
	using Vector3i = glm::ivec3;
	using Vector3f = glm::vec3;
	using Vector4i = glm::ivec4;
	using Vector4f = glm::vec4;

	// Colors
	using Color3i = Vector3i;
	using Color3f = Vector3f;
	using Color4f = Vector4f;
	using Color4i = Vector4i;

	// Size
	using Size2i = Vector2i;
	using Size2f = Vector2f;
	using Size3i = Vector3i;
	using Size3f = Vector3f;
	using Size4i = Vector4i;
	using Size4f = Vector4f;

	// Quaternion
	using Quaternion = glm::quat;

	// Matrices
	using Mat2x2 = glm::mat2x2;
	using Mat3x3 = glm::mat3x3;
	using Mat4x4 = glm::mat4x4;

	struct Rectangle
	{
		Vector2f Position;
		Size2f Size;
	};
}