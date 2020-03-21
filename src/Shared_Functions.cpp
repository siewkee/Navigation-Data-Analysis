#include "A02_header.h"

vector <ShapeTwoD*> shapes_global;

void choice_one(int counter)
{
    cout << "\n[Input sensor data]" << endl;
    
    cout << "Please enter name of shape: ";
    string shape_name;
    cin >> shape_name;
    
    cout << "Please enter special type: ";
    string shape_type;
    cin >> shape_type;
    
    int size = shapes_global.size();
    
    bool WS_check = false;
    if (shape_type == "NS") 
		     WS_check = false;
    
    if (shape_name == "Cross")
    	shapes_global.push_back(new Cross(shape_name, WS_check));
    else if (shape_name == "Square")
    	shapes_global.push_back(new Square(shape_name, WS_check));	
    else if (shape_name == "Rectangle")
    	shapes_global.push_back(new Rectangle(shape_name, WS_check));
    else if (shape_name == "Circle")
    	shapes_global.push_back(new Circle(shape_name, WS_check));
    	
    if (shape_name == "Cross" | shape_name == "Square" | shape_name == "Rectangle")
    {
    	int loop_coord_input = shapes_global.back()->get_numOfVertices();
   
      for (int i = 0; i < loop_coord_input; i++)
		 {
			  int x = 0;
			  int y = 0;
			  
			  cout << "Please enter x-ordinate of pt. " << i + 1 << ": ";
			  cin >> x;
			  cout << "Please enter y-ordinate of pt. " << i + 1 << ": ";
			  cin >> y;
		  
			  //llround(x);
			  //llround(y);
			  
			  Points temp;
			  temp.x = x;
			  temp.y = y;
			  temp.pos = Vertices;
			  
		 	  shapes_global.back()->addVertices_toArray(temp);
			  
		  }	
    }
    else if (shape_name == "Circle")
    {
    	int x = 0;
    	int y = 0;
    	int radius = 0;
    	
		cout << "Please enter x-ordinate of center: ";
		cin >> x;	  
		cout << "Please enter y-ordinate of center: ";
		cin >> y;
		cout << "Please enter radius (units): ";
	   cin >> radius;
	   
		Points center = Points{x, y};
		
		shapes_global.back()->setRadius(radius);
		shapes_global.back()->set_CenterPoints(center);
	}	
			
    cout << "Record successfully stored. Going back to main menu ..." << endl;
}

void choice_two()
{
	for (ShapeTwoD* d : shapes_global)
		d->setArea();
	
	int size = shapes_global.size();
	cout << "Computation completed! ( " << size << "records were updated)\n" << endl; 
}

void choice_three()
{
	int size = shapes_global.size();
	
	cout << "Total records available = " << size << "/n" << endl;

	for (ShapeTwoD* d : shapes_global)
	{
		d->draw_Shape();
		string print = d->toString();
		cout << print << endl;
	}	
}





















