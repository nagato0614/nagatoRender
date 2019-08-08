#include <string>
#include <iostream>

#include <image.hpp>

int main() {
	using namespace nagato;
	const std::string filename = "test.png";
	const std::size_t width = 480;
	const std::size_t height = 360;

	std::vector<RGB> rgb;
	rgb.reserve(width * height);
	for (int i = 0; i < width * height; i++) {
		RGB color = {0.0f, 1.0f, 0.0f};
		rgb.push_back(color);
	}

	Image image(rgb, width, height);
	unsigned error = image.Save(filename);
	if (error)
		std::cout << "error"
							<< error
							<< " : "
							<< lodepng_error_text(error)
							<< std::endl;

	return 0;
}