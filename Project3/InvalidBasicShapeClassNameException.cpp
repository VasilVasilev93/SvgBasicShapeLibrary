#include <exception>
#include <iostream>
#include "InvalidBasicShapeClassNameException.h"

char * InvalidBasicShapeClassNameException::msg = "Invalid basic shape simple class name: ";

InvalidBasicShapeClassNameException::InvalidBasicShapeClassNameException(const char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
const char * InvalidBasicShapeClassNameException::what () const throw () {
	char *msg = new char[strlen(name) + strlen(InvalidBasicShapeClassNameException::msg) + 1];
	strcat(msg, name);
	strcat(msg, InvalidBasicShapeClassNameException::msg);
	return msg;
}
