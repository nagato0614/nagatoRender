#include <string>
#include <iostream>

#include "lodepng.h"

int main() {
	const std::string filename = "test.png";
	const std::size_t width = 480;
	const std::size_t height = 360;
	std::vector<std::uint8_t> image(width * height * 4);

	for (int index = 0; index < width * height * 4; index += 4) {
		image[index + 0] = 255;
		image[index + 1] = 255;
		image[index + 2] = 255;
		image[index + 3] = 255;
	}

	std::vector<std::uint8_t> png;
	unsigned error = lodepng::encode(png, image, width, height);

	if (!error)
		lodepng::save_file(png, filename);

	if (error)
		std::cout << "encoder error "
							<< error
							<< ": "
							<< lodepng_error_text(error)
							<< std::endl;
	return 0;
}