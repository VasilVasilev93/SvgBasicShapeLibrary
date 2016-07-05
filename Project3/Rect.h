#ifndef _RECT_H_
#define _RECT_H_

#include "SvgBasicShape.h"
#include <regex>

class Rect : public SvgBasicShape{
private:
	int rx, ry, x, y, width, height;
	friend class SvgBasicShapeFactory;
	Rect();

public:
	static const std::regex regex;
	static const char *simpleClassName;

	void setRx(int);
	void setRy(int);
	void setX(int);
	void setY(int);
	void setWidth(int);
	void setHeight(int);

	void setProperty(const char *, const int);

	void print();
	void translate();
};

#endif