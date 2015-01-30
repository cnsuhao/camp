#include "camp/error.hpp"

namespace camp {

Error::~Error() throw()
{
}

const char* Error::what() const throw()
{
	return message_.c_str();
}

const char* Error::where() const throw()
{
	return location_.c_str();
}

Error::Error(const std::string& message) :
	message_(message),
	location_("")
{
}

}

