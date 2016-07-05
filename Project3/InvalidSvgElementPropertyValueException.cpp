#include "InvalidSvgElementPropertyValueException.h"
#include <iostream>

char * InvalidSvgElementPropertyValueException::msg = " does not allow negative values!";

InvalidSvgElementPropertyValueException::InvalidSvgElementPropertyValueException(const char *fieldName) {
	this->fieldName = new char[strlen(fieldName) + 1];
	strcpy(this->fieldName, fieldName);
}

const char * InvalidSvgElementPropertyValueException::what () const throw () {
	char *msg = new char[strlen(fieldName) + strlen(InvalidSvgElementPropertyValueException::msg) + 1];
	msg[0] = '\0';
	strcat(msg, fieldName);
	strcat(msg, InvalidSvgElementPropertyValueException::msg);
	return msg;
}
