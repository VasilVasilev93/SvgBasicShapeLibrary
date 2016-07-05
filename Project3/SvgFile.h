#ifndef _SVG_FILE_H
#define _SVG_FILE_H

#include "SvgBasicShape.h"
#include "SvgBasicShapeReader.h"
#include "SvgBasicShapeWriter.h"

class SvgFile {
private:
	SvgBasicShape **shapes;
	SvgBasicShapeReader *reader;
	SvgBasicShapeWriter *writer;

public:
	SvgFile();

	void create(char *, char *, char *, int, int, int, int, int, int, int);
	void erase(int);
	void translate(int, int, int);
	void translate(int, int);
	void print();
	void within(char *, int, int, int, int);
	void save();
	void saveAs(char *);
	void open(char *);
	void close();

	void setWriter(SvgBasicShapeWriter *);
	void setReader(SvgBasicShapeReader *);
};

#endif