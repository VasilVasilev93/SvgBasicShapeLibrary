#ifndef _INVALID_SVG_FILE_SYNTAX_EXCEPTION_H_
#define _INVALID_SVG_FILE_SYNTAX_EXCEPTION_H_

#include <exception>

class InvalidSvgFileSyntaxException : public std::exception {
private:
	static char *msg;
public:
	const char * what () const throw ();
};

#endif