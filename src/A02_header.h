#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

enum Points_Position {Perimeter, Vertices};

struct Points
{
	int x;
	int y;
	Points_Position pos;
};

struct Grid
{
	Points t_left;
	Points t_right;
	Points b_left;
	Points b_right;
};

class ShapeTwoD
{
	public: 
		ShapeTwoD(string name, bool containsWarpSpace);		
		virtual ~ShapeTwoD();

		string getName();
		bool getContainsWarpSpace();
		void setName(string name);
		void setContainsWarpSpace(bool containsWarpSpace);
		
		virtual void setArea();
		virtual int get_numOfVertices();
		virtual void draw_Shape();
		virtual double computeArea();
		virtual bool isPointInShape(int x, int y);
		virtual bool isPointOnShape(int x, int y);
		virtual string toString();
		virtual void addVertices_toArray(Points p);
		virtual void setRadius(int radius);
		virtual void set_CenterPoints(Points p);

	protected:
		string name;
		bool containsWarpSpace;
};

class Cross : public ShapeTwoD
{
	public: 
		Cross(string name, bool containsWarpSpace);			
		~Cross();

		Points start_Point();
		Points draw_verti_upDown(Points draw, string direction);
		Points draw_horiz_rightLeft(Points draw, string direction);
		
		void setArea() override;
		int get_numOfVertices() override;
		void addVertices_toArray(Points p) override;
		void draw_Shape() override;
		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		double computeArea() override;
		string toString() override;
		
	protected:
		string name;
		bool containsWarpSpace;
		int noOfVertices;
		vector<Points> onshape_points;
		vector<Points> inshape_points;
		vector<Points> horiz_inshape_points;
		int area_empty_sq[4];
		int area;
		
};

class Rectangle : public ShapeTwoD
{
	public: 
		Rectangle(string name, bool containsWarpSpace);			
		~Rectangle();

		Points start_Point();
		Points draw_verti_upDown(Points draw, string direction);
		Points draw_horiz_rightLeft(Points draw, string direction);
		
		void setArea() override;
		int get_numOfVertices() override;
		void addVertices_toArray(Points p) override;
		void draw_Shape() override;
		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		double computeArea() override;
		string toString() override;
		
	protected:
		string name;
		bool containsWarpSpace;
		int noOfVertices;
		int area;
		vector<Points> onshape_points;
		vector<Points> inshape_points;
		vector<Points> horiz_inshape_points;
	
};

class Square : public ShapeTwoD
{
	public: 
		Square(string name, bool containsWarpSpace);			
		~Square();

		Points start_Point();
		Points draw_verti_upDown(Points draw, string direction);
		Points draw_horiz_rightLeft(Points draw, string direction);
		
		void setArea() override;
		int get_numOfVertices() override;
		void addVertices_toArray(Points p) override;
		void draw_Shape() override;
		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		double computeArea() override;
		string toString() override;
		
	protected:
		string name;
		bool containsWarpSpace;
		int noOfVertices;
		vector<Points> onshape_points;
		vector<Points> inshape_points;
		vector<Points> horiz_inshape_points;
		int area;
};

class Circle : public ShapeTwoD
{
	public: 
		Circle(string name, bool containsWarpSpace);			
		~Circle();
		
		void setArea() override;
		void setRadius(int radius) override;
		void set_CenterPoints(Points p) override;
		void draw_Shape() override;
		string toString() override;
		double computeArea() override;
		bool isPointInShape(int x, int y) override;
		bool isPointOnShape(int x, int y) override;
		
	protected:
		string name;
		bool containsWarpSpace;
		int radius;
		Points center;
		vector<Points> onshape_points;
		vector<Points> inshape_points;
		int area;
		
};


//shared functions
void choice_one(int);
void choice_two();
void choice_three();






