#include "A02_header.h"

Cross::Cross(string name, bool containsWarpSpace) : ShapeTwoD(name, containsWarpSpace)
{
    this->noOfVertices = 12;
}

Cross::~Cross()
{

}

int Cross::get_numOfVertices()
{
	return this->noOfVertices;
}

void Cross::addVertices_toArray(Points p)
{
    this->onshape_points.push_back(p);
}

Points Cross::start_Point()
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

void Cross::draw_Shape()
{
    //tracing points on shape by "drawing" the shape
    
    //tracing points in shape by duplicating the horizontal points on shape along y axis
    
    //calculate area by subtracting the non-occupied points 
	 //from the overall sqaure that the shape occupies
	
	

    //function call to identiy on_shape points and calculate area of non-occupied square
    //starting point always smallest x and smallest y value with the identified smallest x
    Points draw = start_Point();
    
    //going upwards from starting point
    //storing perimeters as the drawing continues
    draw = draw_verti_upDown(draw, "up");
    
    //going right from the last vertex
    //storing perimeters as the drawing continues
    //x and y values are used to calculate area of non-occupied squares seperately
    int x_1 = draw.x;
    draw = draw_horiz_rightLeft(draw, "right");
    int x_2 = draw.x;
    int y_1 = draw.y;
    
    //going upwards from last vertex
    //storing perimeters as the drawing continues
    draw = draw_verti_upDown(draw, "up");
    int y_2 = draw.y;
    
    //calculate area of top left non-occupied square
    int area = (x_2 - x_1) * (y_2 - y_1);
    area_empty_sq[0] = area;
     
    //going right from the last vertex
    //storing perimeters as the drawing continues
    draw = draw_horiz_rightLeft(draw, "right");
    
    //going downwards from last vertex
    //storing perimeters as the drawing continues
    //x and y values are used to calculate area of non-occupied squares seperately
    y_2 = draw.y;
    draw = draw_verti_upDown(draw, "down");
    y_1 = draw.y;
    x_1 = draw.x;
    
    //going right from the last vertex
    //storing perimeters as the drawing continues
    draw = draw_horiz_rightLeft(draw, "right");
    x_2 = draw.x;
    
    //calculate area of top right non-occupied square
    area = (x_2 - x_1) * (y_2 - y_1);
    area_empty_sq[1] = area;
    
    
    //going downwards from last vertex
    //storing perimeters as the drawing continues
    draw = draw_verti_upDown(draw, "down");
    
    //going left from the last vertex
    //storing perimeters as the drawing continues
	 //x and y values are used to calculate area of non-occupied squares seperately
    this->horiz_inshape_points.push_back(draw);
    x_2 = draw.x;
    draw = draw_horiz_rightLeft(draw, "left");
    this->horiz_inshape_points.push_back(draw);
    x_1 = draw.x;
    y_2 = draw.y;
    
    //going downwards from last vertex
    //storing perimeters as the drawing continues
    draw = draw_verti_upDown(draw, "down");
    y_1 = draw.y;
    
    //calculate area of bottom right non-occupied square
    area = (x_2 - x_1) * (y_2 - y_1);
    area_empty_sq[2] = area;
    
    //going left from the last vertex
    //storing perimeters as the drawing continues
    this->horiz_inshape_points.push_back(draw);
    draw = draw_horiz_rightLeft(draw, "left");
    this->horiz_inshape_points.push_back(draw);
    
    //going upwards from last vertex
    //storing perimeters as the drawing continues
    //x and y values are used to calculate area of non-occupied squares seperately
    y_1 = draw.y;
    draw = draw_verti_upDown(draw, "up");
    y_2 = draw.y;
    x_2 = draw.x;
    
    //going left from the last vertex
    //storing perimeters as the drawing continues
    this->horiz_inshape_points.push_back(draw);
    draw = draw_horiz_rightLeft(draw, "left");
    this->horiz_inshape_points.push_back(draw);
    x_1 = draw.x;
    
    //calculate area of bottom left non-occupied square
    area = (x_2 - x_1) * (y_2 - y_1);
    area_empty_sq[3] = area;
    
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

Points Cross::draw_verti_upDown(Points draw, string direction)
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

Points Cross::draw_horiz_rightLeft(Points draw, string direction)
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

bool Cross::isPointOnShape(int x, int y)
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


bool Cross::isPointInShape(int x, int y)
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

double Cross::computeArea()
{
	//calculate area by subtracting the non-occupied points 
	//from the overall sqaure that the shape occupies
	
	
    //calculate max and min x
    //calculate max and min y
    //calculate area of the overall sqaure
    
    int max_x = this->onshape_points[0].x;
    int min_x = this->onshape_points[0].x;
    int max_y = this->onshape_points[0].y;
    int min_y = this->onshape_points[0].y;
    
    for (Points p : this->onshape_points)
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
    
    int area_overall_sq = length * breadth;
    
    //calculate area
    
    for (int a : area_empty_sq)
    {
    	area_overall_sq -= a;
    }

    return area_overall_sq;
}

void Cross::setArea()
{
	 this->area = computeArea();
}

string Cross::toString()
{
	//name and type info
	string cross;
	
	cross = ShapeTwoD::toString();
	
	//other shape info
	cross += "\nArea: " + to_string((int)this->area) + " units square \nVertices: \n";
	int counter = 0;
	
	for(Points p : onshape_points)
	{
		if (p.pos == Vertices)
		{
			cross += "Point [" + to_string(counter) + "] : (" + to_string(p.x) + ", " + to_string(p.y) + ") \n";
			counter++;
		}
	}
	
	cross += "\n\nPoints on perimeter : ";
	for(Points p : onshape_points)
	{
		if (p.pos == Perimeter)
			cross += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";
	
	}
 
	cross += "\n\nPoint within shape: ";
	for (Points p : inshape_points)
	{
		cross += "(" + to_string(p.x) + ", " + to_string(p.y) + ")  ";
	}

	cross += "\n";
	
	return cross;
    
}






















