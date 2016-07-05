#ifndef INVALID_SVG_BASIC_SHAPE_FIELD_EXCEPTION_H_
#define INVALID_SVG_BASIC_SHAPE_FIELD_EXCEPTION_H_

#include <exception>

class InvalidSvgBasicShapeFieldException : public std::exception {
private:
	char *fieldName;
	static char *msg;
public:
	InvalidSvgBasicShapeFieldException(const char *);
	const char * what () const throw ();
};

#endif