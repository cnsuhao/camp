#pragma once

namespace camp { namespace detail {

// Defines a "yes"/"no" type to be used in metaprograms
// To work, sizeof(TypeYes) must be different than sizeof(TypeNo)

typedef char TypeYes;
struct TypeNo { char padding[8]; };

}}

