#include <iostream>
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include "shaderHandler.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include "engineMain.h"
int main(int argc, char **argv)
{
	std::cout << "I will be your debug window" << std::endl;

	EngineMain engine(800, 600, "title");
	engine.init();

	
	system("PAUSE");
	return 0;
}