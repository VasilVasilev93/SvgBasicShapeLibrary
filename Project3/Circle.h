#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "SvgBasicShape.h"
#include <regex>

class Circle : public SvgBasicShape {
private:
	int cx, cy;
	unsigned int radius;
	friend class SvgBasicShapeFactory;
	Circle();

public:
	static const std::regex regex;
	static const char *simpleClassName;

	void setRadius(unsigned int);
	void setCx(int);
	void setCy(int);

	void setProperty(const char *, const int);

	void print();
	void translate();

	const char *toXmlElement();
	const char *toPropertyValue(const char *, const int);
	const char *toPropertyValue(const char *, const char *);

};

#endif