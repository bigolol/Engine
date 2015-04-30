#pragma once
#include <GL\glew.h>
#include <string>
#include <iostream>
#include <fstream>	
#include <errno.h>

class ShaderHandler
{
public:
	ShaderHandler();
	virtual ~ShaderHandler();
	GLuint createVertAndFragShaderProg(const std::string& pathToVertShader, const std::string& pathToFragShader);
	static GLuint loadAndCompileShader(const std::string& pathToShader, const GLenum shaderType);

private:

public:

private:
};

