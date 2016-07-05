#ifndef _LINE_H_
#define _LINE_H_
#include <regex>

#include "SvgBasicShape.h"

class Line : public SvgBasicShape {
private:
	int x1, x2, y1, y2;

	friend class SvgBasicShapeFactory;

	Line();

	Line(const char *, const char *, const int,
         const int, const int, const int, const int);

	Line(const Line &other);
	Line &operator=(const Line &other);

public:
	static const std::regex regex;
	static const char *simpleClassName;

	void setX1(int);
	void setX2(int);
	void setY1(int);
	void setY2(int);

	void setProperty(const char *, const int);

	void print();
	void translate(int, int);

	const char *toXmlElement();
	const char *toPropertyValue(const char *, const int);
	const char *toPropertyValue(const char *, const char *);

};

#endif