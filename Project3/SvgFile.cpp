#include "SvgFile.h"
#include "SvgBasicShapeFactory.h"
#include <iostream>

SvgFile::SvgFile(char *filePath) {
	shapes = new SvgBasicShape*[INIT_SHAPES_READ_SIZE];
	index = 0;
	reader = new SvgBasicShapeReader();
	writer = new SvgBasicShapeWriter();

	this->filePath = new char[strlen(filePath) + 1];
	strcpy(this->filePath, filePath);
	
	isOpenFake = false;
}

SvgFile::~SvgFile() {
	deleteShapes();
	delete reader;
	delete writer;
}

void SvgFile::open() {
	isOpenFake = true;
	deleteShapes();

	shapes = reader->readShapes(filePath);
	index = reader->getShapesSize();
}

void SvgFile::close() {
	isOpenFake = false;
}

void SvgFile::create(const char *shapeName, const char *fill, 
					const int x, const int y, const int width,
					const int height, const int rx, const int ry,
					const char *stroke,  const int strokeWidth) {

	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

	SvgBasicShape *shape = SvgBasicShapeFactory::createShape(shapeName, fill, x, y, width, height, rx, ry, stroke, strokeWidth);
	if(shape != 0x0) {
		shapes[index++] = shape;
	}
}

void SvgFile::erase(int index) {
	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

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
		this->index --;
	}
}

void SvgFile::translate(int x, int y, int index) {
	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

	if(index != -1) {
		shapes[index]->translate(x, y);
	} else {
		for(int i = 0; i < this->index; i ++) {
			shapes[i]->translate(x, y);
		}
	}
}

void SvgFile::print() {
	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

	for(int i = 0; i < index; i ++) {
		shapes[i]->print();
	}
}

void SvgFile::within(char *shapeClassName, int x, int y, int w, int h) {
	//TODO
}

void SvgFile::save() {
	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

	writer->writeShapes(filePath, shapes, index);
}

void SvgFile::saveAs(char *filePath) {
	if(!isOpenFake) {
		std::cout << "File not open!";
		return;
	}

	writer->writeShapes(filePath, shapes, index);
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

void SvgFile::setWriter(SvgBasicShapeWriter *writer) {
	this->writer = writer;
}

void SvgFile::setReader(SvgBasicShapeReader *reader) {
	this->reader = reader;
}