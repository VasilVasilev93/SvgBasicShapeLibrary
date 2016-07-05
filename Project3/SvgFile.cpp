#include "SvgFile.h"
#include <iostream>

SvgFile::SvgFile() {
	shapes = new SvgBasicShape*[];
	index = 0;
	reader = new SvgBasicShapeReader();
	writer = new SvgBasicShapeWriter();
}

SvgFile::~SvgFile() {
	deleteShapes();
	delete reader;
	delete writer;
}

void SvgFile::create(char *, char *, char *, int, int, int, int, int, int, int) {

}

void SvgFile::erase(int index) {
	if(index < 0) {
		std::cout << "Invalid index!\n";
		return;
	}

	if(index > this->index) {
		std::cout << "Figure at index " << index << " does not exist!\n";
		return;
	} else {
		delete shapes[index];
		shiftShapes(index);
	}
}

void SvgFile::translate(int index = -1, int x, int y) {
	if(index != -1) {
		shapes[index]->translate(x, y);
	} else {
		for(int i = 0; i < this->index; i ++) {
			shapes[i]->translate(x, y);
		}
	}
}

void SvgFile::deleteShapes() {
	for(int i = 0; i < index; i ++) {
		delete shapes[i];
	}

	delete[] shapes;
	index = 0;
}

void SvgFile::shiftShapes(int shapeIndex) {
    for(int i = shapeIndex; i < index; i ++) {
        shapes[i] = shapes[i + 1];
    }
}