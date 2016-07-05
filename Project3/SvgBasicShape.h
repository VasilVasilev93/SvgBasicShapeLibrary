#ifndef _SVG_BASIC_SHAPE_H
#define _SVG_BASIC_SHAPE_H

#define MAX_PROP_LEN 20
#define MAX_SHAPE_LEN 256

class SvgBasicShape {
private:
	char *fill;
	char *stroke;
	unsigned int strokeWidth;

public:
	SvgBasicShape();
	virtual ~SvgBasicShape();

	const unsigned int getStrokeWidth();
	const char *getFill();
	const char *getStroke();

	void setFill(const char *);
	void setStroke(const char *);
	void setStrokeWidth(const unsigned int);

	static bool isShape(const char *);

	virtual void setProperty(const char *, const int);
	virtual void setProperty(const char *, const char *);

	virtual void print() = 0;
	virtual void translate() = 0;
	virtual const char *toXmlElement() = 0;
	virtual const char *toPropertyValue(const char *, const int) = 0;
	virtual const char *toPropertyValue(const char *, const char *) = 0;

};
#endif