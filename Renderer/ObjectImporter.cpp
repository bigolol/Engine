#include "ObjectImporter.h"


ObjectImporter::ObjectImporter()
{
}


ObjectImporter::~ObjectImporter()
{
}


std::vector<Vertex> ObjectImporter::importObj(std::string objFileName)
{
	std::cout << "trying to parse " << objFileName << std::endl;
	std::string pathToObject = "../Resources/objects/" + objFileName + ".obj";
	std::ifstream objFileStream;
	objFileStream.open(pathToObject);
	
	char errorString[1024];
	if (errno != 0)
	{
		strerror_s(errorString, errno);
		std::cout << "Error: " << errorString << " while trying to open: " << pathToObject << std::endl;
	}
	std::vector<glm::vec3> vertPosVec;
	std::vector<glm::vec3> vertNormsVec;
	std::vector<glm::vec3> vertColorVec;
	std::vector<glm::vec2> vertTextureVec;
	std::vector<Vertex> vertexVec;
	std::string currentLine;
	while (!objFileStream.eof())
	{
		std::getline(objFileStream, currentLine);
		if (currentLine.length() > 0 && currentLine.at(0) != '#')
		{
			switch (currentLine.at(0))
			{
			case 'v':
				//get the vertices
				if (currentLine.at(1) == ' ')
				{
					float vertPos[3];
					
					int position = 2;
					for (int i = 0; i < 3; ++i)
					{
						std::string currentFloat;
						while (currentLine.at(position++) == ' ');
						position--;
						while (position < currentLine.length() && currentLine.at(position) != ' ')
							currentFloat += currentLine.at(position++);
						vertPos[i] = std::atof(currentFloat.c_str());						
					}
					vertPosVec.push_back(glm::vec3(vertPos[0], vertPos[1], vertPos[2]));
				}
				else if (currentLine.at(1) == 'n')
				{
					float vertPos[3];

					int position = 2;
					for (int i = 0; i < 3; ++i)
					{
						std::string currentFloat;
						while (currentLine.at(position++) == ' ');
						position--;
						while (position < currentLine.length() && currentLine.at(position) != ' ')
							currentFloat += currentLine.at(position++);
						vertPos[i] = std::atof(currentFloat.c_str());
					}
					vertNormsVec.push_back(glm::vec3(vertPos[0], vertPos[1], vertPos[2]));
				}
				else if (currentLine.at(1) == 't')
				{
					float vertPos[2];

					int position = 2;
					for (int i = 0; i < 2; ++i)
					{
						std::string currentFloat;
						while (currentLine.at(position++) == ' ');
						position--;
						while (position < currentLine.length() && currentLine.at(position) != ' ')
							currentFloat += currentLine.at(position++);
						vertPos[i] = std::atof(currentFloat.c_str());
					}
					vertTextureVec.push_back(glm::vec2(vertPos[0], vertPos[1]));
				}
				break;
			case 'f':
				int position = 1;
				for (int numVertex = 0; position < currentLine.length(); ++numVertex)
				{
					int vertInds[3];
					while (currentLine.at(position++) == ' ');
					position--;
					for (int i = 0; i < 3; ++i)
					{
						std::string currentInt;
						while (position < currentLine.length() && currentLine.at(position) != '/' && currentLine.at(position) != ' ')
						{
							currentInt += currentLine.at(position++);
						}
						vertInds[i] = std::atoi(currentInt.c_str());
						position++;
					}
					Vertex currentVertex(vertPosVec[vertInds[0] - 1]);
					currentVertex.addTexData(vertTextureVec[vertInds[1] - 1]);
					currentVertex.addNormalData(vertNormsVec[vertInds[2] - 1]);
					currentVertex.addColorData(glm::vec3(.5f, .5f, .5f));
					vertexVec.push_back(currentVertex);
				}
			}
		}		

	}
	return vertexVec;

}
