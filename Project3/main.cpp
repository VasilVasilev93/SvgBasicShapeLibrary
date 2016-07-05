#include <iostream>
#include "SvgBasicShapeReader.h"
#include "SvgBasicShapeWriter.h"

using namespace std;

int main() {

	SvgBasicShapeReader *reader = new SvgBasicShapeReader();
	SvgBasicShape **shapes = reader->readShapes("coursesvg.svg");
	SvgBasicShapeWriter *writer = new SvgBasicShapeWriter();

	writer->writeShapes("test.svg", shapes, 5);

	return 0;
}