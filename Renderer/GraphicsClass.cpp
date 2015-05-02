#include "GraphicsClass.h"


GraphicsClass::GraphicsClass(const int width, const int height, const char const *title) : m_iWidth(width), m_iHeight(height), m_cTitle(title)
{
	m_pWindow = nullptr;
	m_context = NULL;
	m_pCurrentCamera = nullptr;
}


GraphicsClass::~GraphicsClass()
{
}

void GraphicsClass::setCamera(Camera *camera)
{
	m_pCurrentCamera = camera;
}

bool GraphicsClass::setUp()
{
	m_pWindow = SDL_CreateWindow(m_cTitle,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_iWidth, m_iHeight, SDL_WINDOW_OPENGL);
	if (m_pWindow == nullptr)
	{
		std::cout << "Error: couldn't create window" << std::endl;
		return false;
	}
	m_context = SDL_GL_CreateContext(m_pWindow);
	if (m_context == NULL)
	{
		std::cout << "Error: couldn't create GLContext" << std::endl;
		return false;
	}
	GLint glewInitResult = glewInit();
	if (GLEW_OK != glewInitResult)
	{
		std::cout << "Error: couldn't init glew: " << glewGetErrorString(glewInitResult) << std::endl;
		return false;
	}
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	m_shaderHandler = ShaderHandler();

	m_lightSource = glm::vec3(0.0f, 6.0f, 0.0f);
	return true;
}

void GraphicsClass::cleanUp()
{
	if (m_pCurrentCamera != nullptr)
	{
		delete &m_pCurrentCamera;
	}
	for (int i = 0; i < m_renderVector.size(); ++i)
	{
		m_renderVector[i]->cleanUp();
	}
	m_shaderHandler.cleanUp();
	if (m_context != NULL)
		SDL_GL_DeleteContext(m_context);
	if(m_pWindow != nullptr)
		SDL_DestroyWindow(m_pWindow);
}


void GraphicsClass::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < m_renderVector.size(); ++i)
	{
		m_renderVector[i]->render(m_pCurrentCamera, m_lightSource);
	}
	SDL_GL_SwapWindow(m_pWindow);
}

void GraphicsClass::addRenderable(RenderAble *obj)
{
	m_renderVector.push_back(obj);
}

void GraphicsClass::getNotified(int x, int y)
{

}