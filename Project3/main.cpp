#include <iostream>
#include "SvgFile.h"

using namespace std;

int main() {

	//SvgBasicShapeReader *reader = new SvgBasicShapeReader();
	//SvgBasicShape **shapes = reader->readShapes("coursesvg.svg");
	//SvgBasicShapeWriter *writer = new SvgBasicShapeWriter();

	SvgFile *svg = new SvgFile("coursesvg.svg");

	svg->open();
	svg->erase(0);
	svg->create("line", "green", 400, 300, 700, 100, 0, 25, "green", 5);
	svg->save();

	return 0;
}