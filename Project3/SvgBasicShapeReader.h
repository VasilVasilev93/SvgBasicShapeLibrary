#ifndef _SVG_BASIC_SHAPE_READER_H_
#define _SVG_BASIC_SHAPE_READER_H_

#include "SvgBasicShape.h"

#include <fstream>

#define INIT_SHAPES_READ_SIZE 10

class SvgBasicShapeReader {
private:
	char *shapeBuffer;
	char c;
	int index;

	SvgBasicShape **shapesRead;
	int shapesIndex;
	int shapesSize;

	int getShapeNameAndPropertiesStartIndex(char *);
	int getPropertyNameAndValueIndex(const int, char *);
	int parseInt(const char *);

	char *getPropertyValue(int &);

	void readShape();
	void deleteShapes();

	const bool isLetter(const char);
	const bool isNumber(const char *);
	const bool isNum(const char);

public:
	SvgBasicShapeReader();
	~SvgBasicShapeReader();
	SvgBasicShape **readShapes(const char *);
};
#endif