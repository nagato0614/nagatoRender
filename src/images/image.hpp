//
// Created by nagato0614 on 2019-07-16.
//

#ifndef NAGATO_RENDER_SRC_IMAGES_IMAGE_HPP_
#define NAGATO_RENDER_SRC_IMAGES_IMAGE_HPP_

#include <cstdlib>
#include <cstring>
#include <cstring>
#include <rgb.hpp>
#include "lodepng.h"

namespace nagato {
class Image {
 public:

	using pixel = RGB;
	using size = std::size_t;
	using array = std::vector<pixel>;
	using const_array = const array;
	using const_reference_array = const_array &;
	using reference_array = array &;
	using self = Image;
	using reference = self &;
	using const_reference = const self &;

	Image(size w, size h);

	template<typename T>
	Image(T &&array, Image::size w, Image::size h)
			: image_(std::forward<T>(array)), width_(w), height_(h) {}


	Image(const_reference image) = default;
	Image(Image &&image) = default;

	bool Save(const std::string &filename) const noexcept;

	size GetWidth() const;
	size GetHeight() const;

 private:
	array image_;
	size width_;
	size height_;
};
}
#endif //NAGATO_RENDER_SRC_IMAGES_IMAGE_HPP_
