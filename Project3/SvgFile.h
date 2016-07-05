#ifndef _SVG_FILE_H
#define _SVG_FILE_H

#include "SvgBasicShape.h"
#include "SvgBasicShapeReader.h"
#include "SvgBasicShapeWriter.h"

class SvgFile {
private:
	SvgBasicShape **shapes;
	int index;
	SvgBasicShapeReader *reader;
	SvgBasicShapeWriter *writer;

	char *filePath;
	bool isOpenFake;

	void deleteShapes();
	void shiftShapes(int);

	SvgFile& operator=(const SvgFile &);
	SvgFile(const SvgFile &);

public:
	SvgFile(char *filePath);

	~SvgFile();

	void open();
	void create(const char *, const char *, const int, const int, const int,
		const int, const int, const int,
		const char *, const int);

	void erase(int);
	void translate(int, int, int index = 0);
	void print();
	void within(char *, int, int, int, int);
	void save();
	void saveAs(char *);
	void close();

	void setWriter(SvgBasicShapeWriter *);
	void setReader(SvgBasicShapeReader *);
};

#endif