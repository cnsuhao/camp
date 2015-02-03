#pragma once

namespace camp { namespace detail {

// Utility class used at compile-time to which type to use to avoid copying the returnd object
// If T is a reference or a pointer type, ReturnType<T>::type is T
// Otherwise, ReturnType<T>::Type is T&
template <typename T> struct ReturnType     {typedef T& Type;};
template <typename T> struct ReturnType<T&> {typedef T& Type;};
template <typename T> struct ReturnType<T*> {typedef T* Type;};

}}
