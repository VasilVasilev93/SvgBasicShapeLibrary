#include <iostream>
#include "SvgBasicShapeReader.h"

using namespace std;

int main() {

	SvgBasicShapeReader *p = new SvgBasicShapeReader();
	SvgBasicShape **shapes = p->readShapes("coursesvg.svg");
	return 0;
}