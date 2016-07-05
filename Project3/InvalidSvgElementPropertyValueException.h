#ifndef _INVALID_SVG_ELEMENT_PROPERTY_VALUE_EXCEPTION_H_
#define _INVALID_SVG_ELEMENT_PROPERTY_VALUE_EXCEPTION_H_

#include <exception>

class InvalidSvgElementPropertyValueException : public std::exception {
private:
	char *fieldName;
	static char *msg;
public:
	InvalidSvgElementPropertyValueException(const char *);
	const char * what () const throw ();
};

#endif