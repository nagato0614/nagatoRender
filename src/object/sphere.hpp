//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_OBJECT_SPHERE_HPP_
#define NAGATO_RENDER_SRC_OBJECT_SPHERE_HPP_

#include "nagato.hpp"
#include "object.hpp"
#include "hit_info.hpp"

namespace nagato {
class HitInfo;

class Sphere : public Object {
 public:
  Sphere(const std::shared_ptr<Material> &material,
         const std::shared_ptr<Light> &light,
         const Vector3f &point,
         Float radius);
  std::optional<HitInfo> Intersect(const Ray &ray) override;
 private:
  Vector3f point_;
  Float radius_;

};
}
#endif //NAGATO_RENDER_SRC_OBJECT_SPHERE_HPP_
