#include "SvgBasicShapeFactory.h"
#include "InvalidBasicShapeClassNameException.h"
#include "InvalidSvgElementPropertyValueException.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

#include <iostream>

SvgBasicShape *SvgBasicShapeFactory::createShape(const char *simpleClassName) {
	if (strcmp(simpleClassName, Circle::simpleClassName) == 0) {
		return new Circle();
	}
	else if (strcmp(simpleClassName, Rect::simpleClassName) == 0) {
		return new Rect();
	}
	else if (strcmp(simpleClassName, Line::simpleClassName) == 0) {
		return new Line();
	} else {
		throw InvalidBasicShapeClassNameException(simpleClassName);
	}
}

SvgBasicShape *SvgBasicShapeFactory::createShape(const char *shapeName, const char *fill, 
					const int x, const int y, const int width,
					const int height, const int rx, const int ry,
					const char *stroke,  const int strokeWidth) {


	if(strokeWidth < 0 || width < 0 || height < 0 || rx < 0 || ry < 0) {
		std::cout << "Negative parameter value!\n";
		return 0x0;
	}

	if (strcmp(shapeName, Circle::simpleClassName) == 0) {
		//width will be radius for circle shape
		return new Circle(fill, stroke, strokeWidth, x, y, width);
	}
	else if (strcmp(shapeName, Rect::simpleClassName) == 0) {
		return new Rect(fill, stroke, strokeWidth, x, y, width, height, rx, ry);
	}
	else if (strcmp(shapeName, Line::simpleClassName) == 0) {
		//width & height will be x2 & y2 for line shape respectively
		return new Line(fill, stroke, strokeWidth, x, y, width, height);
	} else {
		throw InvalidBasicShapeClassNameException(shapeName);
	}
}