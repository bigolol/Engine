#include "shaderHandler.h"


ShaderHandler::ShaderHandler()
{
}


ShaderHandler::~ShaderHandler()
{
}

GLuint ShaderHandler::loadAndCompileShader(const std::string& pathToShader, const GLenum shaderType) const
{
	std::cout << "Compiling: " << pathToShader << std::endl;
	
	std::ifstream shaderFileStream;
	shaderFileStream.open(pathToShader);
	char errorString[1024];
	if (errno != 0)
	{
		strerror_s(errorString, errno);
		std::cout << "Error: " << errorString << " while trying to open: " << pathToShader << std::endl;
	}
	std::string shaderCode;
	std::string line;
	if (shaderFileStream.is_open())
	{
		while (!shaderFileStream.eof())
		{
			std::getline(shaderFileStream, line);
			shaderCode.append(line + '\n');
		}
	}
	std::cout << shaderCode << std::endl;

	const char *shaderCodeGL = shaderCode.c_str();
	GLuint shaderObject = glCreateShader(shaderType);
	glShaderSource(shaderObject, 1, &shaderCodeGL, NULL);
	glCompileShader(shaderObject);

	GLint isCompiled = 0;
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		GLchar errorLog[1024];
		glGetShaderInfoLog(shaderObject, maxLength, &maxLength, &errorLog[0]);

		std::cout << "Error while compiling shader: " << pathToShader << errorLog << std::endl;
		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(shaderObject); // Don't leak the shader.
		return 0;
	}
	std::cout << "compilation succesful" << std::endl;
	return shaderObject;
}

GLuint ShaderHandler::createVertAndFragShaderProg(const std::string& vertShaderName, const std::string& fragShaderName)
{
	std::cout << "making program: " << vertShaderName << " & " << fragShaderName << std::endl;
	GLuint vertexShader = loadAndCompileShader("../Resources/shaders/" + vertShaderName + ".vs", GL_VERTEX_SHADER);
	if (vertexShader == 0)
	{
		std::cout << "Error while making vshader" << std::endl;
		return 0;
	}
	GLuint fragShader = loadAndCompileShader("../Resources/shaders/" + fragShaderName + ".frags", GL_FRAGMENT_SHADER);
	if (fragShader == 0)
	{
		std::cout << "Error while making fshader" << std::endl;
		glDeleteShader(vertexShader);
		return 0;
	}
	GLenum program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		GLchar errorLog[1024];
		glGetProgramInfoLog(program, maxLength, &maxLength, &errorLog[0]);

		std::cout << "Error while compiling program: " << errorLog << std::endl;
		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(vertexShader); // Don't leak the shader.
		glDeleteShader(fragShader);
		glDeleteProgram(program);
		return 0;
	}
	glDeleteShader(vertexShader); 
	glDeleteShader(fragShader);
	m_vPrograms.push_back(program);
	return program;
}



bool ShaderHandler::checkForGLErrors() const
{
	bool noError = true;
	GLenum glErr = glGetError();
	while (glErr != GL_NO_ERROR)
	{
		std::cout << "GLError: " << glewGetErrorString(glErr);
		glErr = glGetError();
		noError = false;
	}
	return noError;
}

void ShaderHandler::cleanUp()
{
	for (int i = 0; i < m_vPrograms.size(); i++)
	{
		glDeleteProgram(m_vPrograms[i]);
	}
}