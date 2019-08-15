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
			wE_(Normalize(lookat - lookfrom)),
			uE_(Normalize(Cross(wE_, up))),
			vE_(Normalize(Cross(wE_, uE_))) {}

Ray PinholeCamera::GeneratePrimaryRay(int x, int y) const {
	const double tf = std::tan(fov_ * .5);
	const double rpx = 2. * (x + 0.5) / width_ - 1;
	const double rpy = 2. * (y + 0.5) / height_ - 1;
	const auto w = Normalize(Vector3f(aspect_ * tf * rpx, tf * rpy, -1));
	return Ray(lookfrom_, uE_ * w[0] + vE_ * w[1] + wE_ * w[2]);
}
}