#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

std::string	to_string(int8_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(int16_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(int32_t nbr)
{
	return std::to_string(nbr);
}

std::string	to_string(float nbr)
{
	std::ostringstream	out;

	out << nbr;
	return (out.str());
}

std::string	to_string(double nbr)
{
	std::ostringstream	out;

	out << nbr;
	return (out.str());
}
