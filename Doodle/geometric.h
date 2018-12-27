#pragma once

#include "vector2.h"

namespace doodle {

	// Computes the length of a vector.
	template <class T> T length(const Vector2<T>& u) noexcept;

	// Computes the length of a vector squared.
	template <class T> T length_sq(const Vector2<T>& u) noexcept;

	// Computes the distance between two vectors.
	template <class T> T distance(const Vector2<T>& u, const Vector2<T>& v) noexcept;

	// Computes the distance between two vectors squared.
	template <class T> T distance_sq(const Vector2<T>& u, const Vector2<T>& v) noexcept;

	// Computes the angle between two vectors.
	template <class T> T angle_between(const Vector2<T>& u, const Vector2<T>& v);

	// Computes the inner product of two vectors.
	template <class T> T dot(const Vector2<T>& u, const Vector2<T>& v) noexcept;
	
	// Rotates a vector clockwise by angle degrees.
	template <class T> Vector2<T> rotate(const Vector2<T>& u, T angle) noexcept;

	// Returns unit length vector u.
	template <class T> Vector2<T> normalize(const Vector2<T>& u);

	// Returns the vector u truncated to len length
	template <class T> Vector2<T> truncate(const Vector2<T>& u, T len);

	// Returns a vector perpendicular to u. 
	// Note:
	// - The returned vector is 90 degrees counterclockwise from u.
	template <class T> Vector2<T> l_perpendicular(const Vector2<T>& u);

	// Returns a vector perpendicular to u.
	// Note:
	// - The returned vector is 90 degrees clockwise from u.
	template <class T> Vector2<T> r_perpendicular(const Vector2<T>& u);

}
#include "geometric.inl"