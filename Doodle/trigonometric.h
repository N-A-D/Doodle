#pragma once

#include <type_traits>

namespace doodle {

	// Converts radians to degrees.
	template <class T> std::enable_if_t<std::is_floating_point_v<T>, T> degrees(T radians) noexcept;

	// Converts degrees to radians.
	template <class T> std::enable_if_t<std::is_floating_point_v<T>, T> radians(T degrees) noexcept;

}

#include "trigonometric.inl"