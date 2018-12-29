#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI
#include <type_traits>

namespace doodle {

	template <class T>
	std::enable_if_t<std::is_floating_point_v<T>, T> degrees(T radians) noexcept
	{
		return radians * static_cast<T>(180) / static_cast<T>(M_PI);
	}

	template <class T>
	std::enable_if_t<std::is_floating_point_v<T>, T> radians(T degrees) noexcept
	{
		return degrees * static_cast<T>(M_PI) / static_cast<T>(180);
	}

}
