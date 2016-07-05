#include "Circle.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include "InvalidSvgElementPropertyValueException.h"
#include <string>

const std::regex Circle::regex = std::regex(".*<.*circle.*>.*");
const char *Circle::simpleClassName = "circle";

Circle::Circle() : SvgBasicShape() { 
	radius = 0;
	cx = 0;
	cy = 0;
}

void Circle::setRadius(unsigned int radius) 
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
	if(strcmp(name, "cx") == 0) {
		if(value < 0) {
			throw InvalidSvgElementPropertyValueException(name);
		}
		setCx(value);
	} 
	else if(strcmp(name, "cy") == 0) {
		setCy(value);
	} else {
		SvgBasicShape::setProperty(name, value);
	}
}

void Circle::print() { }

void Circle::translate(int x, int y) { }

const char *Circle::toXmlElement() {
	char *element = new char[MAX_SHAPE_LEN];
	element[0] = '\0';
	strcat(element, "<");
	strcat(element, Circle::simpleClassName);
	strcat(element, " ");

	/* Write properties */
	strcat(element, toPropertyValue("radius=\"", radius));
	strcat(element, " ");

	strcat(element, toPropertyValue("cx=\"", cx));
	strcat(element, " ");

	strcat(element, toPropertyValue("cy=\"", cy));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke-width=\"", getStrokeWidth()));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke=\"", getStroke()));
	strcat(element, " ");
	strcat(element, toPropertyValue("fill=\"", getFill()));
	strcat(element, "/>");
	
	return element;
}

const char *Circle::toPropertyValue(const char *nameAndEqualSign, int value) {
	if(value == 0) {
		return "";
	}

	char *propAndvalue = new char[MAX_PROP_LEN];
	propAndvalue[0] = '\0';
	strcat(propAndvalue, nameAndEqualSign);

	char *val = new char[MAX_PROP_LEN];
	val[0] = '\0';
	_itoa(value, val, 10);

	strcat(propAndvalue, _itoa(value, val, 10));
	strcat(propAndvalue, "\"");

	delete[] val;

	return propAndvalue;
}

const char *Circle::toPropertyValue(const char* nameAndEqualSign, const char *value) {
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