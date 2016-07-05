#include "SvgBasicShapeFactory.h"
#include "InvalidBasicShapeClassNameException.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

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
			throw new InvalidBasicShapeClassNameException(simpleClassName);
		}
}