//
// Created by 長井亨 on 2019-08-10.
//

#include "pinhole_camera.hpp"

namespace nagato {

PinholeCamera::PinholeCamera(const Vector3f &eye,
                             const Vector3f &up,
                             const Vector3f &center,
                             Float fov,
                             int width,
                             int height)
    : Camera(eye, up, center, fov, width, height),
      wE_(Normalize(eye_ - center_)),
      uE_(Normalize(Cross(up_, wE_))),
      vE_(Cross(wE_, uE_)) {}

Ray PinholeCamera::GeneratePrimaryRay(int x, int y) const {
    const auto u = 2.f * static_cast<Float>(x) / width_ - 1.0f;
    const auto v = 2.f * static_cast<Float>(y) / height_ - 1.0f;
    const auto tf = std::tan(fov_ * 0.5f);
    const auto ww = Normalize(Vector3f{aspect_ * tf * u, tf * v, -1.0f});
    return Ray{eye_, uE_ * ww[0] + vE_ * ww[1] * wE_ * ww[2]};
}
}