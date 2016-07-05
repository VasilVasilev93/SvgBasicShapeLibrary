#ifndef _SVG_BASIC_SHAPE_H
#define _SVG_BASIC_SHAPE_H

class SvgBasicShape {
private:
	char *fill;
	char *stroke;
	int strokeWidth;

public:
	SvgBasicShape();
	virtual ~SvgBasicShape();

	void setFill(const char *);
	void setStroke(const char *);
	void setStrokeWidth(const int);

	virtual void setProperty(const char *, const int);
	virtual void setProperty(const char *, const char *);

	virtual void print() = 0;
	virtual void translate() = 0;

};
#endif