namespace doodle {

	template<class T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other) noexcept
	{
		x += other.x;
		y += other.y;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other) noexcept
	{
		x -= other.x;
		y -= other.y;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator*=(T scale) noexcept
	{
		x *= scale;
		y *= scale;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator/=(T scale)
	{
		x /= scale;
		y /= scale;
	}

	template<class T>
	Vector2<T> operator+(const Vector2<T>& l, const Vector2<T>& r) noexcept
	{
		return Vector2<T>(l) += r;
	}

	template<class T>
	Vector2<T> operator-(const Vector2<T>& l, const Vector2<T>& r) noexcept
	{
		return Vector2<T>(l) -= r;
	}

	template<class T>
	Vector2<T> operator*(const Vector2<T>& l, T scale) noexcept
	{
		return Vector2<T>(l) *= scale;
	}

	template<class T>
	Vector2<T> operator/(const Vector2<T>& l, T scale)
	{
		return Vector2<T>(l) *= scale;
	}


}
