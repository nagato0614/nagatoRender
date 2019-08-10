//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_CAMERA_CAMERA_HPP_
#define NAGATO_RENDER_SRC_CAMERA_CAMERA_HPP_

#include "nagato.hpp"
#include "ray.hpp"

namespace nagato {
class Camera {
 public:
  virtual Ray GeneratePrimaryRay(int x, int y) const = 0;
  Camera(const Vector3f &eye,
         const Vector3f &up,
         const Vector3f &center,
         Float fov,
         int width,
         int height);

 protected:
  /**
   * カメラ中心座標
   */
  Vector3f eye_;

  /**
   * カメラのセンター位置
   */
  Vector3f center_;

  /**
   * カメラの上方向
   */
  Vector3f up_;

  /**
   * field of view
   */
  Float fov_;

  /**
   * アスペクト比
   */
  Float aspect_;

  /**
   * スクリーン幅
   */
  int width_;

  /**
   * スクリーン高さ
   */
  int height_;



};
}
#endif //NAGATO_RENDER_SRC_CAMERA_CAMERA_HPP_
