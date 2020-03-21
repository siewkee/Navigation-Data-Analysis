#include "A02_header.h"

Circle::Circle(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
 	
}

Circle::~Circle()
{

}

void Circle::setRadius(int radius)
{
	this -> radius = radius;
}

void Circle::set_CenterPoints(Points p)
{
	this->center = p;
}

void Circle::draw_Shape()
{	
	//idenity points of the overall sqaure that the shape occupies 
	//iterate and check if points are on shape or in shape
	int max_x = center.x + radius;
	int min_x = center.x - radius;
	
	int max_y = center.y + radius;
	int min_y = center.y - radius;
	
	for (int i = min_x; i <= max_x; i++)
	{
		for (int j = min_y; j <= max_y; j++)
		{
			bool check_onshape = isPointOnShape(i, j);
			if (check_onshape)
				onshape_points.push_back(Points{i, j});
				
			bool check_inshape = isPointInShape(i, j);
			if (check_inshape)
				inshape_points.push_back(Points{i, j});
		}
	}
	
}

bool Circle::isPointInShape(int x, int y)
{
	if ((pow((x - center.x), 2) + pow((y - center.y), 2)) 
			< pow(radius, 2)) 
		return true;
	else 
		return false;
}

bool Circle::isPointOnShape(int x, int y)
{
	bool check = false;
	
	int top_verti = center.y + this->radius;
	int bottom_verti = center.y - this->radius;
	int left_verti = center.x - this->radius;
	int right_verti = center.x + this->radius;
	
	if ((x == center.x && y == top_verti)
		|(x == center.x && y == bottom_verti)
		|(y == center.y && x == left_verti)
		|(y == center.y && x == right_verti))
		check = true;
	
	return check;
}

double Circle::computeArea()
{
	 double area = 3.141 * pow(radius, 2);
    return area;
}

void Circle::setArea()
{
	 this->area = computeArea();
}


string Circle::toString()
{
	//name and type info
	string cir;
	
	cir = ShapeTwoD::toString();
	
	//other shape info
	cir += "\nArea: " + to_string((int)this->area) + " units square";
	
	cir += "\n\nPoints on perimeter : ";
	for(Points p : onshape_points)
		cir += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";

 
	cir += "\n\nPoint within shape: ";
	for (Points p : inshape_points)
		cir += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";

	cir += "\n";
	
	return cir;
    
}






















