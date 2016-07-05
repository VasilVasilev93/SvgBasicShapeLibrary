#ifndef _SVG_BASIC_SHAPE_FACTORY_H_
#define _SVG_BASIC_SHAPE_FACTORY_H_

#include "SvgBasicShape.h"

class SvgBasicShapeFactory {
public:
	static SvgBasicShape *createShape(const char *);
};

#endif