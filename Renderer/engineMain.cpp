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
	std::vector<Vertex> vertices = m_importer.importObj("Torus2");
	Mesh *torusmesh = new Mesh(vertices.data(),vertices.size());
	torusmesh->initBufferFromData();
	vertices = m_importer.importObj("teapot");
	Mesh *teapotmesh = new Mesh(vertices.data(), vertices.size());
	teapotmesh->initBufferFromData();
	vertices = m_importer.importObj("box2");
	Mesh *sphereMesh = new Mesh(vertices.data(), vertices.size());
	sphereMesh->initBufferFromData();
	vertices = m_importer.importObj("plane");
	Mesh *planeMesh = new Mesh(vertices.data(), vertices.size());
	planeMesh->initBufferFromData();

	GameObject *terrain= new GameObject(planeMesh, glm::vec3(0.0f, -2.0f, 0.0f));
	terrain->setProgram(m_handler.createVertAndFragShaderProg("toon", "simple"));

	m_graphics.addRenderable(terrain);


	GameObject *torus = new GameObject(torusmesh, glm::vec3(3.0f, -1.0f, 0.0f));
	torus->setProgram(m_handler.createVertAndFragShaderProg("toon", "simple"));

	GameObject *torus2 = new GameObject(sphereMesh, glm::vec3(5.0f, -1.0f, 6.0f));
	torus2->setProgram(m_handler.createVertAndFragShaderProg("toon", "simple"));

	GameObject *teapot = new GameObject(teapotmesh, glm::vec3(-3.0f, 1.0f, 3.0f));
	teapot->setProgram(m_handler.createVertAndFragShaderProg("toon", "simple"));

	m_updater.addUpdateable(torus);
	m_graphics.addRenderable(torus);
	m_updater.addUpdateable(torus2);
	m_graphics.addRenderable(torus2);
	m_updater.addUpdateable(teapot);
	m_graphics.addRenderable(teapot);
	Camera *camera = new Camera(glm::vec3(3.0f, 3.0f, 0.0f), glm::vec3(-1.0f, -1.0f, 0.0f));
	m_mouseListener.registerMe(&m_graphics);
	m_mouseListener.registerMe(camera);
	m_graphics.setCamera(camera);
	m_keyListener = new KeyListener(camera);
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

		m_keyListener->listenForKeys();
		m_mouseListener.checkMouse();

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