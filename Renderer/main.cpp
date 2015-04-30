#include <iostream>
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include "shaderHandler.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
int main(int argc, char **argv)
{
	std::cout << "I will be your debug window" << std::endl;
	
	
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		800, 600, SDL_WINDOW_OPENGL);	

	SDL_GLContext context = SDL_GL_CreateContext(window);

	GLint glewInitResult = glewInit();
	if (GLEW_OK != glewInitResult)
	{
		std::cout << "Error: couldn't init glew: " << glewGetErrorString(glewInitResult) << std::endl;
		system("PAUSE");


		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//----------------setUp
	GLfloat verts[] = {
		-.5f, -.5f, 0.0f,
		.5f, -.5f, 0.0f,
		0.0f, .5f, 0.0f
	};
	GLfloat colors[] = {
		1.0f, 1.0f, .5f,
		.8f, .5f, .5f,
		.3f, .5f, .7f
	};
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts[0]) * 3 * 3, verts, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors[0]) * 3 * 3, colors, GL_STATIC_DRAW);

	GLuint vaoHandle;
	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)NULL);

	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0, 2.0, 4.0),   // eye
		glm::vec3(0.0, 0.0, 0.0),   // direction
		glm::vec3(0.0, 1.0, 0.0));  // up
	glm::mat4 projection = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	//----------------mainLoop
	bool running = true;
	SDL_Event event;

	ShaderHandler handler;
	GLuint program = handler.createVertAndFragShaderProg("simple", "simple");
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		GLint viewLoc = glGetUniformLocation(program, "viewMatrix");
		GLint projLoc = glGetUniformLocation(program, "perspectiveMatrix");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); 
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(vaoHandle);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	system("PAUSE");
	return 0;
}