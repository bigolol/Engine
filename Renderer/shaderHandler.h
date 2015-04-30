#pragma once
#include <GL\glew.h>
#include <string>
#include <iostream>
#include <fstream>	
#include <errno.h>
#include <vector>
class ShaderHandler
{
public:
	ShaderHandler();
	virtual ~ShaderHandler();
	GLuint createVertAndFragShaderProg(const std::string& vertShaderName, const std::string& fragShaderName);
	void cleanUp();
private:
	GLuint loadAndCompileShader(const std::string& pathToShader, const GLenum shaderType) const;
	bool checkForGLErrors() const;
public:

private:
	std::vector<GLuint> m_vPrograms;
};

