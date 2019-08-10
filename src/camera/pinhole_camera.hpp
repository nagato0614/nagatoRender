//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_CAMERA_PINHOLE_CAMERA_HPP_
#define NAGATO_RENDER_SRC_CAMERA_PINHOLE_CAMERA_HPP_

#include "nagato.hpp"
#include "camera.hpp"

namespace nagato {
class PinholeCamera : public Camera {
 public:

  Ray GeneratePrimaryRay(int x, int y) const override;
 private:
 public:
  PinholeCamera(const Vector3f &eye,
                const Vector3f &up,
                const Vector3f &center,
                Float fov,
                int width,
                int height);

 private:
  Vector3f wE_;
  Vector3f uE_;
  Vector3f vE_;
};
}
#endif //NAGATO_RENDER_SRC_CAMERA_PINHOLE_CAMERA_HPP_
