#include <exception>
#include <iostream>
#include "InvalidSvgBasicShapeFieldException.h"

char * InvalidSvgBasicShapeFieldException::msg = " is not a valid member of svg basic shape!";

InvalidSvgBasicShapeFieldException::InvalidSvgBasicShapeFieldException(const char *fieldName) {
	this->fieldName = new char[strlen(fieldName) + 1];
	strcpy(this->fieldName, fieldName);
}
const char * InvalidSvgBasicShapeFieldException::what () const throw () {
	char *msg = new char[strlen(fieldName) + strlen(InvalidSvgBasicShapeFieldException::msg) + 1];
	msg[0] = '\0';
	strcat(msg, fieldName);
	strcat(msg, InvalidSvgBasicShapeFieldException::msg);
	return msg;
}
