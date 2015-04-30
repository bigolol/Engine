#include "GraphicsClass.h"


GraphicsClass::GraphicsClass(int width, int height, char *title) : m_iWidth(width), m_iHeight(height), m_cTitle(title)
{
	m_pWindow = nullptr;
	m_context = NULL;
}


GraphicsClass::~GraphicsClass()
{
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
	return true;
}

void GraphicsClass::cleanUp()
{
	if (m_context != NULL)
		SDL_GL_DeleteContext(m_context);
	if(m_pWindow != nullptr)
		SDL_DestroyWindow(m_pWindow);
}

void GraphicsClass::render()
{

}