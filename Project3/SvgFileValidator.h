#ifndef _SVG_FILE_VALIDATOR_H_
#define _SVG_FILE_VALIDATOR_H_

#include <regex>
#include <fstream>

class SvgFileValidator {
private:

public:
	static const std::regex svgElementRegex;
	static void validate(std::fstream &stream);
};
#endif