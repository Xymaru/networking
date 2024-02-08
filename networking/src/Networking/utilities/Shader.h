#pragma once

#include <string>
#include <typeinfo>

#include <sdl2/SDL.h>
#include "glew/gl/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "sdl2/SDL_opengl.h"

#include "Networking/Debug.h"

namespace EM {
	class Shader
	{
	public:
		Shader();
		~Shader();

		enum State {
			Vertex
		};

		void Init(const GLchar* filename);
		GLuint getID() { return m_IDprogram; }
		void Bind() { glUseProgram(m_IDprogram); }
		void UnBind() { glUseProgram(0); }
		void Delete() { glDeleteProgram(m_IDprogram); }

		bool getAllOk() { return m_AllOk; }

		unsigned int getUniformLocation(const char* uniform_name);

		template<class T> void setUniform(unsigned int uniform_id, T value);
	private:
		std::string* getFileData(const char* file);
		GLuint m_IDprogram;
		bool m_AllOk;
	};

	template<>
	inline void Shader::setUniform<glm::mat4>(unsigned int uniform_id, glm::mat4 value) {
		glUseProgram(m_IDprogram);
		glUniformMatrix4fv(uniform_id, 1, GL_FALSE, glm::value_ptr(value));
	}

	template<>
	inline void Shader::setUniform<float>(unsigned int uniform_id, float value) {
		glUseProgram(m_IDprogram);
		glUniform1f(uniform_id, value);
	}

	template<>
	inline void Shader::setUniform<glm::vec3>(unsigned int uniform_id, glm::vec3 value) {
		glUseProgram(m_IDprogram);
		glUniform3f(uniform_id, value.x, value.y, value.z);
	}

	template<>
	inline void Shader::setUniform<glm::vec4>(unsigned int uniform_id, glm::vec4 value) {
		glUseProgram(m_IDprogram);
		glUniform4f(uniform_id, value.r, value.g, value.b, value.a);
	}

	template<class T>
	inline void Shader::setUniform(unsigned int uniform_id, T value)
	{
		Debug::getInstance()->LogError("Uniform loading", "Setting uniform of a non existant specialization.");
	}
}
