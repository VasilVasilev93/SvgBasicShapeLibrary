#include "SvgBasicShapeReader.h"
#include "SvgBasicShapeFactory.h"
#include "SvgFileValidator.h"
#include "InvalidBasicShapeClassNameException.h"
#include "NoMorePropertiesInSvgElementException.h"
#include "InvalidSvgBasicShapeFieldException.h"
#include "InvalidSvgElementSyntaxException.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

#include <regex>

SvgBasicShapeReader::SvgBasicShapeReader() {
	shapeBuffer = new char [MAX_SHAPE_LEN]; 
	shapesRead = new SvgBasicShape *[INIT_SHAPES_READ_SIZE];
}

SvgBasicShapeReader::~SvgBasicShapeReader() {
	delete[] shapeBuffer;
	deleteShapes();
}

SvgBasicShape **SvgBasicShapeReader::readShapes(const char *file) {
	deleteShapes();
	shapesRead = new SvgBasicShape *[INIT_SHAPES_READ_SIZE];
	std::fstream stream;
	stream.open("coursesvg.svg", std::ios::in);
	while(stream.getline(shapeBuffer, MAX_SHAPE_LEN)) {
		index = strlen(shapeBuffer);
		if(isShape()) {
			readShape();
		}

		delete[] shapeBuffer;
		shapeBuffer = new char[MAX_SHAPE_LEN];
		index = 0;
	}
	stream.clear();
	stream.close();

	delete[] shapeBuffer;

	return shapesRead;
}

const bool SvgBasicShapeReader::isShape() {
	return isCircle() || isRect() || isLine();
}

const bool SvgBasicShapeReader::isCircle() {
	return std::regex_match(shapeBuffer, Circle::regex);

}
const bool SvgBasicShapeReader::isRect() {
	return std::regex_match(shapeBuffer, Rect::regex);
}
const bool SvgBasicShapeReader::isLine() {
	return std::regex_match(shapeBuffer, Line::regex);
}


void SvgBasicShapeReader::readShape() {
	SvgBasicShape *shape = 0x0;
	if(isCircle()) {
		shape = SvgBasicShapeFactory::createCircle();
	}
	else if(isRect()) {
		shape = SvgBasicShapeFactory::createRect();
	}
	else if(isLine()) {
		shape = SvgBasicShapeFactory::createLine();
	}

	int propertiesIndex = getPropertiesStartIndex();
	char *propertyName;
	char *propertyValue;
	while(true) {
		try {
			propertyName = new char[MAX_PROP_LEN];

			int propertyValueIndex = getPropertyNameAndValueIndex(propertiesIndex, propertyName);
			propertyValue = getPropertyValue(propertyValueIndex);
			propertiesIndex = propertyValueIndex;

			isNumber(propertyValue) ? shape->setProperty(propertyName, parseInt(propertyValue))
										: shape->setProperty(propertyName, propertyValue);
			delete[] propertyName;
			delete[] propertyValue;

		} catch(NoMorePropertiesInSvgElementException &) {
			break;
		}
	}

	shapesRead[shapesIndex++] = shape;
}

int SvgBasicShapeReader::getPropertyNameAndValueIndex(const int index, char *propName) {
	char *name = new char[MAX_PROP_LEN];
	int nameIndex = 0;
	bool isReadingPoperty = false;

	for(int i = index; i < this->index; i ++) {
		c = shapeBuffer[i];
		if(c == '>') {
			throw NoMorePropertiesInSvgElementException();
		}
		if(isLetter(c) || isNum(c)) {
			name[nameIndex ++] = c;
			if(!isReadingPoperty)
				isReadingPoperty = true;
		}

		else if(isReadingPoperty) {
			if(c == '=') {
				name[nameIndex] = '\0';
				strcpy(propName, name);
				delete[] name;
				return i;
			}
		}
	}

	throw InvalidSvgElementSyntaxException();
}

//fix
char *SvgBasicShapeReader::getPropertyValue(int &index) {
	char *value = new char[MAX_PROP_LEN];
	int valueIndex = 0;
	bool isReadingValue = false;

	for(; index < this->index; index ++) {
		c = shapeBuffer[index];

		if(c == '\"' && !isReadingValue) {
			isReadingValue = true;
		}
		else if(isLetter(c) || isNum(c)) {
			value[valueIndex ++] = c;
		}

		else if(isReadingValue && c == '\"') {
			value[valueIndex] = '\0';
			return value;
		}
	}

	throw InvalidSvgElementSyntaxException();
}

void SvgBasicShapeReader::deleteShapes() {
	for(int i = 0; i < shapesIndex; i ++) {
		delete shapesRead[i];
	}

	delete[] shapesRead;
	shapesIndex = 0;
}

int SvgBasicShapeReader::getPropertiesStartIndex() {
	char *shapeName = new char[MAX_PROP_LEN];
	int shapeNameIndex = 0;
	bool isReadingPropName = false;

	for(int i = 0; i < index; i ++) {
		c = shapeBuffer[i];

		if(isLetter(c)) {
				shapeName[shapeNameIndex++] = c;
				isReadingPropName = true;
		}

		else if(isReadingPropName && c == ' ') {
			shapeName[shapeNameIndex] = '\0';
			if( (strcmp(shapeName, Circle::simpleClassName) == 0) ||
			    (strcmp(shapeName, Rect::simpleClassName) == 0) ||
			    (strcmp(shapeName, Line::simpleClassName) == 0)) {
					delete[] shapeName;
					return i;
			}

			else throw InvalidBasicShapeClassNameException(shapeName);
		}
	}
}

const bool SvgBasicShapeReader::isLetter(const char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-');
}

const bool SvgBasicShapeReader::isNum(const char c) {
	return (c >= '0' && c <= '9');
}

const bool SvgBasicShapeReader::isNumber(const char *value) {
	int len = strlen(value);
	for(int i = 0; i < len; i ++) {
		if(!isNum(value[i])){
			return false;
		}
	}

	return true;
}

int SvgBasicShapeReader::parseInt(const char *value) {
	return atoi(value);
}