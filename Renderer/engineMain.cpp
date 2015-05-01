#include "engineMain.h"


EngineMain::EngineMain(const int width, const int height, const char const *title) : m_graphics(width, height, title)
{
}


EngineMain::~EngineMain()
{
}

void EngineMain::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	if (!m_graphics.setUp())
	{
		cleanUp();
	}
	std::vector<Vertex> vertices = m_importer.importObj("box2");
	Mesh *mesh = new Mesh(vertices.data(),vertices.size());
	mesh->initBufferFromData();
	GameObject *cube = new GameObject(mesh);
	cube->setProgram(m_handler.createVertAndFragShaderProg("simple", "simple"));
	m_updater.addUpdateable(cube);
	m_graphics.addRenderable(cube);
	mainLoop();
}

void EngineMain::cleanUp()
{
	m_graphics.cleanUp();
	SDL_Quit();
}


void EngineMain::mainLoop()
{
	bool running = true;
	SDL_Event event;
	unsigned int now = SDL_GetTicks();
	unsigned int before = SDL_GetTicks();
	unsigned int delta = 0;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		now = SDL_GetTicks();
		delta = now - before;
		while (delta < 1000 / 60)
		{
			m_graphics.render();
			now = SDL_GetTicks();
			delta = now - before;
		}
		m_updater.update(delta);
		before = now;
	}
	cleanUp();
}