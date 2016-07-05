#include "SvgBasicShapeWriter.h"
#include <string>
#include <fstream>

const char *SvgBasicShapeWriter::svgElement = "<?xml version=\"1.0\" standalone=\"no\"?>";

const char *SvgBasicShapeWriter::xmlElement = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";

SvgBasicShapeWriter::SvgBasicShapeWriter() {
	content = new char[MAX_XML_LEN];
	content[0] = '\0';
}

void SvgBasicShapeWriter::writeShapes(const char *filePath, SvgBasicShape **shapes, const int size) {
	delete[] content;
	content = new char[MAX_XML_LEN];
	content[0] = '\0';

	writeXmlTemplate();

	for(int i = 0; i < size; i ++) {
		strcat(content, "\t");
		addContent(shapes[i]->toXmlElement());
		strcat(content, "\n");
	}

	strcat(content, "</svg");
	writeContentToFile(filePath);
}

void SvgBasicShapeWriter::writeXmlTemplate() {
	strcat(content, SvgBasicShapeWriter::svgElement);
	strcat(content, "\n");
	strcat(content, SvgBasicShapeWriter::xmlElement);
	strcat(content, "\n");
}

void SvgBasicShapeWriter::addContent(const char *content) {
	strcat(this->content, content);
}

void SvgBasicShapeWriter::writeContentToFile(const char *filePath) {
	std::fstream stream;

	stream.open(filePath, std::ios::out, std::ios::trunc);

	if(stream) {
		//throw exc
	}

	stream.write(content, strlen(content));

	stream.close();
}
