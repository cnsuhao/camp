#pragma once

#include "camp/error.hpp"
#include "camp/type.hpp"

namespace camp {

class Class;

// Error thrown when providing a metavalue whose type is incompatible with what's expected
class CAMP_API BadType : public Error
{
public:
	BadType(Type provided, Type expected);

protected:
	BadType(const std::string& message);

	static std::string typeName(Type type);
};

// Error thrown when providing a function argument which is incompatible with what the function expects
class CAMP_API BadArgument : public BadType
{
public:
	BadArgument(Type provided, Type expected, std::size_t index, const std::string& functionName);
};

// Error thrown when a declaring a meta class that already exists
class CAMP_API ClassAlreadyCreated : public Error
{
public:
	ClassAlreadyCreated(const std::string& name, const std::string& type);
};

// Error thrown when a metaclass couldn't be found (either by its name or its id)
class CAMP_API ClassNotFound : public Error
{
public:
	ClassNotFound(const std::string& name);
};

// Error thrown when trying to convert an object to a class that is not a base nor a derived
class CAMP_API ClassUnrelated : public Error
{
public:
	ClassUnrelated(const std::string& sourceClass, const std::string& requestedClass);
};

// Error thrown when a declaring a metaenum that already exists
class CAMP_API EnumAlreadyCreated : public Error
{
public:
	EnumAlreadyCreated(const std::string& name, const std::string& type);
};

// Error thrown when the value of a metaenum couldn't be found by its name
class CAMP_API EnumNameNotFound : public Error
{
public:
	EnumNameNotFound(const std::string& name, const std::string& enumName);
};

// Error thrown when a metaenum couldn't be found (either by its name or its id)
class CAMP_API EnumNotFound : public Error
{
public:
	EnumNotFound(const std::string& name);
};

// Error thrown when a value in a metaenum couldn't be found
class CAMP_API EnumValueNotFound : public Error
{
public:
	EnumValueNotFound(long value, const std::string& enumName);
};

// Error thrown when calling a function that is not callable
class CAMP_API ForbiddenCall : public Error
{
public:
	ForbiddenCall(const std::string& functionName);
};

// Error thrown when trying to read a property that is not readable
class CAMP_API ForbiddenRead : public Error
{
public:
	ForbiddenRead(const std::string& propertyName);
};

// Error thrown when trying to write a function that is not writable
class CAMP_API ForbiddenWrite : public Error
{
public:
	ForbiddenWrite(const std::string& propertyName);
};

// Error thrown when a function can't be found in a metaclass (by its name)
class CAMP_API FunctionNotFound : public Error
{
public:
	FunctionNotFound(const std::string& name, const std::string& className);
};

// Error thrown when
class CAMP_API NotEnoughArguments : public Error
{
public:
	NotEnoughArguments(const std::string& functionName, std::size_t provided, std::size_t expected);
};

// Error thrown when trying to use an empty metaobject
class CAMP_API NullObject : public Error
{
public:
	NullObject(const Class* objectClass);
};

// Error thrown when using an index which is out of bounds
class CAMP_API OutOfRange : public Error
{
public:
	OutOfRange(std::size_t index, std::size_t size);
};

// Error thrown when a property can't be found in a metaclass (by its name)
class CAMP_API PropertyNotFound : public Error
{
public:
	PropertyNotFound(const std::string& name, const std::string& className);
};

}

