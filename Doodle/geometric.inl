#include <cmath>
#include "vector2.h"
#include "trigonometric.h"

namespace doodle {

	template <class T> 
	T length(const Vector2<T>& u) noexcept
	{
		return std::sqrt(length_sq(u));
	}

	template <class T> 
	T length_sq(const Vector2<T>& u) noexcept
	{
		return std::pow(u.x, 2) + std::pow(u.y, 2);
	}

	template <class T> 
	T distance(const Vector2<T>& u, const Vector2<T>& v) noexcept
	{
		return std::sqrt(distance_sq(u, v));
	}

	template <class T> 
	T distance_sq(const Vector2<T>& u, const Vector2<T>& v) noexcept
	{
		return std::pow(v.x - u.x, 2) + std::pow(v.y - u.y, 2);
	}

	template <class T> 
	T angle_between(const Vector2<T>& u, const Vector2<T>& v)
	{
		return degrees(std::acos(dot(normalize(u), normalize(v))));
	}

	template <class T> 
	T dot(const Vector2<T>& u, const Vector2<T>& v) noexcept
	{
		return u.x * v.x + u.y * v.y;
	}

	template <class T> 
	Vector2<T> rotate(const Vector2<T>& u, T angle) noexcept
	{
		T rad = radians(angle);
		return Vector2<T>(u.x * std::cos(rad) - u.y * std::sin(rad), u.x * std::sin(rad) + u.y * std::cos(rad));
	}

	template <class T> 
	Vector2<T> normalize(const Vector2<T>& u)
	{
		T len = length(u);
		return Vector2<T>(u.x / len, u.y / len);
	}

	template <class T> 
	Vector2<T> truncate(const Vector2<T>& u, T len)
	{
		return normalize(u) * len;
	}

	template<class T>
	Vector2<T> l_perpendicular(const Vector2<T>& u)
	{
		return Vector2<T>(-u.y, u.x);
	}

	template<class T>
	Vector2<T> r_perpendicular(const Vector2<T>& u)
	{
		return Vector2<T>(u.y, -u.x);
	}

}