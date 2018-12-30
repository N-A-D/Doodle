#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../../Doodle/math.h"

namespace UnitTest
{		
	TEST_CLASS(Math)
	{
	public:
		
		TEST_METHOD(VectorLength)
		{
			doodle::Vector2f u(3, 4);
			Assert::IsTrue(doodle::length(u) == 5.f);
			Assert::IsTrue(doodle::length_sq(u) == 25.f);
		}

		TEST_METHOD(VectorDistance) {
			doodle::Vector2f u(10, 0);
			doodle::Vector2f v(5, 0);
			Assert::IsTrue(doodle::distance(u, v) == 5.f);
			Assert::IsTrue(doodle::distance_sq(u, v) == 25.f);
		}

		TEST_METHOD(VectorAngleBetwee) {
			doodle::Vector2f u(1, 0);
			doodle::Vector2f v(0, 1);
			Assert::IsTrue(doodle::is_equal(doodle::angle_between(u, v), 90.f));
		}

	};
}