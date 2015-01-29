#pragma once

#include "camp/config.hpp"
#include <boost/current_function.hpp>
#include <boost/lexical_cast.hpp>
#include <exception>
#include <string>

namespace camp {

class CAMP_API Error : public std::exception
{
public:
	virtual ~Error() throw();

	virtual const char* what() const throw();
	virtual const char* where() const throw();

	// internal use only
	template <typename T>
	static T prepare(T error, const std::string& file, int line, const std::string& function);	

protected:
	Error(const std::string& message);

	// Helper function to convert anything to a string
	// This is a convenience function provided to help derived
	// classes to easily build their full message
	template <typename T>
	static std::string str(T x);

private:
	std::string message_;
	std::string location_;
};

}

#include "camp/error.inl"

#define CAMP_ERROR(error) throw camp::Error::prepare(error, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION)

