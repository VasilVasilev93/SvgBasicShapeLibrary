#include "Circle.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include <string>

const std::regex Circle::regex = std::regex(".*<.*circle.*>.*");
const char *Circle::simpleClassName = "circle";

Circle::Circle() : SvgBasicShape() { 
	radius = 0;
	cx = 0;
	cy = 0;
}

void Circle::setRadius(int radius) 
{
	this->radius = radius;
}

void Circle::setCx(int cx) {
	this->cx = cx;
}

void Circle::setCy(int cy) {
	this->cy = cy;
}

void Circle::setProperty(const char *name, const int value) {
	if(strcmp(name, "radius") == 0 || strcmp(name, "r") == 0) {
		setRadius(value);
	}
	else if(strcmp(name, "cx") == 0) {
		setCx(value);
	} 
	else if(strcmp(name, "cy") == 0) {
		setCy(value);
	} else {
		SvgBasicShape::setProperty(name, value);
	}
}

void Circle::print() { }

void Circle::translate() { }