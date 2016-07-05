#include "Rect.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include "InvalidSvgElementPropertyValueException.h"
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

Rect::Rect(const char *fill, const char *stroke, const int strokeWidth,
		   const int x, const int y, const int width, const int height,
		   const int rx, const int ry) 
		   : SvgBasicShape(fill, stroke, strokeWidth) {
	
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setRx(rx);
	setRy(ry);
}

void Rect::setRx(unsigned int rx) {
	this->rx = rx;
}

void Rect::setRy(unsigned int ry) {
	this->ry = ry;
}

void Rect::setX(int x) {
	this->x = x;
}

void Rect::setY(int y) {
	this->y = y;
}

void Rect::setWidth(unsigned int width) {
	this->width = width;
}

void Rect::setHeight(unsigned int height) {
	this->height = height;
}

void Rect::setProperty(const char *name, int value) {
	if(strcmp(name, "rx") == 0) {
		if(value < 0) {
			throw InvalidSvgElementPropertyValueException(name);
		}
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

void Rect::translate(int x, int y) { }

const char *Rect::toXmlElement() {
	char *element = new char[MAX_SHAPE_LEN];
	element[0] = '\0';
	strcat(element, "<");
	strcat(element, Rect::simpleClassName);
	strcat(element, " ");

	/* Write properties */
	strcat(element, toPropertyValue("x=\"", x));
	strcat(element, " ");

	strcat(element, toPropertyValue("y=\"", y));
	strcat(element, " ");

	strcat(element, toPropertyValue("width=\"", width));
	strcat(element, " ");

	strcat(element, toPropertyValue("height=\"", height));
	strcat(element, " ");

	strcat(element, toPropertyValue("rx=\"", rx));
	strcat(element, " ");

	strcat(element, toPropertyValue("rx=\"", ry));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke-width=\"", getStrokeWidth()));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke=\"", getStroke()));
	strcat(element, " ");
	strcat(element, toPropertyValue("fill=\"", getFill()));
	strcat(element, "/>");
	
	return element;
}

const char *Rect::toPropertyValue(const char *nameAndEqualSign, int value) {
	if(value == 0) {
		return "";
	}

	char *propAndvalue = new char[MAX_PROP_LEN];
	propAndvalue[0] = '\0';
	strcat(propAndvalue, nameAndEqualSign);

	char *val = new char[MAX_PROP_LEN];
	val[0] = '\0';
	_itoa(value, val, 10);

	strcat(propAndvalue, val);
	strcat(propAndvalue, "\"");

	delete[] val;

	return propAndvalue;
}

const char *Rect::toPropertyValue(const char* nameAndEqualSign, const char *value) {
	if(strcmp(value, "") == 0) {
		return "";
	}

	char *propAndvalue = new char[MAX_PROP_LEN];
	propAndvalue[0] = '\0';
	strcat(propAndvalue, nameAndEqualSign);

	strcat(propAndvalue, value);
	strcat(propAndvalue, "\"");

	return propAndvalue;
}