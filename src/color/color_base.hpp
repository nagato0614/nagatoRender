//
// Created by nagato0614 on 2019-07-19.
//

#ifndef NAGATO_RENDER_SRC_COLOR_COLOR_BASE_HPP_
#define NAGATO_RENDER_SRC_COLOR_COLOR_BASE_HPP_

#include <cstdlib>
#include <nagato.hpp>
#include <vector.hpp>

namespace nagato {
template<Size element>
class ColorBase {

	using self = ColorBase<element>;
	using reference = self &;
	using const_refernce = const self &&;

 public:
	constexpr explicit ColorBase(Float f = 0.0) noexcept
			: array_(f) {}

	constexpr ColorBase(const std::initializer_list<Float> &init) noexcept
			: array_(init) {}

	constexpr ColorBase(const ColorBase &color_base)
			: array_(color_base.array_) {}

	constexpr ColorBase(ColorBase &&color_base) noexcept
			: array_(std::move(color_base.array_)) {}

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

	constexpr ColorBase<element> &operator=(const_refernce v)
	noexcept {
		array_ = v.array_;
		return *this;
	}

	constexpr self &operator+=(const_refernce v) noexcept {
		return array_ + v.array_;
	}

	template<typename T>
	constexpr self &operator+=(const T &v) noexcept {
		return array_ + v;
	}

	constexpr self &operator-=(const_refernce v) noexcept {
		return array_ - v.array_;
	}

	template<typename T>
	constexpr self &operator-=(const T &v) noexcept {
		return array_ - v;
	}

	constexpr self &operator*=(const_refernce v) noexcept {
		return array_ * v.array_;
	}

	template<typename T>
	constexpr self &operator*=(const T &v) noexcept {
		return array_ * v;
	}

	constexpr self &operator/=(const_refernce v) noexcept {
		return array_ / v.array_;
	}

	template<typename T>
	constexpr self &operator/=(const T &v) noexcept {
		return array_ / v;
	}

	template<typename From, typename To>
	constexpr self Clamp(From from, To to) noexcept {
		return array_.Clamp(from, to);
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
