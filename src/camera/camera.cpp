//
// Created by 長井亨 on 2019-08-10.
//

#include "camera.hpp"

namespace nagato {

Camera::Camera(const Vector3f &eye,
               const Vector3f &up,
               const Vector3f &center,
               Float fov,
               int width,
               int height)
    : eye_(eye),
      center_(center),
      up_(up),
      fov_(fov),
      aspect_(static_cast<Float>(width) / height),
      width_(width),
      height_(height) {}
}