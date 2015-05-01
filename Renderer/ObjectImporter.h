#pragma once
#include "vertex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class ObjectImporter
{
public:
	ObjectImporter();
	virtual ~ObjectImporter();
	std::vector<Vertex> importObj(std::string objFileName);
		
private:

public:

private:

};

