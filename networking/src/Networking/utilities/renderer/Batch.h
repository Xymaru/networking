#pragma once

//#include <Empathy/SimpleTypes.h>
//#include "../Shader.h"
//#include "Empathy/Resources.h"
//#include "../VertexBuffer.h"
//#include "../Color.h"
//
//namespace EM
//{
//	class Batch
//	{
//	public:
//		Batch(u32 maxQuads);
//		~Batch();
//
//		void SetColor(const Color& color);
//
//		void AddQuads(Vertex* vertices, u32 count);
//		void Render();
//		void Clear();
//
//	private:
//		u32 m_VAO = 0, m_VBO = 0, m_EBO = 0;
//		u32 m_MaxQuads = 0;
//		u32 m_MaxIndices = 0;
//		u32 m_UsedQuads = 0;
//
//		ResourceId m_BatchingShaderId = EM_INVALID_RESOURCE;
//		Shader* m_BatchingShader = nullptr;
//
//		u32 m_ColorLocation = 0;
//		u32 m_ModelLocation = 0;
//
//		Color m_Color{};
//
//		glm::vec4 m_gl_Color;
//	};
//}