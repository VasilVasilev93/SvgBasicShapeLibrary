#include "Rect.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include <string>

const std::regex Rect::regex = std::regex(".*<.*rect.*>.*");
const char *Rect::simpleClassName = "rect";

Rect::Rect() : SvgBasicShape() { 
	rx = 0;
	ry = 0;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

void Rect::setRx(int rx) {
	this->rx = rx;
}

void Rect::setRy(int ry) {
	this->ry = ry;
}

void Rect::setX(int x) {
	this->x = x;
}

void Rect::setY(int y) {
	this->y = y;
}

void Rect::setWidth(int width) {
	this->width = width;
}

void Rect::setHeight(int height) {
	this->height = height;
}

void Rect::setProperty(const char *name, int value) {
	if(strcmp(name, "rx") == 0) {
		setRx(value);
	}
	else if(strcmp(name, "ry") == 0) {
		setRy(value);
	} 
	else if(strcmp(name, "x") == 0) {
		setX(value);
	} 
	else if(strcmp(name, "y") == 0) {
		setY(value);
	} 
	else if(strcmp(name, "width") == 0) {
		setWidth(value);
	} 
	else if(strcmp(name, "height") == 0) {
		setHeight(value);
	} else {
		SvgBasicShape::setProperty(name, value);
	}
}

void Rect::print() { }

void Rect::translate() { }
