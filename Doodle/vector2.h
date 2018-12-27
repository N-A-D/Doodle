#pragma once

namespace doodle {

	template <class T>
	struct Vector2 final {
		Vector2() = default;
		Vector2(T x, T y) : x(x), y(y) {}
		Vector2<T>& operator+=(const Vector2<T>& other) noexcept;
		Vector2<T>& operator-=(const Vector2<T>& other) noexcept;
		Vector2<T>& operator*=(T scale) noexcept;
		Vector2<T>& operator/=(T scale);
		T x = 0, y = 0;
	};

	template <class T> Vector2<T> operator+(const Vector2<T>& l, const Vector2<T>& r) noexcept;
	template <class T> Vector2<T> operator-(const Vector2<T>& l, const Vector2<T>& r) noexcept;
	template <class T> Vector2<T> operator*(const Vector2<T>& l, T scale) noexcept;
	template <class T> Vector2<T> operator/(const Vector2<T>& l, T scale);

	using Vector2i = Vector2<int>;
	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;
}

#include "vector2.inl"