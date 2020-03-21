#include "A02_header.h"
 

int main()
{
	int counter = -1;
	
	while (true)
	{
		 cout << "Name: Hung Siew Kee" << endl;
		 cout << "Student ID: 5986606" << endl;
		 cout << "--------------------------" << endl;
		 cout << "Welcome to Assn2 program!" << endl;
		 
		 cout << "1)	Input sensor data" << endl;
		 cout << "2)	Compute area(for all records)" << endl;
		 cout << "3)	Print shapes report" << endl;
		 cout << "4)	Sort shape data" << endl;
		 
		 cout << "\nPlease enter your choice: ";
		 int choice;
		 cin >> choice;

		if (choice == 1)
		{
			choice_one(counter);
			counter += 1;
			cout << "counter" << counter << endl;
		}
		else if (choice == 2)
			choice_two();
		else if (choice == 3)
			choice_three();
		else
			break;
			
	}
	
}
