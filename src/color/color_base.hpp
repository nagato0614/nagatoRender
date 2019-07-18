//
// Created by nagato0614 on 2019-07-19.
//

#ifndef NAGATO_RENDER_SRC_COLOR_COLOR_BASE_HPP_
#define NAGATO_RENDER_SRC_COLOR_COLOR_BASE_HPP_

#include <cstdlib>
#include <core/nagato.hpp>
#include <vector.hpp>

namespace nagato {
template<Size element>
class ColorBase {

	using __self = ColorBase<element>;
	using _reference = __self &;
	using _const_reference = const __self &&;

 public:
	template<class... Args>
	constexpr explicit ColorBase(Args &&... args) noexcept
			: array_(std::forward<decltype(args)>(args)...) {
	}

	constexpr ColorBase(_const_reference c) noexcept
			: array_(c.array_) {}

	constexpr Float &operator[](Size index)
	& noexcept {
		return array_[index];
	}

	constexpr const Float &operator[](Size index)
	const & noexcept {
		return array_[index];
	}

	constexpr const Float &operator[](Size index)
	const && noexcept {
		return array_[index];
	}

	constexpr ColorBase<element> &operator=(_const_reference v)
	noexcept {
		array_ = v.array_;
		return *this;
	}

	constexpr __self &operator+=(_const_reference v) noexcept {
		return array_ + v.array_;
	}

	template<typename T>
	constexpr __self &operator+=(const T &v) noexcept {
		return array_ + v;
	}

	constexpr __self &operator-=(_const_reference v) noexcept {
		return array_ - v.array_;
	}

	template<typename T>
	constexpr __self &operator-=(const T &v) noexcept {
		return array_ - v;
	}

	constexpr __self &operator*=(_const_reference v) noexcept {
		return array_ * v.array_;
	}

	template<typename T>
	constexpr __self &operator*=(const T &v) noexcept {
		return array_ * v;
	}

	constexpr __self &operator/=(_const_reference v) noexcept {
		return array_ / v.array_;
	}

	template<typename T>
	constexpr __self &operator/=(const T &v) noexcept {
		return array_ / v;
	}

 protected:
	Vector<Float, element> array_;
};

// -----------------------------------------------------------------------------


template<Size element>
constexpr ColorBase<element>
operator+(
		const ColorBase<element> &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv.array_ + rhv.array_);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator+(
		const ColorBase<element> &lhv,
		const T &rhv
) {
	return ColorBase(lhv.array_ + rhv);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator+(
		const T &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv + rhv.array_);
}

// -----------------------------------------------------------------------------

template<Size element>
constexpr ColorBase<element>
operator-(
		const ColorBase<element> &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv.array_ - rhv.array_);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator-(
		const ColorBase<element> &lhv,
		const T &rhv
) {
	return ColorBase(lhv.array_ - rhv);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator-(
		const T &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv - rhv.array_);
}

// -----------------------------------------------------------------------------

template<Size element>
constexpr ColorBase<element>
operator*(
		const ColorBase<element> &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv.array_ * rhv.array_);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator*(
		const ColorBase<element> &lhv,
		const T &rhv
) {
	return ColorBase(lhv.array_ * rhv);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator*(
		const T &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv * rhv.array_);
}
// -----------------------------------------------------------------------------

template<Size element>
constexpr ColorBase<element>
operator/(
		const ColorBase<element> &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv.array_ / rhv.array_);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator/(
		const ColorBase<element> &lhv,
		const T &rhv
) {
	return ColorBase(lhv.array_ / rhv);
}

template<Size element, typename T>
constexpr ColorBase<element>
operator/(
		const T &lhv,
		const ColorBase<element> &rhv
) {
	return ColorBase(lhv / rhv.array_);
}

// -----------------------------------------------------------------------------

}

#endif //NAGATO_RENDER_SRC_COLOR_COLOR_BASE_HPP_
