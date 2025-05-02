#include <iostream>

class Shape
{
public:
	double area;
	double volumn;
};
class Cube :public Shape
{
public:
	double side;
Cube(double side) 
{
	this->side = side;
	this->area = side * side * 6;
	this->volumn = side * side * side;
}
};
class Sphere :public Shape
{
public:
	double radius;
Sphere(double radius)
{
	this->radius = radius;
	this->area = 4 * 3.14159 * (radius * radius);
	this->volumn = (4 / 3.0) * 3.14159 * (radius * radius * radius);
}
};


int main()
{

	Cube cube(10);
	Sphere sphere(5);


	std::cout << "Area of Cube : " << cube.area << std::endl;
	std::cout << "Volume of Cube : " << cube.volumn << std::endl;
	std::cout << "Area of sphere : " << sphere.area << std::endl;
	std::cout << "Volume of sphere : " << sphere.volumn << std::endl;
	
	return 0;
}
