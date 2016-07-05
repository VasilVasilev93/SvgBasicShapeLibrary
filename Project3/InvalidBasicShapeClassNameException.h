#ifndef INVALID_SVG_BASIC_CLASS_NAME_EXCEPTION_H_
#define INVALID_SVG_BASIC_CLASS_NAME_EXCEPTION_H_

#include <exception>

class InvalidBasicShapeClassNameException : public std::exception {
private:
	char *name;
	static char *msg;
public:
	InvalidBasicShapeClassNameException(const char *);
	const char * what () const throw ();
};

#endif