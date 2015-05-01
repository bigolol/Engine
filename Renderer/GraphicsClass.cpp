#include "GraphicsClass.h"


GraphicsClass::GraphicsClass(const int width, const int height, const char const *title) : m_iWidth(width), m_iHeight(height), m_cTitle(title)
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


	m_shaderHandler = ShaderHandler();

	Vertex positions[] = {
		Vertex(glm::vec3(-.5f, -.5f, 0.0f)),
		Vertex(glm::vec3(.5f, -.5f, 0.0f)),
		Vertex(glm::vec3(-.5f, .5f, 0.0f)),
		Vertex(glm::vec3(0.5f, .5f, 0.0f))
	};
	GLushort elements[] = {
		0, 1, 2,
		1, 2, 3
	};
	for (int i = 0; i < 4; i++)
	{
		positions[i].addColorData(glm::vec3(1.0f, 0.0f, 0.0f));
	}
	Mesh *mesh = new Mesh(positions, 4);
	mesh->initBufferFromData();
	mesh->bindElementArray(elements, 3 * 2);
	mesh->setProgram(m_shaderHandler.createVertAndFragShaderProg("simple", "simple"));
	addMesh(mesh);
	return true;
}

void GraphicsClass::cleanUp()
{
	
	m_shaderHandler.cleanUp();
	if (m_context != NULL)
		SDL_GL_DeleteContext(m_context);
	if(m_pWindow != nullptr)
		SDL_DestroyWindow(m_pWindow);
}


void GraphicsClass::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < m_meshVector.size(); ++i)
	{
		glUseProgram(m_meshVector[i]->getProgram());
		glBindVertexArray(m_meshVector[i]->getVAOHandle());
		glDrawElements(GL_TRIANGLE_STRIP, m_meshVector[i]->getNumElements(), GL_UNSIGNED_SHORT, NULL);
		glBindVertexArray(0);
		glUseProgram(0);
	}
	SDL_GL_SwapWindow(m_pWindow);
}

void GraphicsClass::addMesh(Mesh *mesh)
{
	m_meshVector.push_back(mesh);
}
