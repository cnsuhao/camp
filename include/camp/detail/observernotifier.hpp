#pragma once

#include "camp/config.hpp"
#include <set>

namespace camp {
class Observer;
class Class;
class Enum;
};

namespace camp { namespace detail {

// Base class for classes that can notify global observers
class ObserverNotifier
{
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);

protected:
	ObserverNotifier();

	void notifyClassAdded(const Class& theClass);
	void notifyClassRemoved(const Class& theClass);
	void notifyEnumAdded(const Enum& theEnum);
	void notifyEnumRemoved(const Enum& theEnum);

private:
	typedef std::set<Observer*> ObserverSet;

	ObserverSet observers_;
};

}}

