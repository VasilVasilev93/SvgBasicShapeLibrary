#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "SvgBasicShape.h"
#include <regex>

class Circle : public SvgBasicShape {
private:
	int radius, cx, cy;
	friend class SvgBasicShapeFactory;
	Circle();

public:
	static const std::regex regex;
	static const char *simpleClassName;

	void setRadius(int);
	void setCx(int);
	void setCy(int);

	void setProperty(const char *, const int);

	void print();
	void translate();

};

#endif