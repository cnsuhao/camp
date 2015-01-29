#pragma once

#include "camp/config.hpp"
#include <vector>

namespace camp {

class Value;

class CAMP_API Args
{
public:
	Args();
	Args(const Value& a0);
	Args(const Value& a0, const Value& a1);
	Args(const Value& a0, const Value& a1, const Value& a2);
	Args(const Value& a0, const Value& a1, const Value& a2, const Value& a3);
	Args(const Value& a0, const Value& a1, const Value& a2, const Value& a3, const Value& a4);

	std::size_t count() const;

	const Value& operator[](std::size_t index) const;
	Args operator+(const Value& arg) const;
	Args& operator+=(const Value& arg);

public:
	static const Args empty;

private:
	std::vector<Value> values_;
};

}

