#pragma once

#include "camp/detail/objecttraits.hpp"
#include "camp/detail/yesnotype.hpp"
#include <boost/utility/enable_if.hpp>

namespace camp { namespace detail {

// Utility class to get the CAMP identifier associated to a C++ type
// A compiler error will be triggered if requesting the identifier of a type
// which hasn't been registered with the CAMP_TYPE macro.
template <typename T>
struct StaticTypeId
{
	static const char* get(bool = true)
	{
		// If you get this error, it means you didn't register
		// your class/enum T with the CAMP_TYPE macro.
		return T::CAMP_TYPE_NOT_REGISTERED();
	}

	enum
	{
		defined = false,
		copyable = true,
	};
};

// Utility class to check if a type has a CAMP id (i.e. has been registered with CAMP_TYPE)
template <typename T>
struct HasStaticTypeId
{
	enum
	{
		value = StaticTypeId<typename RawType<T>::Type>::defined,
	};
};

// Return the static type identifier of a C++ type T
template <typename T> const char* staticTypeId()         { return StaticTypeId<typename RawType<T>::Type>::get(); }
template <typename T> const char* staticTypeId(const T&) { return StaticTypeId<typename RawType<T>::Type>::get(); }

// Utility class used to check at compile-time if a type T implements the CAMP RTTI
template <typename T>
struct HasCampRtti
{
	template <typename U, const char* (U::*)() const> struct TestForMbmer {};
	template <typename U> static TypeYes check(TestForMbmer<U, &U::campClassId>*);
	template <typename U> static TypeNo  check(...);

	enum { value = sizeof(check<typename RawType<T>::Type>(0)) == sizeof(TypeYes) };
};

// Utility class to get the CAMP identifier associated to a C++ object
// If the object has a dynamic type witch is different from its static type
// (i.e. Base* obj = new Derived), and both classes use the
// CAMP_RTTI macro, then the system is able to return the identifier of
// the true dynamic type of the object.
template <typename T, typename E = void>
struct DynamicTypeId
{
	typedef ObjectTraits<const T&> Traits;

	static const char* get(const T& object)
	{
		typename Traits::PointerType pointer = Traits::getPointer(object);
		return pointer ? pointer->campClassId() : staticTypeId<T>();
	}
};

// Specialization of DyanmicTypeId for types that don't implement CAMP RTTI
template <typename T>
struct DynamicTypeId<T, typename boost::disable_if<HasCampRtti<T>>::type>
{
	static const char* get(const T&)
	{
		return staticTypeId<T>();
	}
};

// Return the dynamic type identifier of a C++ object
template <typename T> const char* typeId()                { return staticTypeId<T>(); }
template <typename T> const char* typeId(const T& object) { return DynamicTypeId<T>::get(object); }

// Utility class to get a valid CAMP identifier from a C++ type even if the type wasn't declared
template <typename T, typename E = void>
struct SafeTypeId
{
	static const char* get()
	{
		return typeId<T>();
	}

	static const char* get(const T& object)
	{
		return typeId(object);
	}
};

// Specialization of SafeTypeId for types that have no CAMP id
template <typename T>
struct SafeTypeId<T, typename boost::disable_if<HasStaticTypeId<T>>::type>
{
	static const char* get()
	{
		return "";
	}

	static const char* get(const T&)
	{
		return "";
	}
};

// Specialization of SafeTypeId needed because "const void&" is not a valid expression
template <>
struct SafeTypeId<void>
{
	static const char* get() { return ""; }
};

// Return the dyanmic type identifier of a C++ object even if it doesn't exist (i.e. it can't fail)
template <typename T> const char* safeTypeId()                { return SafeTypeId<typename RawType<T>::Type>::get(); }
template <typename T> const char* safeTypeId(const T& object) { return SafeTypeId<T>::get(object); } 

}}

