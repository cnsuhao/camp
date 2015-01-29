#pragma once

#include <string>
#include <cassert>

namespace camp {

struct NoType
{
};

enum Type
{
	noType,     // No type has beed defined yet
	boolType,   // Boolean type (bool)
	intType,    // Integer types (unsigned/signed char short int long)
	realType,   // Real types (float, double)
	stringType, // String types (char*, std::string)
	enumType,   // Enumerated types
	arrayType,  // Array types (std::vector, std::list, T[])
	userType,   // User-defined classes
	
};

}

