#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
namespace Boba
{
	void OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::ifstream vertexFileStream{ vertexFile };
		std::stringstream vertexStringStream;
		vertexStringStream << vertexFileStream.rdbuf();
		std::string vertexCode{ vertexStringStream.str() };
		const char* cVertexCode{ vertexCode.c_str() };
		vertexFileStream.close();
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertexCode, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		std::ifstream fragmentFileStream{ fragmentFile };
		std::stringstream fragmentStringStream;
		fragmentStringStream << fragmentFileStream.rdbuf();
		std::string fragmentCode{ fragmentStringStream.str() };
		const char* cFagmentCode{ fragmentCode.c_str() };
		fragmentFileStream.close(); 

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cFagmentCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		if (bShaderProgram != 0) {
			glDeleteProgram(bShaderProgram);
		}

		bShaderProgram = glCreateProgram();
		glAttachShader(bShaderProgram, vertexShader);
		glAttachShader(bShaderProgram, fragmentShader);
		glLinkProgram(bShaderProgram);

		glGetProgramiv(bShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(bShaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	void OpenGLShader::Use()
	{
		glUseProgram(bShaderProgram);
	}
}