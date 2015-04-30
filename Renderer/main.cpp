#include <iostream>
#include <SDL2\SDL.h>
#include <GL\glew.h>
int main(int argc, char **argv)
{
	std::cout << "I will be your debug window" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		800, 600, SDL_WINDOW_OPENGL);

	glewInit();

	SDL_GLContext context = SDL_GL_CreateContext(window);
	glClearColor(0.5f, 0.6f, 0.7f, 1.0f);

	bool running = true;
	SDL_Event event;
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
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	system("PAUSE");
	return 0;
}