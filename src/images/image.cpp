//
// Created by nagato0614 on 2019-07-16.
//

#include "image.hpp"

namespace nagato {

Image::size Image::GetWidth() const {
	return width_;
}
Image::size Image::GetHeight() const {
	return height_;
}
Image::Image(Image::size w, Image::size h)
		: width_(w), height_(h) {
	image_.reserve(w * h);
}


bool Image::Save(const std::string &filename) const noexcept {
	std::vector<std::uint8_t> image(4 * width_ * height_);
	for (int i = 0; i < width_ * height_ * 4; i += 4) {
		size index = i / 4;
		image[i + 0] = image_[index].R255();
		image[i + 1] = image_[index].G255();
		image[i + 2] = image_[index].B255();
		image[i + 3] = 255;
	}

	std::vector<std::uint8_t> png;
	unsigned error = lodepng::encode(png, image, width_, height_);
	if (error)
		return error;

	return lodepng::save_file(png, filename);
}
}