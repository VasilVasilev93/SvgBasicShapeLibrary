#ifndef _SVG_BASIC_SHAPE_READER_H_
#define _SVG_BASIC_SHAPE_READER_H_

#include "SvgBasicShape.h"

#include <fstream>

#define MAX_SHAPE_LEN 256
#define MAX_PROP_LEN 20
#define INIT_SHAPES_READ_SIZE 10

class SvgBasicShapeReader {
private:
	char *shapeBuffer;
	char c;
	int index;

	SvgBasicShape **shapesRead;
	int shapesIndex;
	int shapesSize;

	int getPropertiesStartIndex();
	int getPropertyNameAndValueIndex(const int, char *);
	int parseInt(const char *);

	char *getPropertyValue(int &);

	void readShape();
	void deleteShapes();
	
	const bool isShape();
	const bool isCircle();
	const bool isRect();
	const bool isLine();
	const bool isLetter(const char);
	const bool isNumber(const char *);
	const bool isNum(const char);
	

public:
	SvgBasicShapeReader();
	~SvgBasicShapeReader();
	SvgBasicShape **readShapes(const char *);
};
#endif