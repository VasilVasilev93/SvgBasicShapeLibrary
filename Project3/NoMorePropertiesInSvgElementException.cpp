#include <exception>
#include <iostream>
#include "NoMorePropertiesInSvgElementException.h"

char * NoMorePropertiesInSvgElementException::msg = "Invalid basic shape simple class name: ";

NoMorePropertiesInSvgElementException::NoMorePropertiesInSvgElementException() {

}
const char * NoMorePropertiesInSvgElementException::what () const throw () {
	return msg;
}
