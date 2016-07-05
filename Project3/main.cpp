#include <iostream>
#include "SvgFile.h"

using namespace std;

int main() {

	//SvgBasicShapeReader *reader = new SvgBasicShapeReader();
	//SvgBasicShape **shapes = reader->readShapes("coursesvg.svg");
	//SvgBasicShapeWriter *writer = new SvgBasicShapeWriter();

	SvgFile *svg = new SvgFile("test.svg");

	svg->open();
	svg->within("t", 5, 5, 5, 5);
	svg->erase(0);
	svg->save();

	return 0;
}