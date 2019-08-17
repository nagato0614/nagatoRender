//
// Created by 長井亨 on 2019-08-10.
//

#include "pinhole_camera.hpp"

namespace nagato {

PinholeCamera::PinholeCamera(const Vector3f &lookfrom,
														 const Vector3f &up,
														 const Vector3f &lookat,
														 Float fov,
														 int width,
														 int height)
		: Camera(lookfrom, up, lookat, fov, width, height),
			wE_(Normalize(lookfrom - lookat)),
			uE_(Normalize(Cross(up, wE_))),
			vE_(Cross(wE_, uE_)) {}

Ray PinholeCamera::GeneratePrimaryRay(int x, int y) const {
	const Float tf = std::tan(fov_ * .5);
	const Float rpx = 2. * (x + 0.5) / width_ - 1;
	const Float rpy = 2. * (y + 0.5) / height_ - 1;
	const Vector3f w = Normalize(Vector3f(aspect_ * tf * rpx, tf * rpy, -1));
	return Ray(lookfrom_, uE_ * w[0] + vE_ * w[1] + wE_ * w[2]);
}
}