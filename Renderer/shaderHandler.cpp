#include "shaderHandler.h"


ShaderHandler::ShaderHandler()
{
}


ShaderHandler::~ShaderHandler()
{
}

GLuint ShaderHandler::loadAndCompileShader(const std::string& pathToShader, const GLenum shaderType)
{
	char errorString[1024];
	std::ifstream shaderFileStream;
	shaderFileStream.open(pathToShader);
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
			shaderCode.append(line);
		}
	}

	GLuint shaderObject = glCreateShader(shaderType);

	return shaderObject;

}