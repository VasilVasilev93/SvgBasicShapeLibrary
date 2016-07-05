#ifndef NO_MORE_PROPERTIES_IN_SVG_ELEMENT_EXCEPTION_H_
#define NO_MORE_PROPERTIES_IN_SVG_ELEMENT_EXCEPTION_H_

#include <exception>

class NoMorePropertiesInSvgElementException : public std::exception {
private:
	static char *msg;
public:
	NoMorePropertiesInSvgElementException();
	const char * what () const throw ();
};

#endif