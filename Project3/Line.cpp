#include "Line.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include <string>

const std::regex Line::regex = std::regex(".*<.*line.*>.*");
const char *Line::simpleClassName = "line";

Line::Line() : SvgBasicShape() {
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

void Line::setX1(int x1) {
	this->x1 = x1;
}

void Line::setX2(int x2) {
	this->x2 = x2;
}

void Line::setY1(int y1) {
	this->y1 = y1;
}

void Line::setY2(int y2) {
	this->y2 = y2;
}

void Line::setProperty(const char *name, const int value) {
	if(strcmp(name, "x1") == 0) {
		setX1(value);
	}
	else if(strcmp(name, "x2") == 0) {
		setX2(value);
	} 
	else if(strcmp(name, "y1") == 0) {
		setY1(value);
	}
	else if(strcmp(name, "y2") == 0) {
		setY2(value);
	} else {
		SvgBasicShape::setProperty(name, value);
	}
}

void Line::print() { }

void Line::translate() { }