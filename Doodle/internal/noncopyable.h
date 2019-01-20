#pragma once

namespace doodle {
	namespace internal {

		struct NonCopyable {
			NonCopyable() = default;
			~NonCopyable() = default;
			NonCopyable(const NonCopyable&) = delete;
			NonCopyable& operator=(const NonCopyable&) = delete;
		};

	}
}