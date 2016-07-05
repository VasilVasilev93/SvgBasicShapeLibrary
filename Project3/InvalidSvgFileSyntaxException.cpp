#include <exception>
#include <iostream>
#include "InvalidSvgFileSyntaxException.h"

char * InvalidSvgFileSyntaxException::msg = "Invalid svg file syntax!";

const char * InvalidSvgFileSyntaxException::what () const throw () {
	return InvalidSvgFileSyntaxException::msg;
}
