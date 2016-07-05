#include <exception>
#include <iostream>
#include "InvalidSvgElementSyntaxException.h"

char * InvalidSvgElementSyntaxException::msg = "Invalid svg element syntax!";

InvalidSvgElementSyntaxException::InvalidSvgElementSyntaxException() {
}
const char * InvalidSvgElementSyntaxException::what () const throw () {
	return msg;
}
