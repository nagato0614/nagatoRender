#include <string>
#include <iostream>
#include "image.hpp"
#include "sphere.hpp"
#include "scene.hpp"
#include "linear_intersector.hpp"
#include "pinhole_camera.hpp"
#include "rgb.hpp"

int main(int argc, char *argv[]) {
	using namespace nagato;

	//画像サイズを設定
	int width = 400;
	int height = 300;

	Scene scene(std::make_unique<LinearIntersector>());
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(-0.5, 1, 0), 1));
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(0.5, 1, 0), 1));
//    scene.AddObject(
//        std::make_shared<Sphere>(nullptr, nullptr, Vector3f(0, -901, 0), 900));

	scene.AddObject(
			std::make_shared<Sphere>(nullptr,
															 nullptr,
															 Vector3f(1e5 + 1, 40.8, 81.6),
															 1e5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr,
															 nullptr,
															 Vector3f(-1e5 + 99, 40.8, 81.6),
															 1e5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, 40.8, 1e5), 1e5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr, nullptr, Vector3f(50, 1e5, 81.6), 1e5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr,
															 nullptr,
															 Vector3f(50, -1e5 + 81.6, 81.6),
															 1e5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr, nullptr, Vector3f(27, 16.5, 47), 16.5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr, nullptr, Vector3f(73, 16.5, 78), 16.5));
	scene.AddObject(
			std::make_shared<Sphere>(nullptr,
															 nullptr,
															 Vector3f(50, 681.6 - .27, 81.6),
															 600));
	scene.Build();

	// Camera parameters
	const Vector3f eye(50, 52, 295.6);
	const Vector3f center = eye + Vector3f(0, -0.042612, -1);
	const Vector3f up(0, 1, 0);

//    const Vector3f eye(0, 1, 5);
//    const Vector3f up(0, 1, 0);
//    const Vector3f center(0, 1, 0);

	PinholeCamera camera(eye,
											 up,
											 center,
											 30,
											 width,
											 height);

	std::vector<RGB> image_array;

	for (int i = 0; i < width * height; i++) {
		const int x = i % width;
		const int y = height - 1 - i / width;
		Ray ray = camera.GeneratePrimaryRay(x, y);
		auto hit_info = scene.Intersect(ray);
		RGB q_color;
		auto tonemap = [](Float v) -> int {
			return std::min(
					std::max(int(std::pow(v, 1 / 2.2) * 255), 0), 255);
		};
		if (hit_info) {
			Vector3f normal = Normalize(hit_info->GetNormal());
			normal = (normal + 1.0) * 0.5;
			q_color.SetRGB(
					normal[0],
					normal[1],
					normal[2]);
		} else {
			q_color.SetRGB(151 / 255.0, 199 / 255.0, 199 / 255.0);
		}
		image_array.push_back(q_color);
	}
	Image image(std::move(image_array), width, height);
	image.Save("output.png");
}