#include "SvgBasicShape.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include <string>

SvgBasicShape::SvgBasicShape() {
	fill = new char[1];
	fill[0] = '\0';
	stroke = new char[1];
	stroke[0] = '\0';
	strokeWidth = 0;
}

SvgBasicShape::~SvgBasicShape() {
	delete[] fill;
	delete[] stroke;
}

void SvgBasicShape::setFill(const char* fill) {
	if(this->fill)
		delete[] this->fill;

	this->fill = new char[strlen(fill) + 1];
	strcpy(this->fill, fill);
}

void SvgBasicShape::setStroke(const char* stroke) {
	if(this->stroke)
		delete[] this->stroke;

	this->stroke = new char[strlen(stroke) + 1];
	strcpy(this->stroke, stroke);
}

void SvgBasicShape::setStrokeWidth(int strokeWidth) {
	this->strokeWidth = strokeWidth;
}

void SvgBasicShape::setProperty(const char *name, const int value) {
	if(strcmp(name, "stroke-width") == 0) {
		setStrokeWidth(value);
	} 
}

void SvgBasicShape::setProperty(const char *name, const char *value) {
	if(strcmp(name, "stroke") == 0) {
		setStroke(value);
	}
	else if(strcmp(name, "fill") == 0) {
		setFill(value);
	} else {
		throw InvalidSvgBasicShapeFieldException(name);
	}
}