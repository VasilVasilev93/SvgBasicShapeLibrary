#ifndef _SVG_BASIC_SHAPE_WRITER_H_
#define _SVG_BASIC_SHAPE_WRITER_H_

#include "SvgBasicShape.h"

#define MAX_XML_LEN 2049

class SvgBasicShapeWriter {
private:
	static const char *xmlElement;
	static const char *svgElement;

	char *content;

	void writeXmlTemplate();
	void addContent(const char *);
	void writeContentToFile(const char *);
public:
	SvgBasicShapeWriter();
	SvgBasicShapeWriter(const SvgBasicShapeWriter &);
	SvgBasicShapeWriter &operator=(const SvgBasicShapeWriter &);
	~SvgBasicShapeWriter();

	void writeShapes(const char *, SvgBasicShape **, const int size);
};

#endif