#ifndef _RECT_H_
#define _RECT_H_

#include "SvgBasicShape.h"
#include <regex>

class Rect : public SvgBasicShape{
private:
	unsigned int rx, ry, width, height;
	int x, y;
	friend class SvgBasicShapeFactory;
	Rect();

public:
	static const std::regex regex;
	static const char *simpleClassName;

	void setRx(unsigned int);
	void setRy(unsigned int);
	void setX(int);
	void setY(int);
	void setWidth(unsigned int);
	void setHeight(unsigned int);

	void setProperty(const char *, const int);

	void print();
	void translate(int, int);

	const char *toXmlElement();
	const char *toPropertyValue(const char *, const int);
	const char *toPropertyValue(const char *, const char *);

};

#endif