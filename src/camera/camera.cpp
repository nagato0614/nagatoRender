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
      fov_(fov * M_PI / 180),
      aspect_((Float) width / height),
      width_(width),
      height_(height) {}
}