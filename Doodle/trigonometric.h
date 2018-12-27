#pragma once

namespace doodle {

	// Converts radians to degrees.
	template <class T> T degrees(T radians) noexcept;

	// Converts degrees to radians.
	template <class T> T radians(T degrees) noexcept;

}

#include "trigonometric.inl"