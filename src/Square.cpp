#include "A02_header.h"

Square::Square(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
    this->noOfVertices = 4;
}

Square::~Square()
{

}

int Square::get_numOfVertices()
{
	return this->noOfVertices;
}

void Square::addVertices_toArray(Points p)
{
    this->onshape_points.push_back(p);
}

Points Square::start_Point()
{
    Points to_Return = this->onshape_points[0];
    
    //find smallest x value
    int min_x = this->onshape_points[0].x;
    
    for (Points p : this->onshape_points)
    {
        if(min_x > p.x)
            min_x = p.x;
    }
    
    //find smallest y value in all points with smallest x value
    int min_y = this->onshape_points[0].y;
    
    for (Points p : this->onshape_points)
    {
        if (p.x == min_x)
        {
            if (min_y > p.y)
            {
                min_y = p.y;
                to_Return = p;
            }
        }
    }
    
    return to_Return;
}

void Square::draw_Shape()
{
    //tracing points on shape by "drawing" the shape
    
    //tracing points in shape by duplicating the horizontal points on shape along y axis
    

    //function call to identiy on_shape points and calculate area of non-occupied square
    //starting point always smallest x and smallest y value with the identified smallest x
    Points draw = start_Point();
    
    //going upwards from starting point
    //storing perimeters as the drawing continues
    draw = draw_verti_upDown(draw, "up");
    
    //going right from the last vertex
    //storing perimeters as the drawing continues
    draw = draw_horiz_rightLeft(draw, "right");
    
    //going downwards from last vertex
    //storing perimeters as the drawing continues
    //x and y values are used to calculate area of non-occupied squares seperately
    draw = draw_verti_upDown(draw, "down");

    //going left from the last vertex
    //storing perimeters as the drawing continues
	 //x and y values are used to calculate area of non-occupied squares seperately
    this->horiz_inshape_points.push_back(draw);
    draw = draw_horiz_rightLeft(draw, "left");
    this->horiz_inshape_points.push_back(draw);
    

    //function call to identiy in_shape points
    for (Points p : this->horiz_inshape_points)
    {
        bool check_onShape = false;
        int x = p.x;
        int y = p.y;
        while (check_onShape == false)
        {
            y += 1;
            check_onShape = isPointOnShape(x, y);
            if (!check_onShape)
                this->inshape_points.push_back(Points{x, y});
        }
    }
    
}

Points Square::draw_verti_upDown(Points draw, string direction)
{
    //going upwards vertically from starting point (increment of y value)
    // or going downwards vertically from starting point (decrement of y value)
    //check if points are vertices
    //true: change direction, false: continue in same direction
    bool present = false;
    
    present = isPointOnShape(draw.x, draw.y);
    if (present == false)
    {
        Points to_store = Points{draw.x, draw.y, Perimeter};
        this->onshape_points.push_back(to_store);
    }
    
    present = false;
    
    do
    {
        if (direction == "up")
            draw.y += 1;
        else
            draw.y -= 1;
        
        present = isPointOnShape(draw.x, draw.y);
        if (present == false)
        {
            Points to_store = Points{draw.x, draw.y, Perimeter};
            this->onshape_points.push_back(to_store);
        }
    }while(present == false);
    
    return draw;
}

Points Square::draw_horiz_rightLeft(Points draw, string direction)
{
    //going right horizontally from starting point (increment of x value)
    // or going left horizontally from starting point (decrement of x value)
    //check if points are vertices
    //true: change direction, false: continue in same direction
    bool present = false;
    
    present = isPointOnShape(draw.x, draw.y);
    if (present == false)
    {
        Points to_store = Points{draw.x, draw.y, Perimeter};
        this->onshape_points.push_back(to_store);
        if (direction == "left")
            this->horiz_inshape_points.push_back(to_store);
    }
    
    present = false;
    
    do
    {
        if (direction == "right")
            draw.x += 1;
        else
            draw.x -= 1;
        
        present = isPointOnShape(draw.x, draw.y);
        if (present == false)
        {
            Points to_store = Points{draw.x, draw.y, Perimeter};
            this->onshape_points.push_back(to_store);
            if (direction == "left")
                this->horiz_inshape_points.push_back(to_store);
        }
    }while(present == false);
    
    
    return draw;
}

bool Square::isPointOnShape(int x, int y)
{
    //reduces complexity using while instead of for loop
    bool present = false;
    int i = 0;
    int size = onshape_points.size();
    
    while (present == false && i < size)
    {
        if (this->onshape_points[i].x == x && this->onshape_points[i].y == y)
            present = true;
        i++;
    }
    
    return present;
}


bool Square::isPointInShape(int x, int y)
{
    //check if parameters are aligned with any of the x and y values of all perimeter and vertices points
    int index = onshape_points.size() - 1;
    bool present_x = false;
    bool present_y = false;
    
    while(present_x == false | present_y == false)
    {
        if (onshape_points[index].x == x)
            present_x = true;
        if (onshape_points[index].y == y)
            present_x = true;
        index--;
        if (index < 0)
            break;
    }
    
    //if aligned, check if the parameters are a pair of vertex or perimeter points
    if (present_x == true && present_y == true)
    {
        bool check_onshape = isPointOnShape(x, y);
        if (check_onshape == true)
            return false;
        else
            return true;
    }
    else
        return false;
    
}

double Square::computeArea()
{
    //calculate max and min x
    //calculate max and min y
    //calculate area of the overall sqaure
    
    int max_x = onshape_points[0].x;
    int min_x = onshape_points[0].x;
    int max_y = onshape_points[0].y;
    int min_y = onshape_points[0].y;
    
    for (Points p : onshape_points)
    {
    	if (max_x < p.x)
    		max_x = p.x;
    	if (min_x > p.x)
    		min_x = p.x;
    		
    	if (max_y < p.y)
    		max_y = p.y;
    	if (min_y > p.y)
    		min_y = p.y;
    }
    
    int length = max_x - min_x;
    int breadth = max_y - min_y;
    
    int area = length * breadth;
    
    //calculate area

    return area;
}

void Square::setArea()
{
	 this->area = computeArea();
}

string Square::toString()
{
	//name and type info
	string Square;
	
	Square = ShapeTwoD::toString();

	//other shape info
	Square += "\nArea: " + to_string((int)this->area) + " units square \nVertices: \n";
	int counter = 0;
	
	for(Points p : onshape_points)
	{
		if (p.pos == Vertices)
		{
			Square += "Point [" + to_string(counter) + "] : (" + to_string(p.x) + ", " + to_string(p.y) + ") \n";
			counter++;
		}
	}
	
	Square += "\nPoints on perimeter : ";
	for(Points p : onshape_points)
	{
		if (p.pos == Perimeter)
			Square += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";
	
	}
 
	Square += "\n\nPoint within shape: ";
	for (Points p : inshape_points)
	{
		Square += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";
	}

	Square += "\n";
	
	return Square;
    
}



