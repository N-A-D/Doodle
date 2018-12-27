#define _USE_MATH_DEFINES
#include <cmath>

namespace doodle {

	template <class T>
	T degrees(T radians) noexcept
	{
		return radians * static_cast<T>(180) / static_cast<T>(M_PI);
	}

	template <class T>
	T radians(T degrees) noexcept
	{
		return degrees * static_cast<T>(M_PI) / static_cast<T>(180);
	}

}
