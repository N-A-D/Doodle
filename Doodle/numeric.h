#pragma once

#include <type_traits>

namespace doodle {

	// Checks if two floating point values are approximately equal.
	template <class T> std::enable_if_t<std::is_floating_point_v<T>, bool> is_equal(T a, T b) noexcept;

}
#include "numeric.inl"