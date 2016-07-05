#include "SvgBasicShapeFactory.h"
#include "InvalidBasicShapeClassNameException.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

SvgBasicShape *SvgBasicShapeFactory::createCircle() {
		return new Circle();
}

SvgBasicShape *SvgBasicShapeFactory::createRect() {
		return new Rect();
}

SvgBasicShape *SvgBasicShapeFactory::createLine() {
		return new Line();
}