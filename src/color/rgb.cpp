//
// Created by nagato0614 on 2019-07-19.
//

#include "rgb.hpp"

namespace nagato {

const Float &RGB::R() const & noexcept {
	return array_[0];
}
Float &RGB::R() & noexcept {
	return array_[0];
}
uint RGB::R255() const noexcept {
	return static_cast<uint>(clamp(R(), 0, 1.0) * 255);
}
const Float &RGB::G() const & noexcept {
	return array_[1];
}
Float &RGB::G() & noexcept {
	return array_[1];
}
uint RGB::G255() const noexcept {
	return static_cast<uint>(clamp(G(), 0, 1.0) * 255);
}
const Float &RGB::B() const & noexcept {
	return array_[2];
}
Float &RGB::B() & noexcept {
	return array_[2];
}
uint RGB::B255() const noexcept {
	return static_cast<uint>(clamp(B(), 0, 1.0) * 255);
}
}