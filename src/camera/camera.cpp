//
// Created by 長井亨 on 2019-08-10.
//

#include "camera.hpp"
#include "math.hpp"

namespace nagato {

Camera::Camera(const Vector3f &lookfrom,
							 const Vector3f &up,
							 const Vector3f &lookat,
							 Float fov,
							 int width,
							 int height)
		: lookfrom_(lookfrom),
			lookat_(lookat),
			up_(up),
			fov_(fov / 180. * Pi<Float>),
			aspect_(static_cast<Float>(width) / static_cast<Float>(height)),
			width_(width),
			height_(height) {}
}