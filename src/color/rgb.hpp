//
// Created by nagato0614 on 2019-07-19.
//

#ifndef NAGATO_RENDER_SRC_COLOR_RGB_HPP_
#define NAGATO_RENDER_SRC_COLOR_RGB_HPP_

#include "color_base.hpp"

namespace nagato {
class RGB : public ColorBase<3> {
 public:
	RGB(Float f = 0.0) : ColorBase(f) {}
	RGB(const std::initializer_list<Float> f) : ColorBase(f) {}

	RGB(const ColorBase &color_base) : ColorBase(color_base) {}

	RGB(ColorBase &&color_base) : ColorBase(std::move(color_base)) {}

	const Float &R() const & noexcept;

	Float &R() & noexcept;

	uint R255() const noexcept;

	const Float &G() const & noexcept;

	Float &G() & noexcept;

	uint G255() const noexcept;

	const Float &B() const & noexcept;

	Float &B() & noexcept;

	uint B255() const noexcept;

	void SetRGB(Float r, Float g, Float b) noexcept;


 private:
};
}

#endif //NAGATO_RENDER_SRC_COLOR_RGB_HPP_
