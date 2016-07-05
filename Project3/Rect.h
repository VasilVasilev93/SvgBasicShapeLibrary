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

	Rect(const char *, const char *, const int,
         const int, const int, const int, 
		 const int, const int, const int);

	Rect(const Rect &other);
	Rect &operator=(const Rect &other);

public:
	~Rect();

	static const std::regex regex;
	static const char *simpleClassName;

	void setRx(unsigned int);
	void setRy(unsigned int);
	void setX(int);
	void setY(int);
	void setWidth(unsigned int);
	void setHeight(unsigned int);

	virtual void setProperty(const char *, const int);

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