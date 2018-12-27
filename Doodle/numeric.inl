#include <type_traits>
#include <limits>

namespace doodle {

	template<class T>
	std::enable_if_t<std::is_floating_point_v<T>, bool> is_equal(T a, T b) noexcept
	{
		return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
	}

}
