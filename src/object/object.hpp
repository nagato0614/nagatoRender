//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_
#define NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_

#include <vector>
#include <optional>
#include "nagato.hpp"
#include "hit_info.hpp"
#include "material.hpp"
#include "light.hpp"
#include "ray.hpp"
#include "hit_info.hpp"

namespace nagato {
class HitInfo;
class Object {
 public:
  Object(const std::shared_ptr<Material> &material, const std::shared_ptr<Light> &light);
  virtual std::optional<HitInfo> Intersect(const Ray &ray) = 0;
  const std::shared_ptr<Material> &GetMaterial() const;
  const std::shared_ptr<Light> &GetLight() const;
 protected:
  std::shared_ptr<Material> material_;
  std::shared_ptr<Light> light_;
};
}
#endif //NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_
