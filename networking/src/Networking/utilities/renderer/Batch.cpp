//#include <empch.h>
//#include "Batch.h"
//#include <Empathy/Renderer2D.h>
//#include <Empathy/Application.h>
//#include <Empathy/Window.h>
//
//EM::Batch::Batch(u32 maxQuads)
//	:	m_MaxQuads(maxQuads),
//		m_UsedQuads(0)
//{
//	m_Color = { 0, 0, 0, 255 };
//	m_gl_Color = { 0.0f, 0.0f, 0.0f, 1.0f };
//
//	m_BatchingShader = new Shader();
//	m_BatchingShader->Init("../Assets/Resources/Shaders/colorShader");
//
//	m_ColorLocation = m_BatchingShader->getUniformLocation("u_Color");
//	m_ModelLocation = m_BatchingShader->getUniformLocation("u_Model");
//
//	glGenBuffers(1, &m_VBO);
//	glGenBuffers(1, &m_EBO);
//	glGenVertexArrays(1, &m_VAO);
//
//	glBindVertexArray(m_VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * maxQuads * 4, nullptr, GL_DYNAMIC_DRAW);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
//
//	m_MaxIndices = maxQuads * 6;
//
//	unsigned int* indexes = new unsigned int[m_MaxIndices];
//
//	int offset = 0;
//	for (u32 i = 0; i < m_MaxIndices; i += 6) {
//		indexes[i + 0] = 0 + offset;
//		indexes[i + 1] = 1 + offset;
//		indexes[i + 2] = 3 + offset;
//
//		indexes[i + 3] = 1 + offset;
//		indexes[i + 4] = 2 + offset;
//		indexes[i + 5] = 3 + offset;
//
//		offset += 4;
//	}
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_MaxIndices, indexes, GL_STATIC_DRAW);
//
//	delete[] indexes;
//}
//
//EM::Batch::~Batch()
//{
//}
//
//void EM::Batch::SetColor(const Color& color)
//{
//	m_Color = color;
//	m_gl_Color = glm::vec4(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha / 255.0f);
//}
//
//void EM::Batch::AddQuads(Vertex * vertices, u32 count)
//{
//	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//	glBufferSubData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_UsedQuads * 4, sizeof(Vertex) * 4 * count, vertices);
//
//	m_UsedQuads += count;
//}
//
//void EM::Batch::Render()
//{
//	if (!m_UsedQuads) return;
//
//	Window* window = Application::GetInstance()->window;
//
//	SDL_Rect rect = { 0, 0, 32, 32 };
//	Renderer2D::Pivot pivot = Renderer2D::Pivot::DOWN_LEFT;
//
//	m_BatchingShader->Bind();
//
//	m_BatchingShader->setUniform(m_ColorLocation, m_gl_Color);
//
//	Vector2f screen_pos_gl = Application::GetInstance()->renderer2D->CalculateScreenGlPos(rect, pivot);
//
//	Size2i screen_scale = { rect.w, rect.h };
//	Size2f screen_scale_gl = window->screenSizeToGl(screen_scale);
//
//	glm::mat4 model = glm::mat4(1.0f);
//	model = glm::translate(model, glm::vec3(screen_pos_gl.x, screen_pos_gl.y, 0.0f));
//	model = glm::scale(model, glm::vec3(screen_scale_gl.x, screen_scale_gl.y, 0.0f));
//
//	m_BatchingShader->setUniform(m_ModelLocation, model);
//
//	glBindVertexArray(m_VAO);
//	glDrawElements(GL_TRIANGLES, m_UsedQuads * 6, GL_UNSIGNED_INT, 0);
//}
//
//void EM::Batch::Clear()
//{
//	m_UsedQuads = 0;
//}