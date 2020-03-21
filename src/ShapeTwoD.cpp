
#include "A02_header.h"

ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
	this->name = name;
	this->containsWarpSpace = containsWarpSpace;
}

ShapeTwoD::~ShapeTwoD()
{
	//destructor
}

string ShapeTwoD::getName()
{
	return this->name;
}

bool ShapeTwoD::getContainsWarpSpace()
{
	return this->containsWarpSpace;
}

void ShapeTwoD::setName(string name)
{
	this->name = name; 
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}

void ShapeTwoD::draw_Shape()
{
	
}


bool ShapeTwoD::isPointOnShape(int x, int y)
{
	return false;
}

bool ShapeTwoD::isPointInShape(int x, int y)
{
	return false;
}

double ShapeTwoD::computeArea()
{
	return 0;
}

void ShapeTwoD::addVertices_toArray(Points p)
{
	
}

int ShapeTwoD::get_numOfVertices()
{
	return 0;
}

void ShapeTwoD::setRadius(int radius)
{
	
}

void ShapeTwoD::set_CenterPoints(Points p)
{
}


void ShapeTwoD::setArea()
{

}

string ShapeTwoD::toString()
{
	string name = "Name: " + getName();
	
	string type;
	if (containsWarpSpace)
		type = "Special Type: WS";
	else
		type = "Special Type: NS";
		
	return name + "\n" + type;
}






