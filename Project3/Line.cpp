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

Line::Line(const char *fill, const char *stroke, const int strokeWidth,
		   const int x1, const int x2, const int y1, const int y2) 
		   : SvgBasicShape(fill, stroke, strokeWidth) {
	
	setX1(x1);
	setX2(x2);
	setY1(y1);
	setY2(y2);
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

void Line::translate(int x, int y) { }

const char *Line::toXmlElement() {
	char *element = new char[MAX_SHAPE_LEN];
	element[0] = '\0';
	strcat(element, "<");
	strcat(element, Line::simpleClassName);
	strcat(element, " ");

	/* Write properties */
	strcat(element, toPropertyValue("x1=\"", x1));
	strcat(element, " ");

	strcat(element, toPropertyValue("x2=\"", x2));
	strcat(element, " ");

	strcat(element, toPropertyValue("y1=\"", y1));
	strcat(element, " ");

	strcat(element, toPropertyValue("y2=\"", y2));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke-width=\"", getStrokeWidth()));
	strcat(element, " ");

	strcat(element, toPropertyValue("stroke=\"", getStroke()));
	strcat(element, " ");
	strcat(element, toPropertyValue("fill=\"", getFill()));
	strcat(element, "/>");

	return element;
}

const char *Line::toPropertyValue(const char* nameAndEqualSign, int value) {
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

const char *Line::toPropertyValue(const char* nameAndEqualSign, const char *value) {
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