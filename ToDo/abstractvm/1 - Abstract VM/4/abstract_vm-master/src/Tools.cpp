#include "../include/Tools.hpp"

myexception::myexception(const char *msg) : msg(msg) {
	std::cerr << msg << std::endl;
}

const char      *myexception::what() const throw(){
	return msg;
}

template<typename Out>
void    split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}


std::vector<std::string>    line_split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}