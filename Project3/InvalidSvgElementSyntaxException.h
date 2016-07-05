#ifndef INVALID_SVG_ELEMENT_SYNTAX_EXCEPTION_H_
#define INVALID_SVG_ELEMENT_SYNTAX_EXCEPTION_H_

#include <exception>

class InvalidSvgElementSyntaxException : public std::exception {
private:
	static char *msg;
public:
	InvalidSvgElementSyntaxException();
	const char * what () const throw ();
};

#endif