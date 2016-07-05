#include <exception>
#include <iostream>
#include "InvalidBasicShapeClassNameException.h"
#include <Windows.h>

char * InvalidBasicShapeClassNameException::msg = "Invalid basic shape simple class name: ";

InvalidBasicShapeClassNameException::InvalidBasicShapeClassNameException(const char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	OutputDebugString(this->what());
}
const char * InvalidBasicShapeClassNameException::what () const throw () {
	char *msg = new char[strlen(name) + strlen(InvalidBasicShapeClassNameException::msg) + 1];
	msg[0] = '\0';
	strcat(msg, InvalidBasicShapeClassNameException::msg);
	strcat(msg, name);
	return msg;
}
