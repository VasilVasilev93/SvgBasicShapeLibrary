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
	Circle(const char *, const char *, const int,
           const int, const int, const int);

	Circle(const Circle &other);
	Circle &operator=(const Circle &other);

public:
	~Circle();
	static const std::regex regex;
	static const char *simpleClassName;

	void setRadius(unsigned int);
	void setCx(int);
	void setCy(int);

	void setProperty(const char *, const int);

	virtual void print();
	virtual void translate(int, int);

	virtual const char *toXmlElement();
	virtual const char *toPropertyValue(const char *, const int);
	virtual const char *toPropertyValue(const char *, const char *);

	virtual int getX();
	virtual int getY();
	virtual int getWidth();
	virtual int getHeight();

};

#endif